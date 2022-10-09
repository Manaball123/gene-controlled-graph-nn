

#include "network.hpp"



//Network 


using namespace NN;


//Dont use this ever
Network::Network()
{

	//InitializeVectors();

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
	Connection* temp_ptr;

	for (uint i = 0; i < CONNECTIONS_SIZE; i++)
	{
		Connection* newc_ptr;
		//Create a connection for each gene
		Gene* currentGene = &genes->genes[i];
		void* rawMemPtr = connectionsMemPool.New(CSIZE_TABLE[currentGene->mode]);
		
		switch (currentGene->mode) {
		case CType::Simple:
			newc_ptr = reinterpret_cast<SimpleC*>(rawMemPtr);
			temp_ptr = new SimpleC(currentGene);
			
			
			break;
		case CType::Hardwired:
			newc_ptr = reinterpret_cast<HardwiredC*>(rawMemPtr);
			temp_ptr = new HardwiredC(currentGene);
			
			
			break;
		default:
			//This should never happen
			newc_ptr = nullptr;
			temp_ptr = nullptr;
		}
		//temp_ptr = nullptr;

		memcpy(newc_ptr, temp_ptr, CSIZE_TABLE[currentGene->mode]);
		connections[i] = newc_ptr;
		delete temp_ptr;
		
		
	}


}


void Network::ResetActivations()
{
	for (auto it : neurons)
	{
		it->currentActivation = 0.0;
		it->nextActivation = 0.0;
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


