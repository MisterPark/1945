#include "pch.h"
#include "Character.h"

void Character::Update()
{
	
}

void Character::Render()
{
}

bool Character::isCollided(const GameObject* _target)
{


	return false;
}

void Character::SetColliderSize(LONG left, LONG top, LONG right, LONG bottom)
{
	simpleCollider.left = left;
	simpleCollider.top = top;
	simpleCollider.right = right;
	simpleCollider.bottom = bottom;
}

void Character::PushOut(Character* target, float _force)
{


}



