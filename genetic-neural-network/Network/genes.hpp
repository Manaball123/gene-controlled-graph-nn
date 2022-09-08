#pragma once

#include <cstdlib>;
#include <random>;
#include "../Utils/typedefs.hpp"
#include "network_defs.hpp"



namespace NN 
{


	
	//A single gene
	class Gene
	{
		void RandMode();

		void RandSrc();

		void RandDst();

		void RandWeight(weight_t offset, weight_t base = 0.0);

		void RandBackWeight(weight_t offset, weight_t base = 0.0);


	public:
		int mode;
		uint src;
		uint dst;
		weight_t weight;
		weight_t backWeight;



		Gene();

		Gene(int mode, uint src, uint dst, weight_t weight, weight_t backWeight);

		void Mutate();

	};
	
	class Genes
	{
	public:
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

		void Init();
		void Mutate();
		Gene genes[GENES_SIZE];
		

	};

}