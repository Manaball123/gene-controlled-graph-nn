export module Network;

import Neuron;
import Genes;
import <vector>;


namespace NN
{
	export
	class Network
	{
	public:

		std::vector<Connection*> connections;
		std::vector<Neuron*> neurons;
		Network()
		{

		};

		Network(Genes*)
		{

		}
		~Network()
		{

		};

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
}