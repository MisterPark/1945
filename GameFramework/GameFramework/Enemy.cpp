#include "pch.h"
#include "Enemy.h"

void Enemy::Update()
{
	isAlliance = false;
}

void Enemy::Render()
{
}

void Enemy::OnCollision(GameObject* _other)
{
	if (_other->type == ObjectType::BULLET && _other->isAlliance != isAlliance)
	{
		hp--;
		if (hp < 0)
		{
			Die();
		}
	}
}
