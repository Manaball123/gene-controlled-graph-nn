#pragma once
#include "world.hpp"



using namespace SIM;



void World::Tick()
{
	//iterate through all entities
	for (size_t i = 0; i < entities.size(); i++)
	{
		entities[i]->Tick();
	}
}