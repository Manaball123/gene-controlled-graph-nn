#include "connection.hpp"
#include "genes.hpp"



using namespace NN;
//Connection base class

Connection::Connection(Gene* gene)
{
	weight = gene->weight;
	src = gene->src;
	dst = gene->dst;
	//neurons_ref = neuronsRef;

}

void Connection::BackProp(std::vector<Neuron*>* neurons_ref)
{
	return;
}

//Get neuron from table
Neuron* Connection::GetN(std::vector<Neuron*>* neurons_ref, uint index)
{
	return neurons_ref->at(index);
};
Neuron* Connection::GetSrc(std::vector<Neuron*>* neurons_ref)
{
	return GetN(neurons_ref, src);
};

Neuron* Connection::GetDst(std::vector<Neuron*>* neurons_ref)
{
	return GetN(neurons_ref, dst);
};

void Connection::Propagate(std::vector<Neuron*>* neurons_ref)
{
	GetDst(neurons_ref)->nextActivation += GetSrc(neurons_ref)->currentActivation * weight;
};
/*
Connection& Connection::operator=(Connection& c) 
{
	memcpy(this, &c, c.GetSize());
	return *this;
}
*/

size_t Connection::GetSize()
{
	return sizeof(Connection);
}
SimpleC::SimpleC(Gene* gene) : Connection(gene)
{
	backWeight = gene->backWeight;
}

size_t SimpleC::GetSize()
{
	return sizeof(SimpleC);
}

HardwiredC::HardwiredC(Gene* gene) : Connection(gene)
{
	//nothing lol
}

//Connection derivative classes
void SimpleC::BackProp(std::vector<Neuron*>* neurons_ref)
{
	//some placeholder ish thing here, there could be a proper algorithm but im doing this for now
	//dy/dx lmao

	//also im thinking of caching src activation * weight idk
	if (GetSrc(neurons_ref)->currentActivation == 0)
	{
		return;
	}
	//derivative of resultant dst activation = dsig(sum)
	//derivative of sum = src activation * weight
	weight -= backWeight * ( 
		//dy (this is actually the intermediate du but whatever
		SignalDerivative(GetDst(neurons_ref)->nextActivation)
		//divided by dx
		/ (GetSrc(neurons_ref)->currentActivation * weight));
	return;
}


size_t HardwiredC::GetSize()
{
	return sizeof(HardwiredC);
}
void HardwiredC::BackProp(std::vector<Neuron*>* neurons_ref)
{
	return;
}