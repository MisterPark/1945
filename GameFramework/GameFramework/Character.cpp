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

RECT Character::GetCollisionArea()
{
	RECT rc;
	rc.left = simpleCollider.left + transform.position.x;
	rc.right = simpleCollider.right + transform.position.x;
	rc.top = simpleCollider.top + transform.position.y;
	rc.bottom = simpleCollider.bottom + transform.position.y;
	return rc;
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



