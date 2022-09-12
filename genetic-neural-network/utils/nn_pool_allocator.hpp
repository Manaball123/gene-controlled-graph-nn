#pragma once
#include <memory>





namespace NN
{
	//alloactor made specifically for my project :D
	//
	template <class T>
	class MemPoolAllocator
	{
		
		//Determined upon object creation, should not be modified after initialization
		size_t size;
		//mem pool
		char* pool;
		
		size_t currentOffset;

	public:


		MemPoolAllocator(size_t poolSize)
		{
			pool = (char*)malloc(poolSize);
			currentOffset = 0;
			size = poolSize;

		}
		~MemPoolAllocator()
		{
			free(pool);
		}
		//element_size exists as not having it would cause object slicing(probably)
		//remember to cast this into the derived class
		T* Alloc(
			size_t elementSize = sizeof(T),
			size_t elementNum = 1
		)
		{
			T* newMem = (T*)(pool + currentOffset);
			currentOffset += elementSize * elementNum;
			return newMem;
		}


	};
}