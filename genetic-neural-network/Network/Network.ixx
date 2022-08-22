export module Network;

import Neuron;
import <vector>;

namespace NN
{
	export 
	class Network
	{
		Network();
		~Network();
		std::vector<Connection*> connections;


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