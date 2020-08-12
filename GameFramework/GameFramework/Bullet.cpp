#include "pch.h"
#include "Bullet.h"

Bullet::Bullet()
{
	simpleCollider = { -5,-5,5,5 };
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	position.x = position.x + cosf(radian) * speed * TimeManager::DeltaTime();
	position.y = position.y + sinf(radian) * speed * TimeManager::DeltaTime();

	if (position.x < 0 || position.x > dfWINDOW_WIDTH ||
		position.y < 0 || position.y > dfWINDOW_HEIGHT)
	{
		this->Die();
	}
}

void Bullet::Render()
{
	float left = simpleCollider.left + position.x;
	float right = simpleCollider.right + position.x;
	float top = simpleCollider.top + position.y;
	float bottom = simpleCollider.bottom + position.y;
	RenderManager::DrawRect(left, top, right, bottom);
}

void Bullet::OnCollision(GameObject * _other)
{
}
