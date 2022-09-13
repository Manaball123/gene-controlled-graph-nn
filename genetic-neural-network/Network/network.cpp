

#include "network.hpp"



//Network 


using namespace NN;


//Dont use this ever
Network::Network()
{

	InitializeVectors();

};

void Network::Init(Genes* genes)
{
	//count size of connections

	connectionsMemPool.Reallocate(genes->GetSize());
	neuronsMemPool.Reallocate(NEURONS_SIZE * sizeof(Neuron));

	InitializeVectors();
	//expand vectors first
	
	//Create neurons
	for (uint i = 0; i < NEURONS_SIZE; i++)
	{
		neurons[i] = static_cast<Neuron*>(neuronsMemPool.New(sizeof(Neuron), 1));
		*neurons[i] = Neuron();

	}
	//Create connections
	for (uint i = 0; i < CONNECTIONS_SIZE; i++)
	{
		Connection* newc_ptr;
		//Create a connection for each gene
		Gene* currentGene = &genes->genes[i];
		Connection* rawMemPtr = static_cast<Connection*>(connectionsMemPool.New(CSIZE_TABLE[currentGene->mode]));
		switch (currentGene->mode) {
		case CType::Simple:
			newc_ptr = static_cast<SimpleC*>(rawMemPtr);
			
			break;
		case CType::Hardwired:
			newc_ptr = static_cast<HardwiredC*>(rawMemPtr);
			break;
		default:
			newc_ptr = nullptr;
		}
		connections[i] = newc_ptr;
		
		
	}
}

Network::Network(Genes* genes)
{
	Init(genes);
}

//Deallocate objects in vectors
Network::~Network()
{
	//Mempools are automatically deallocated
	
}

void Network::Propagate()
{

	//Forward propagate
	for (auto it : connections)
	{
		it->Propagate(&neurons);
	}
	//Back propagate
	for (auto it : connections)
	{
		it->BackProp(&neurons);
	}
	//Push neurons cached activation
	for (auto it : neurons)
	{
		it->PushCache();
	}
}


