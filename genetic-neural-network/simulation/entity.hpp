#pragma once


#include "../utils/vector.hpp"
#include "../network/network.hpp"
#include "../network/network_defs.hpp"
#include "sim_defs.hpp"
namespace SIM
{
	class Entity
	{



		
		//bool CanMove(ElementMatrix* m, Vector::Vector2I dst);
		void Move(ElementMatrix* m, int dir);
	public:
		
		//i really want that singled bit...
		Vector::Vector2I position;
		float health = 100.0;
		Entity();
		//~Entity();

		virtual void Tick();

		
		

		
	};


	class Creature : public Entity
	{
		NN::Network* network;
		NN::Genes* genes;
		ElementMatrix* worldElements;
		int dir = Dirs::up;




		void DoAction(int id);


	public:
		void Tick();
		void PerceiveEnv();
		


	};
}