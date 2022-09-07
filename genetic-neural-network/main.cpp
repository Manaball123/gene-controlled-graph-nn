// genetic-neural-network.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "network/network.hpp"
#include "network/network-defs.hpp"




using namespace NN;


int main()
{
    Genes* genes = new Genes();
    genes->genes[0] = Gene(1, 0, 63, 1.0, 1.0);
    genes->genes[1] = Gene(1, 62, 1, 1.0, 1.0);
    genes->genes[2] = Gene(1, 1, 62, 1.0, 1.0);
    genes->genes[3] = Gene(1, 61, 0, 1.0, 1.0);

    Network net1 = Network(genes);

    net1.neurons[0]->currentActivation = 1.0;
    net1.Propagate();
    
}

