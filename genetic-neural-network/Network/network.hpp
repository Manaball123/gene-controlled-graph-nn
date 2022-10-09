#pragma once


#include "network_defs.hpp"
#include "connection.hpp"
#include "genes.hpp"
#include "neuron.hpp"
#include <vector>
#include "../utils/nn_pool_allocator.hpp"



namespace NN
{

	class Network
	{
	public:
		
		std::vector<Connection*> connections;
		std::vector<Neuron*> neurons;

		MemPoolAllocator neuronsMemPool;
		MemPoolAllocator connectionsMemPool;


		//call on network creation
		//Resizes the vectors and initializes neurons
		//Note that the connections still have to be constructed
		inline void InitializeVectors()
		{
			connections.resize(CONNECTIONS_SIZE);
			neurons.resize(NEURONS_SIZE);

		}
		
		Network();
		~Network();
		


		Network(Genes* genes);
		void Init(Genes* genes);


		void ResetActivations();

		//~Network();

		//Does a forward and backwards propagation for all connections and pushes the cached activations
		void Propagate();

		//void BackPropagate();
	};



}