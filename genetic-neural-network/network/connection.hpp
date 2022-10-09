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
		//std::vector<Neuron*>* neurons_ref;
		//-8 bytes per connection which brings the grand total to 16/24! yipee :D
		//+8 bytes for stack frame doe :(

		//Get neuron from table
		Connection(Gene* gene);
		Neuron* GetN(std::vector<Neuron*>* neurons_ref, uint index);
		Neuron* GetSrc(std::vector<Neuron*>* neurons_ref);

		Neuron* GetDst(std::vector<Neuron*>* neurons_ref);

		void Propagate(std::vector<Neuron*>* neurons_ref);

		virtual void BackProp(std::vector<Neuron*>* neurons_ref);

		//Connection& operator=(Connection& c);
		virtual size_t GetSize();
	};



	class SimpleC : public Connection
	{
	public:
		//Weight for backpropagation

		weight_t backWeight;

		SimpleC(Gene* gene);
		void BackProp(std::vector<Neuron*>* neurons_ref);
		size_t GetSize();
	};


	class HardwiredC : public Connection
	{
	public:
		void BackProp(std::vector<Neuron*>* neurons_ref);

		HardwiredC(Gene* gene);
		size_t GetSize();
		//HardwiredC();

	};



	//Connection sizes
	const size_t CSIZE_TABLE[]
	{

		sizeof(SimpleC),
		sizeof(HardwiredC)

	};

}