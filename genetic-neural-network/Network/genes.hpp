#pragma once

#include <cstdlib>;
#include <random>;
#include "../Utils/typedefs.hpp"
#include "network-defs.hpp"

#define GENES_SIZE 1024
#define NEURONS_NUM 64
#define INPUT_NEURONS 8
#define OUTPUT_NEURONS 5

#define INIT_WEIGHT_OFFSET 1.0
#define MUTATE_WEIGHT_OFFSET 0.2
//probability of mode randomization
#define PROB_MODE_RAND 1/10000
//probability of address randomization
#define PROB_ADDR_RAND 1/1000
//probability of weight randomization
#define PROB_WGT_RAND 1/10

//min multiplier
//0.25-> currentweight * 0.75 ~ 1.25
#define MIN_MULT_RANGE 0.1
#define MAX_MULT_RANGE 2


namespace NN 
{


	
	//A single gene
	class Gene
	{
		void RandMode();

		void RandSrc();

		void RandDst();

		void RandWeight(WDType offset, WDType base = 0.0);

		void RandBackWeight(WDType offset, WDType base = 0.0);


	public:
		int mode;
		uint src;
		uint dst;
		ADType weight;
		WDType backWeight;



		Gene();

		void Mutate();

	};
	
	class Genes
	{
		//Genes header, do not mutate
		//Total number of neurons
		static const uint neuronN;
		//specify input/output neurons range here
		static const uint inRng = INPUT_NEURONS;
		static const uint outRng = OUTPUT_NEURONS;
		//Example:
		//ir = 2
		//or = 3
		//total = 10
		//ir range: 0-1
		//or range: 7-9

		Gene genes[GENES_SIZE];
		

	};

}