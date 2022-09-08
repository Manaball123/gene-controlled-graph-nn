// genetic-neural-network.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "network/network.hpp"
#include "network/network_defs.hpp"
#include "utils/network_visualization.hpp"




using namespace NN;
using namespace NNVis;


int main()
{
    Genes* genes = new Genes();

    Network net1 = Network(genes);
    
    NetworkVisualizer v1(&net1);
    net1.neurons[0]->currentActivation = 1.0;
    net1.neurons[32]->currentActivation = 1.0;
    
    while (1)
    {
        std::cin.get();
        net1.neurons[0]->currentActivation = 1.0;
        //net1.neurons[32]->currentActivation = 1.0;
        v1.Render();
        net1.Propagate();


    }
    
}

