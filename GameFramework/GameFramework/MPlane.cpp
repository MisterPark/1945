#include "pch.h"
#include "MPlane.h"


MPlane::MPlane()
{
	transform.scale.x = 35;
	transform.scale.y = 35;
	speed = 200.f;
	SecondCount = 0.f;
	isAlliance = false;
	simpleCollider = { -35,-35,35,35 };
	hp = 10;
	attackDelay = 1.f;
}

MPlane::~MPlane()
{
}

void MPlane::Update()
{
	++count;
	
	if (count<=100&&SecondCount==0)
	{
		transform.position.x += forceX * speed * TimeManager::DeltaTime();
		if (count == 100)
		{
			
			speed = -50.f;
			count = 0;
			++SecondCount;
		}
	}
	else if (count <= 100 && SecondCount >= 1 &&SecondCount<6)
	{
		transform.position.x += forceX * speed * TimeManager::DeltaTime();
		if (count == 100)
		{
			forceX *= -1.f;
			count = 0;
			++SecondCount;
		}
	}
	else
	{
		speed = 200.f;
		transform.position.x += forceX * speed * TimeManager::DeltaTime();
		transform.position.y += speed * TimeManager::DeltaTime();
	}

	attackTick += TimeManager::DeltaTime();
	if (attackTick > attackDelay)
	{
		attackTick = 0.f;

		GameObject* p = ObjectManager::FindObject(ObjectType::PLAYER);
		if (p == nullptr) return;
		MultiShot(p, 3);

		
	}
}



void MPlane::Render()
{
	RenderManager::DrawRect(transform.position, transform.rotation, transform.scale);

}