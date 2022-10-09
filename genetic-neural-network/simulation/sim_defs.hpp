#ifndef __SIMDEFS__
#define __SIMDEFS__


namespace SIM
{
	namespace Actions
	{
		enum ActionsEnum
		{
			lookUp,
			lookDown,
			lookLeft,
			lookRight,
			//walk to faced direction
			walk,
			

			
			useHeld,
			dropHeld,
			pickup,
			swap,
			combine,

			//This overrides the senses and makes the sensory details return
			identify,




		};
		

	}


	//There should be no easy way to tell the item the entity is currently holding as 
	namespace Senses
	{
		enum SensesEnum
		{

		};
	}

}





#endif // !__SIMDEFS__
