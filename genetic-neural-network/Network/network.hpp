#pragma once


#include "network-defs.hpp"
#include "genes.hpp"
#include <vector>


namespace NN
{
	
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
	class Neuron
	{
	public:
		Neuron();
		~Neuron();

		bool PushCache();
		ADType currentActivation;
		ADType nextActivation;




	};


	class Connection
	{

	public:
		uint src;
		uint dst;
		WDType weight;

		//Reference to neurons table in thet network
		std::vector<Neuron*>* neurons_ref;

		//Get neuron from table
		Neuron* GetN(uint index)
		{
			return this->neurons_ref->at(index);
		};
		Neuron* GetSrc()
		{
			return GetN(this->src);
		};

		Neuron* GetDst()
		{
			return GetN(this->dst);
		};

		void Propagate()
		{
			this->GetDst()->nextActivation += this->GetSrc()->currentActivation * this->weight;
		};

		virtual void BackProp();
	};


	class SimpleC : public Connection
	{
	public:
		//Weight for backpropagation
		WDType backWeight;
		void BackProp()
		{


			//some placeholder ish thing here, there could be a proper algorithm but im doing this for now
			//dy/dx lmao

			//also im thinking of caching src activation * weight idk
			this->weight += this->backWeight * (this->GetDst()->nextActivation / (this->GetSrc()->currentActivation * this->weight));
			return;
		}
	};


	class HardwiredC : public Connection
	{
	public:
		//no backprop cuz its hardwired...
		void BackProp()
		{

			return;
		}
	};
}