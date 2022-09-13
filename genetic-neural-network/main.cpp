// genetic-neural-network.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "network/network.hpp"
#include "network/network_defs.hpp"
#include "utils/network_visualization.hpp"




using namespace NN;
using namespace NNVis;



void memleakTest()
{
    std::cout << "hi\n";
    Network nets[100];
    for (int i = 0; i < 100; i++)
    {
        Genes* genes = new Genes();
        nets[i].Init(genes);
        delete genes;



    };


   // std::cin.get();
}

int main()
{

    Genes* genes = new Genes();

    Network net1 = Network(genes);
    
    NetworkVisualizer v1(&net1);
    net1.neurons[0]->currentActivation = 1.0;
    //net1.neurons[32]->currentActivation = 1.0;
    bool activate = 0;

    memleakTest();


    while (1)
    {

        //std::cin.get();
        if (activate)
        {
            activate = 0;
            net1.neurons[0]->currentActivation = 1.0;
            net1.neurons[2]->currentActivation = 1.0;
            net1.neurons[4]->currentActivation = 1.0;
        }
        else
        {
            activate = 1;
        }

        //net1.neurons[0]->currentActivation = 1.0;
        
        v1.Render();
        net1.Propagate();


    }
    
}

