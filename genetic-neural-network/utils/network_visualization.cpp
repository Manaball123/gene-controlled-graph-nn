#include "network_visualization.hpp"
//#include "../network/neuron.hpp"

using namespace NNVis;


NetworkVisualizer::NetworkVisualizer(NN::Network* network_ptr)
{
	this->network_ptr = network_ptr;
	renderer = CLIRenderer::CRenderer(8, 8);
}

void NetworkVisualizer::Render()
{
	std::vector <NN::Neuron*>* neurons_ref = &network_ptr->neurons;

	for (uint32 i = 0; i < neurons_ref->size(); i++)
	{
		renderer.AddPixel(GetCharFromActivation(neurons_ref->operator[](i)->currentActivation), i);
	}
	renderer.Draw();
}


char NetworkVisualizer::GetCharFromActivation(NN::activation_t activation)
{
	NN::activation_t threshold = 0.95;
	NN::activation_t decrements = 0.2;

	for (uint32 i = 9; i > 0; i--) 
	{
		if (activation >= threshold)
		{
			return charset[i];
		}
		
		threshold -= decrements;

	}
	return charset[0];
}