#pragma once

#include <vector>
#include "matrix.hpp"
#include "typedefs.hpp"
#include <iostream>

namespace CLIRenderer
{
	class CRenderer
	{
		Matrix::Matrix2<char> screen;
		
	public:
		CRenderer(uint32 w, uint32 h);
		CRenderer();
		void ClearPixels();
		void AddPixel(char pixel, uint32 index);
		void AddPixel(char pixel, uint32 x, uint32 y);
		void Draw();

	};
}