#include "pch.h"
#include "SPlane_2.h"


SPlane_2::SPlane_2()
{
	transform.scale.x = 15;
	transform.scale.y = 15;
	speed = 300.f;
	isAlliance = false;
	simpleCollider = { -15,-15,15,15 };
	hp = 1;
}

SPlane_2::~SPlane_2()
{
}

void SPlane_2::Update()
{
	tick += TimeManager::DeltaTime();

	if (tick > delay)
	{
		tick = 0.f;
	}
	transform.position.y += speed * TimeManager::DeltaTime();

	if (transform.position.y > 300)
	{
		
		if (destination.x - transform.position.x > 0)
			transform.position.x += speed * TimeManager::DeltaTime();
		if (destination.x - transform.position.x < 0)
			transform.position.x -= speed * TimeManager::DeltaTime();
	}

}



void SPlane_2::Render()
{
	RenderManager::DrawRect(transform.position, transform.rotation, transform.scale);

}