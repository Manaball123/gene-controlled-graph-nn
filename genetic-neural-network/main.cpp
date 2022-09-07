// genetic-neural-network.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "network/network-defs.hpp"








class TestClass
{
    int a, b, c;

public:
    TestClass(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    //~TestClass();

    int Method()
    {
        return a + b + c;
    }
    

};
using namespace NN;
int main()
{
    TestClass c = TestClass(1, 2, 3);

    std::cout << c.Method() << std::endl;


    
}

