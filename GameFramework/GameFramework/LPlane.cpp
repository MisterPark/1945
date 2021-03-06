#include "pch.h"
#include "LPlane.h"


LPlane::LPlane()
{
	transform.scale.x = 50;
	transform.scale.y = 50;
	speed = 100.f;
	isAlliance = false;
	simpleCollider = { -50,-50,50,50 };
	hp = 15;
	attackDelay = 1.f;
}

LPlane::~LPlane()
{
}

void LPlane::Update()
{
	if (SecondCount < 3)
	{
		if (transform.position.y < destination.y)
		{
			transform.position.y += speed * TimeManager::DeltaTime();
		}
		if (transform.position.y > destination.y)
		{
			if (count == 0)
			{
				speed = 4.f;
			}
			++count;

			if (count > 0)
			{
				transform.position.x -= speed * TimeManager::DeltaTime();
			}
		}

		if (count > 150)
		{
			count = 1;
			speed *= -1.f;
			++SecondCount;
		}
	}
	else
	{
		speed = 200.f;
		transform.position.x += speed * TimeManager::DeltaTime();
		transform.position.y += speed * TimeManager::DeltaTime();
	}

	attackTick += TimeManager::DeltaTime();
	if (attackTick > attackDelay)
	{
		attackTick = 0.f;

		GameObject* p = ObjectManager::FindObject(ObjectType::PLAYER);
		if (p == nullptr) return;
		MultiShot(p, 5);


	}
}



void LPlane::Render()
{
	RenderManager::DrawRect(transform.position, transform.rotation, transform.scale);

}