#pragma once


#include "../utils/vector.hpp"
#include "../network/network.hpp"
namespace SIM
{
	class Entity
	{


		Entity();
		~Entity();

		float health = 100.0;
		
		Vector::Vector2UI position;
		
	};


	class Creature : public Entity
	{
		NN::Network* network;

	};
}