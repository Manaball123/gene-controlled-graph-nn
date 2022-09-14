#pragma once
#include <memory>





namespace NN
{
	//alloactor made specifically for my project :D
	//

	class MemPoolAllocator
	{
		
		//Determined upon object creation, should not be modified after initialization
		size_t size;
		//mem pool
		char* pool;
		//bool freed = 0;
		size_t currentOffset;

	public:

		

		//RAW BYTE SIZE of pool
		MemPoolAllocator(size_t poolSize)
		{
			pool = new char[poolSize];
			currentOffset = 0;
			size = poolSize;

		}
		
		MemPoolAllocator()
		{
			pool = nullptr;
			currentOffset = 0;
			size = 0;
		}
		
		~MemPoolAllocator()
		{
			//freed = 1;
			delete[] pool;
		}
		//Create block of new memory, frees the previous
		void Reallocate(size_t poolSize)
		{
			delete[] pool;
			pool = new char[poolSize];
			currentOffset = 0;
			size = poolSize;

		}
		//element_size exists as not having it would cause object slicing(probably)
		//remember to cast this into the derived class
		void* New(
			size_t elementSize,
			size_t elementNum = 1
		)
		{

			
			void* newMem = (pool + currentOffset);
			currentOffset += elementSize * elementNum;

			if (currentOffset > size) 
			{
				throw std::bad_alloc();
				return nullptr;
			}
			return newMem;
		}


	};
}