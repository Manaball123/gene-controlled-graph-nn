

#include "network.hpp"



//Network 


using namespace NN;


Network::Network()
{

}

Network::Network(Genes* genes)
{
	InitializeVectors();
	//expand vectors first
	
	for (int i = 0; i < CONNECTIONS_SIZE; i++)
	{
		Connection* newc_ptr;
		//Create a connection for each gene
		Gene* currentGene = &genes->genes[i];
		switch (currentGene->mode) {
		case CType::Simple:
			newc_ptr = new SimpleC(currentGene, &neurons);
			break;
		case CType::Hardwired:
			newc_ptr = new HardwiredC(currentGene, &neurons);
			break;
		default:
			newc_ptr = nullptr;
		}
		connections[i] = newc_ptr;
		
		
	}
}


//Deallocate objects in vectors
Network::~Network()
{
	for (auto it : neurons)
	{
		delete it;
	}
	for (auto it : connections)
	{
		delete it;
	}
}

void Network::Propagate()
{

	//Forward propagate
	for (auto it : connections)
	{
		it->Propagate();
	}
	//Back propagate
	for (auto it : connections)
	{
		it->BackProp();
	}
	//Push neurons cached activation
	for (auto it : neurons)
	{
		it->PushCache();
	}
}


