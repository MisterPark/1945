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
	
	transform.position.x = transform.position.x + cosf(radian) * speed * TimeManager::DeltaTime();
	transform.position.y = transform.position.y + sinf(radian) * speed * TimeManager::DeltaTime();

	if (transform.position.x < 0 || transform.position.x > dfWINDOW_WIDTH ||
		transform.position.y < 0 || transform.position.y > dfWINDOW_HEIGHT)
	{
		Die();
	}
}

void Bullet::Render()
{
	RenderManager::DrawRect(transform.position, transform.rotation, transform.scale);
}

void Bullet::OnCollision(GameObject * _other)
{
	if (_other->type == ObjectType::BULLET) return;
	if (_other->type == ObjectType::REV_BULLET) return;
	if (isAlliance != _other->isAlliance)
	{
		Die();
	}
}
