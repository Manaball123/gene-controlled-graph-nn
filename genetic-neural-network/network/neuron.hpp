#pragma once


#include "network-defs.hpp"
namespace NN
{
	class Neuron
	{
	public:
		Neuron();

		//~Neuron();

		void PushCache();
		activation_t currentActivation;
		activation_t nextActivation;


	};



}