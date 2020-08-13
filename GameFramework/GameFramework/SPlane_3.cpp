#include "pch.h"
#include "SPlane_3.h"


SPlane_3::SPlane_3()
{
	transform.scale.x = 25;
	transform.scale.y = 25;
	speed = 300.f;
}

SPlane_3::~SPlane_3()
{
}

void SPlane_3::Update()
{
	transform.position.y += speed * TimeManager::DeltaTime();
	if (transform.position.y > 300)
	{
		if (destination.x - transform.position.x > 0)
			transform.position.x += speed * TimeManager::DeltaTime();
		if (destination.x - transform.position.x < 0)
			transform.position.x -= speed * TimeManager::DeltaTime();
	}
}



void SPlane_3::Render()
{
	RenderManager::DrawRect(transform.position, transform.rotation, transform.scale);

}