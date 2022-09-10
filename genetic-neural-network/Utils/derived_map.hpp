#pragma once
//#include <vector>
#include <unordered_map>
#include "typedefs.hpp"



//TODO:
//make custom allocator with fixed buffer size
//as netwoprk size can be known when creating with a gene, an allocator can be made to allocate that much memory
//pros: no writing the bullshit below
//cons: sitll wasted a bit of mem cuz of pointers

namespace DerivedMap
{
	//this serves to mitigate memory allocation overhead by using an array of objects for the same derived class
	template <class BaseClass>
	class DMapUnordered
	{

		std::unordered_map<const char*, BaseClass*> arrayPointers;
		std::unordered_map<const char*, uint32> arraySizes;
		//uint32 

	public:


		BaseClass* Get(const char* className, uint32 index)
		{

		}

	};
}