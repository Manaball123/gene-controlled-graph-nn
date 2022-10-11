#include "entity.hpp"


using namespace SIM;
using namespace NN;
using namespace Vector;



inline bool IsOOB(Vector2I dst)
{
	if (dst.x < 0 || dst.y < 0)
	{
		return true;
	}
	//if oob in positive end
	if (dst.x >= WORLD_SIZE || dst.y >= WORLD_SIZE)
	{
		return true;
	}
}

bool CanMove(ElementMatrix* m, Vector2I dst)
{
	//return false if either ints are negative(cuz it will 100% be oob)
	if (IsOOB(dst))
	{
		return false;
	}
	//if dst is a solid block
	if (m->Get(dst.x, dst.y)->IsSolid())
	{
		return false;
	}
	
	return true;
}

//No entity collisions, fuck u
void Entity::Move(ElementMatrix* m, int dir)
{
	//should copy the thing over
	Vector::Vector2I dst = position;
	switch (dir)
	{
	case Dirs::up:
		dst.y++;
		break;
	case Dirs::down:
		dst.y--;
		break;
	case Dirs::left:
		dst.x--;
		break;
	case Dirs::right:
		dst.x++;
		break;

	default:
		//should not be called ever so gonna make funny crash here
		*((char*)nullptr) = 0;

	}
	//if can move then move
	if (CanMove(m, dst))
	{
		position = dst;
	}
}

//Get from world
consteval size_t GetInputIndex(int xOffset, int yOffset)
{

	size_t res;
	return xOffset + yOffset * 3;

}

//wanted to make this consteval :(
Vector2I GetRelativeVec(size_t index)
{
	return Vector2I(index % 3, index / 3);
}






NN::activation_t PerceiveBlock(ElementMatrix* m, Vector2I v)
{
	//check for oob
	if (IsOOB(v))
	{
		return -1.0;
	}

	if (CanMove(m, v))
	{
		return 1.0;
	}
	return 0.0;
	
}
//

#define ENV_PERC_NEURONS 9
void Creature::PerceiveEnv()
{
	for (size_t i = 0; i < ENV_PERC_NEURONS; i++)
	{
		network->neurons[i]->currentActivation = PerceiveBlock(worldElements, position + GetRelativeVec(i));
		
	}
	
}



Vector2I GetMoveVec(int dir)
{
	using namespace Dirs;
	switch (dir)
	{
	case up:
		return Vector2I(0, 1);
		break;
	case down:
		return Vector2I(0, -1);
		break;
	case left:
		return Vector2I(-1, 0);
		break;
	case right:
		return Vector2I(1, 0);
		break;
	}
}
void Creature::DoAction(int id)
{
	using namespace Actions;
	using namespace Dirs;
	switch (id)
	{
	case lookUp:
		dir = up;
		break;
	case lookDown:
		dir = down;
		break;
	case lookLeft:
		dir = left;
		break;
	case lookRight:
		dir = right;
		break;
		//walk to faced direction
	case walk:

		break;
	}

}

void Creature::Tick()
{
	//Add input sensories

	PerceiveEnv();

	//Process information
	network->Propagate();

	//Execute results
	int dec = network->GetDecision();
	DoAction(dec);
	
}

