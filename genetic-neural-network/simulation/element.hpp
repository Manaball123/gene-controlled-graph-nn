#pragma once
#include "../network/network.hpp"



namespace SIM
{

	class Element
	{
		Element();
		~Element();


		virtual void Use();
		virtual void Attack();
		virtual void Break();
		static uint64 properties;
	};

	class SolidBlock : public Element
	{
		inline void Use() {};
		inline void Attack() {};
		inline void Break() {};

	};



	class Creature : public Element
	{

		float health = 100.0;

		NN::Network* network;

		NN::Gene* gene;




		

		

	};


}