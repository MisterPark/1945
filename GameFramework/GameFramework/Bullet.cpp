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
	// 대기하는거 만들고

	// 속도가 000미만일때.

	// 어디까지 증가할지

	/*
		동그란 전기발사
	*/

	if (isAccelerate == true)
	{
		accelCount += 100.f;
	}


	transform.position.x = transform.position.x + cosf(radian) * accelCount * speed * TimeManager::DeltaTime();
	transform.position.y = transform.position.y + sinf(radian) * accelCount * speed * TimeManager::DeltaTime();

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
