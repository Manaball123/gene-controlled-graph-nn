#pragma once

#include "neuron.hpp"
#include "genes.hpp"
#include "../utils/typedefs.hpp"
#include <vector>


namespace NN
{

	class Connection
	{

	public:
		uint src;
		uint dst;
		weight_t weight;

		//Reference to neurons table in thet network
		std::vector<Neuron*>* neurons_ref;

		//Get neuron from table
		Connection(Gene* gene, std::vector<Neuron*>* neurons_ref);
		Neuron* GetN(uint index);
		Neuron* GetSrc();

		Neuron* GetDst();

		void Propagate();

		virtual void BackProp();
	};



	class SimpleC : public Connection
	{
	public:
		//Weight for backpropagation

		weight_t backWeight;

		SimpleC(Gene* gene, std::vector<Neuron*>* neuronsRef);
		void BackProp();
	};


	class HardwiredC : public Connection
	{
	public:
		void BackProp();

		HardwiredC(Gene* gene, std::vector<Neuron*>* neuronsRef);

	};
}