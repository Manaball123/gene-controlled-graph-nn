// genetic-neural-network.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "network/network.hpp"
#include "network/network-defs.hpp"




using namespace NN;


int main()
{
    Genes* genes = new Genes();

    Network net1 = Network(genes);

    net1.neurons[0]->currentActivation = 1.0;
    net1.Propagate();
    
}

