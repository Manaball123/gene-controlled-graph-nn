#pragma once

#include "../utils/matrix.hpp"
#include "element.hpp"
#include <vector>
#include "entity.hpp"


namespace SIM
{

	class World
	{

		Matrix::Matrix2<Element*> elements;
		std::vector<Entity*> entities;

	public:

		World();
		~World();


		void Tick();


	};
}