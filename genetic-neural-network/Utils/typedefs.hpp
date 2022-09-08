

#ifndef __CONST_TYPE_DEFENITIONS__

#define __CONST_TYPE_DEFENITIONS__



//idk why this is a thing but here it is lmao
using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;

using uchar = unsigned char;

using ubyte = unsigned __int8;
using uint8 = unsigned __int8;

using ushort = unsigned __int16;
using uint16 = unsigned __int16;

using uint = unsigned __int32;
//Use this to avoid ambiguity :nerd:
using uint32 = unsigned __int32;


//ik long isnt actually 64 bits in length but whatever, doesnt make sense for long to be same as int anyway
using ulong = unsigned __int64;
using uint64 = unsigned __int64;



namespace ERR
{
	enum
	{
		//Generic errors
		SUCCESS,
		MALLOC_FAIL,
		STREAM_CLOSED,


	};
}




#endif