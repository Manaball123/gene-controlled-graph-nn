#pragma once
//#include "../network/network.hpp"



namespace SIM
{

	class Element
	{
		Element();
		~Element();


	public:
		virtual void Use();
		virtual void Attack();
		virtual void Break();
		virtual bool IsSolid();

		static uint64 properties;
	};

	class SolidElement : public Element
	{
		inline bool IsSolid()
		{
			return true;
		}
		inline void Use() {};
		inline void Attack() {};
		inline void Break() {};

	};
	//Can be passed through by entities
	class NonsolidElement : public Element
	{
		inline bool IsSolid()
		{
			return false;
		}
	};





}