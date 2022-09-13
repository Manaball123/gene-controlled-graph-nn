#include "genes.hpp"
#include "connection.hpp"


using namespace NN;



void Gene::RandMode()
{
	//only 2 modes currently
	this->mode = rand() % CTYPE_COUNT;
}

void Gene::RandSrc()
{
	//dont use output neurons as source
	this->src = rand() % (NEURONS_SIZE - OUTPUT_NEURONS);
}

void Gene::RandDst()
{
	//dont use input neurons as dst
	this->dst = (rand() % (NEURONS_SIZE - INPUT_NEURONS)) + INPUT_NEURONS;
}

void Gene::RandWeight(weight_t offset, weight_t base)
{
	this->weight = RandW(base - offset, base + offset);
}

void Gene::RandBackWeight(weight_t offset, weight_t base)
{
	this->backWeight = RandW(base - offset, base + offset);
}


Gene::Gene()
{
	this->RandMode();
	this->RandSrc();
	this->RandDst();
	this->RandWeight(INIT_WEIGHT_OFFSET);
	this->RandBackWeight(INIT_WEIGHT_OFFSET);


}

Gene::Gene(int mode, uint src, uint dst, weight_t weight, weight_t backWeight)
{
	this->mode = mode;
	this->src = src;
	this->dst = dst;
	this->weight = weight;
	this->backWeight = backWeight;
}


void Gene::Mutate()
{
	if (DoMutation(PROB_MODE_RAND))
	{
		this->RandMode();

	}

	if (DoMutation(PROB_ADDR_RAND))
	{
		this->RandSrc();
	}

	if (DoMutation(PROB_ADDR_RAND))
	{
		this->RandDst();
	}

	if (DoMutation(PROB_WGT_RAND))
	{
		this->RandWeight(MUTATE_WEIGHT_OFFSET, this->weight);
	}

	if (DoMutation(PROB_WGT_RAND))
	{
		this->RandWeight(MUTATE_WEIGHT_OFFSET, this->backWeight);

	}

}

//Initialize vector on creation
Genes::Genes()
{
	connectionTypes.resize(CTYPE_COUNT);
}
//randomly initialize genes
void Genes::Init()
{
	for (uint i = 0; i < GENES_SIZE; i++)
	{
		genes[i] = Gene();

	}
}

void Genes::CountTypes()
{
	for (uint i = 0; i < GENES_SIZE; i++)
	{
		genes[i].mode = 0;

	}
}

void Genes::GetCTable(std::vector<size_t>* sizeTable)
{
	
	sizeTable->resize(CTYPE_COUNT);

	for (uint i = 0; i < GENES_SIZE; i++)
	{
		sizeTable->at(this->genes[i].mode)++;
	}
		
}

size_t Genes::GetSize()
{
	std::vector<size_t> sTable;
	size_t counter = 0;
	GetCTable(&sTable);
	for (size_t i = 0; i < sTable.size(); i++)
	{
		counter += (sTable[i] * CSIZE_TABLE[i]);
	}
	return counter;
}

void Genes::Mutate()
{
	for (uint i = 0; i < GENES_SIZE; i++)
	{
		genes[i].Mutate();
	}
}