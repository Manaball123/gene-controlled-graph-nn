// genetic-neural-network.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <crtdbg.h>
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


   //std::cin.get();
}

int main()
{

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


    Genes* genes = new Genes();
    _crtBreakAlloc = 155;

    Network net1 = Network(genes);
    
    //NetworkVisualizer v1(&net1);
    //net1.neurons[0]->currentActivation = 1.0;
    //net1.neurons[32]->currentActivation = 1.0;
    bool activate = 0;

    for (uint i = 0; i < 3; i++)
    {
        std::cout << i << std::endl;
        memleakTest();
    }
    //net1.~Network();
    //delete genes;
    _CrtDumpMemoryLeaks();

   
    
}

