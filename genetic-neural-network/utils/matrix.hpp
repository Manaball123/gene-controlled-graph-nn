#pragma once
#include "typedefs.hpp"
namespace Matrix
{
	
	template <class dtype>
	class Matrix2
	{
		
		
	public:
		dtype* data;
		uint32 xLen, yLen;

		Matrix2(uint32 xLen, uint32 yLen)
		{
			data = new dtype[xLen * yLen];
			this->xLen = xLen;
			this->yLen = yLen;

		}
		Matrix2()
		{
			data = nullptr;
			this->xLen = 0;
			this->yLen = 0;
		}
		~Matrix2()
		{
			if (data != nullptr)
			{
				return;
			}
			delete[] this->data;
		}
		
		dtype Get(uint32 x, uint32 y)
		{
			return data[x + y * xLen];
		}
		void Set(uint32 x, uint32 y, dtype value)
		{
			data[x + y * xLen] = value;
		}

	};

	
	
		using Matrix2F = Matrix2<float>;
		using Matrix2D = Matrix2<double>;



		using Matrix2I = Matrix2<int32>;
		using Matrix2UI = Matrix2<uint32>;
		using Matrix2S = Matrix2<int16>;
		using Matrix2US = Matrix2<uint16>;
		using Matrix2L = Matrix2<int64>;
		using Matrix2UL = Matrix2<uint64>;
	

}