#include "neuron.hpp"



using namespace NN;

//idk what to put in here
Neuron::Neuron()
{
	currentActivation = 0.0;
	nextActivation = 0.0;
}

void Neuron::PushCache()
{
	currentActivation = Signal(nextActivation);
	nextActivation = 0.0;
}