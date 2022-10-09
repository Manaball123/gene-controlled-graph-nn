#pragma once

#include "../utils/matrix.hpp"
#include "element.hpp"
#include <vector>
#include "entity.hpp"
namespace SIM
{

	class World
	{
		Matrix::Matrix2<Element*> world;
		std::vector<Entity*> entities;

		World();
		~World();
		

	};
}