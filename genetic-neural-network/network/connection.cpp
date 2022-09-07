#include "connection.hpp"
#include "genes.hpp"



using namespace NN;
//Connection base class

Connection::Connection(Gene* gene, std::vector<Neuron*>* neuronsRef)
{
	weight = gene->weight;
	src = gene->src;
	dst = gene->dst;
	neurons_ref = neuronsRef;

}

void Connection::BackProp()
{
	return;
}

//Get neuron from table
Neuron* Connection::GetN(uint index)
{
	return neurons_ref->at(index);
};
Neuron* Connection::GetSrc()
{
	return GetN(src);
};

Neuron* Connection::GetDst()
{
	return GetN(dst);
};

void Connection::Propagate()
{
	GetDst()->nextActivation += GetSrc()->currentActivation * weight;
};

SimpleC::SimpleC(Gene* gene, std::vector<Neuron*>* neuronsRef) : Connection(gene, neuronsRef)
{
	backWeight = gene->backWeight;
}

HardwiredC::HardwiredC(Gene* gene, std::vector<Neuron*>* neuronsRef) : Connection(gene, neuronsRef)
{
	//nothing lol
}

//Connection derivative classes
void SimpleC::BackProp()
{
	//some placeholder ish thing here, there could be a proper algorithm but im doing this for now
	//dy/dx lmao

	//also im thinking of caching src activation * weight idk
	weight += backWeight * (GetDst()->nextActivation / (GetSrc()->currentActivation * weight));
	return;
}

void HardwiredC::BackProp()
{
	return;
}