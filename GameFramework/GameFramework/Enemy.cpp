#include "pch.h"
#include "Enemy.h"

void Enemy::Update()
{
	isAlliance = false;
	if (transform.position.x < -200 || transform.position.x > dfWINDOW_WIDTH+200 ||
		transform.position.y < -800 || transform.position.y > dfWINDOW_HEIGHT+300)
	{
		Die();
	}
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
