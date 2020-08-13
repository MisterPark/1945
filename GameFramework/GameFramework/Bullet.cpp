#include "pch.h"
#include "Bullet.h"

Bullet::Bullet()
{
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
		Die();
	}
}

void Bullet::Render()
{
	RenderManager::DrawRect(position, rotation, scale);
}

void Bullet::OnCollision(GameObject * _other)
{
	if (isAlliance != _other->isAlliance)
	{
		Die();
	}
}
