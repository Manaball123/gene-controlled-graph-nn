

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
		//Create a connection for each gene
		Gene* currentGene = &genes->genes[i];
		switch (currentGene->mode) {
		case CType::Simple:
			SimpleC(currentGene, &neurons);
			break;
		case CType::Hardwired:
			HardwiredC(currentGene, &neurons);
			break;
		}
		
		
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


