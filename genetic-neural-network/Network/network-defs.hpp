




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
	using ADType = double;
	using WDType = double;

	
	template<class dtype> 
	dtype RandVal(dtype min, dtype max)
	{
		return (((dtype)rand() / (dtype)RAND_MAX) * (max - min)) + min;
	}


	inline WDType RandW(WDType min, WDType max)
	{
		return RandVal<WDType>(min, max);
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
