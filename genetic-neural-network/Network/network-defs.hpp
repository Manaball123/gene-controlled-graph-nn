




#ifndef __NETWORK_DEFS__

#define __NETWORK_DEFS__


#include <stdlib.h>

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
