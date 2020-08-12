#include "pch.h"
#include "SPlane_1.h"

void SPlane_1::Update()
{
	Ready_Monster();
	if (destination.x - position.x > 0)
		++position.x*speed;
	if (destination.x - position.x < 0)
		--position.x*speed;
	++position.y* speed;
}


void SPlane_1::Render()
{
	RenderManager::DrawRect(position, rotation, scale);

}

void SPlane_1::Ready_Monster()
{
	if (ReadyCount == 0)
	{
		scale.x = 20;
		scale.y = 20;
		speed = 10.f;
		++ReadyCount;
	}
}
