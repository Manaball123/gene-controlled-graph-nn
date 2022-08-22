export module Neuron;
import <vector>;
export
namespace NN
{


	/*
	namespace CType
	{
		enum CType
		{
			Simple,
			Hardwired,

		};
	}
	*/
	class Neuron
	{
	public:
		Neuron();
		~Neuron();

		bool PushCache();
		double currentActivation;
		double nextActivation;




	};


	class Connection
	{
		
	public:
		int src;
		int dst;
		double weight;
		
		//Reference to neurons table in thet network
		std::vector<Neuron*>* neurons_ref;

		//Get neuron from table
		Neuron* GetN(uint index)
		{
			return neurons_ref[index]
		}
		
		void Propagate()
		{
			this->dst->nextActivation += this->src->currentActivation * this->weight;
		};
		
		virtual void BackProp();
	};


	class SimpleC : public Connection
	{
	public:
		//Weight for backpropagation
		double backWeight;
		void BackProp()
		{


			//some placeholder ish thing here, there could be a proper algorithm but im doing this for now
			//dy/dx lmao

			//also im thinking of caching src activation * weight idk
			this->weight += this->backWeight * (this->dst->nextActivation / (this->src->currentActivation * this->weight));
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