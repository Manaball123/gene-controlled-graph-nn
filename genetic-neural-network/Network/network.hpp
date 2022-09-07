#pragma once


#include "network-defs.hpp"
#include "genes.hpp"
#include <vector>


namespace NN
{

	class Neuron
	{
	public:
		Neuron();
		~Neuron();

		void PushCache();
		activation_t currentActivation;
		activation_t nextActivation;


	};


	class Connection
	{

	public:
		uint src;
		uint dst;
		weight_t weight;

		//Reference to neurons table in thet network
		std::vector<Neuron*>* neurons_ref;

		//Get neuron from table
		Neuron* GetN(uint index);
		Neuron* GetSrc();

		Neuron* GetDst();

		void Propagate();

		virtual void BackProp();
	};


	class Network
	{
	public:

		std::vector<Connection*> connections;
		std::vector<Neuron*> neurons;
		Network();


		Network(Genes*);

		~Network();


		void Propagate()
		{
			for (int i = 0; i < this->connections.size(); i++)
			{

			}
		}

		void BackPropagate()
		{

		}
	};

	
	class SimpleC : public Connection
	{
	public:
		//Weight for backpropagation
		weight_t backWeight;
		void BackProp();
	};


	class HardwiredC : public Connection
	{
	public:
		void BackProp();

	};
}