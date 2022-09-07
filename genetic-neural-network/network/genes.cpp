#include "genes.hpp"


using namespace NN;



void Gene::RandMode()
{
	//only 2 modes currently
	this->mode = rand() % 2;
}

void Gene::RandSrc()
{
	this->src = (rand() % (NEURONS_NUM - INPUT_NEURONS)) + INPUT_NEURONS;
}

void Gene::RandDst()
{
	this->dst = rand() % (NEURONS_NUM - OUTPUT_NEURONS);
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