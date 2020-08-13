#include "pch.h"
#include "SPlane_1.h"


SPlane_1::SPlane_1()
{
	transform.scale.x = 25;
	transform.scale.y = 25;
	speed = 300.f;
}

SPlane_1::~SPlane_1()
{
}

void SPlane_1::Update()
{


	transform.position.y += speed*TimeManager::DeltaTime();

	if (transform.position.y > 300)
	{
		speed *= -1.f;
	}
	if (speed < 0)
	{
		transform.position.x -= speed * TimeManager::DeltaTime();
	}
}



void SPlane_1::Render()
{
	RenderManager::DrawRect(transform.position, transform.rotation, transform.scale);

}