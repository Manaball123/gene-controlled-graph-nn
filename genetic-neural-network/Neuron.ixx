export module Neuron;


namespace NN
{

	namespace CType
	{
		enum CType
		{
			Simple,
			Hardwired,

		};
	}
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
		Neuron* src;
		Neuron* dst;
		
		
		double weight;
		void Propagate()
		{
			this->dst->nextActivation += this->src->currentActivation * this->weight;
		};
		virtual void BackProp();
	};


	class SimpleC : public Connection
	{
	public:
		
	};
}