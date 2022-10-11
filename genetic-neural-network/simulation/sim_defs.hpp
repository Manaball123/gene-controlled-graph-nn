#ifndef __SIMDEFS__
#define __SIMDEFS__

#include "../utils/matrix.hpp"
#include "../utils/vector.hpp"
#include "element.hpp"

//64 * 64
#define WORLD_SIZE 64
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


	//directions enum
	namespace Dirs
	{
		enum DirsEnum
		{
			up,
			down,
			left,
			right
		};
	}


	//There should be no easy way to tell the item the entity is currently holding as 
	namespace Senses
	{
		enum SensesEnum
		{

		};
	}
	using Vec2I = Vector::Vector2I;
	using ElementMatrix = Matrix::Matrix2<Element*>;

}





#endif // !__SIMDEFS__
