#include "neuron.hpp"



using namespace NN;

//idk what to put in here
Neuron::Neuron()
{
	currentActivation = 0;
	nextActivation = 0;
}

void Neuron::PushCache()
{
	currentActivation = nextActivation;
}