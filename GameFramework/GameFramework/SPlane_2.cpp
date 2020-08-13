#include "pch.h"
#include "SPlane_2.h"


SPlane_2::SPlane_2()
{
	scale.x = 25;
	scale.y = 25;
	speed = 300.f;
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
	position.y += speed * TimeManager::DeltaTime();

	if (position.y > 300)
	{
		
		if (destination.x - position.x > 0)
			position.x += speed * TimeManager::DeltaTime();
		if (destination.x - position.x < 0)
			position.x -= speed * TimeManager::DeltaTime();
	}

}



void SPlane_2::Render()
{
	RenderManager::DrawRect(position, rotation, scale);

}