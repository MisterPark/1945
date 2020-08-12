#include "pch.h"
#include "SPlane_3.h"


SPlane_3::SPlane_3()
{
	scale.x = 25;
	scale.y = 25;
	speed = 300.f;
}

SPlane_3::~SPlane_3()
{
}

void SPlane_3::Update()
{
	position.y += speed * TimeManager::DeltaTime();
	if (position.y > 300)
	{
		if (destination.x - position.x > 0)
			position.x += speed * TimeManager::DeltaTime();
		if (destination.x - position.x < 0)
			position.x -= speed * TimeManager::DeltaTime();
	}
}



void SPlane_3::Render()
{
	RenderManager::DrawRect(position, rotation, scale);

}