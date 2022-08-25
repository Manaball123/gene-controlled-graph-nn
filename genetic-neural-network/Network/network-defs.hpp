




#ifndef __NETWORK_DEFS__

#define __NETWORK__DEFS__


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
		(((dtype)rand() / (dtype)RAND_MAX) * (max - min)) + min;
	}
}
#endif // !__NETWORK_ENUMS__
