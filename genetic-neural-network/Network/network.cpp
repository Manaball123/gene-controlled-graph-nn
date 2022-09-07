

#include "network.hpp"


//Network 


using namespace NN;



void Neuron::PushCache()
{
	currentActivation = nextActivation;
}

//Connection base class

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