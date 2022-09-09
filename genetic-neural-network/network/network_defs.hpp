




#ifndef __NETWORK_DEFS__

#define __NETWORK_DEFS__


#include <stdlib.h>
#include <math.h>

//Gene definitions
#define GENES_SIZE 16384

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


//Other network defs
#define NEURONS_SIZE 256
#define CONNECTIONS_SIZE GENES_SIZE

namespace NN
{
	namespace CType
	{
		enum CType
		{
			Simple,
			Hardwired,
		};
		const unsigned int Num = 2;
	};

	//Data type used for activation
	using activation_t = double;
	using weight_t = double;

	
	template<class dtype> 
	dtype RandVal(dtype min, dtype max)
	{
		return (((dtype)rand() / (dtype)RAND_MAX) * (max - min)) + min;
	}

	inline activation_t Signal(activation_t activation)
	{
		return tanh(activation);
	}
	inline activation_t SignalDerivative(activation_t activation)
	{
		return 1.0 - pow(tanh(activation), 2.0);
	}
	inline weight_t RandW(weight_t min, weight_t max)
	{
		return RandVal<weight_t>(min, max);
	}

	inline bool DoMutation(double probability)
	{
		if (probability >= RandVal<double>(0.0, 1.0))
		{
			return true;
		}
		return false;
	}
		
	
}
#endif 
