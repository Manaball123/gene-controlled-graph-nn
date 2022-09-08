#include "console_renderer.hpp"

#define CHAR_SPACE 0x20
using namespace CLIRenderer;
CRenderer::CRenderer(uint32 w, uint32 h)
{
	screen = Matrix::Matrix2<char>(w, h);


}


CRenderer::CRenderer()
{
	screen = Matrix::Matrix2<char>();
}

void CRenderer::AddPixel(char pixel, uint32 x, uint32 y)
{
	screen.Set(x, y, pixel);
}

void CRenderer::AddPixel(char pixel, uint32 index)
{
	screen.data[index] = pixel;
}
//This isnt really nulling them out its just making them white spaces
void CRenderer::ClearPixels()
{
	for (uint i = 0; i < screen.xLen * screen.yLen; i++)
	{
		screen.data[i] = CHAR_SPACE;
	}
}



void CRenderer::Draw()
{
	//draw higher columns first
	for (int i = screen.yLen - 1; i >= 0; i--)
	{
		for (uint j = 0; j < screen.xLen; j++)
		{
			std::cout << screen.Get(i, j);
		}
		std::cout << std::endl;
	}
}
