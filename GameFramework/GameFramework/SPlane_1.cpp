#include "pch.h"
#include "SPlane_1.h"


SPlane_1::SPlane_1()
{
	scale.x = 25;
	scale.y = 25;
	speed = 300.f;
}

SPlane_1::~SPlane_1()
{
}

void SPlane_1::Update()
{


	position.y += speed*TimeManager::DeltaTime();

	if (position.y > 300)
	{
		speed *= -1.f;
	}
	if (speed < 0)
	{
		position.x -= speed * TimeManager::DeltaTime();
	}
}



void SPlane_1::Render()
{
	RenderManager::DrawRect(position, rotation, scale);

}