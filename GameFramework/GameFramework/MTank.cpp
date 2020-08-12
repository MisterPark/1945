#include "pch.h"
#include "MTank.h"

void MTank::Update()
{
	Ready_Monster();
	if (direction.x - position.x > 0)
		++position.x;
	if (direction.x - position.x < 0)
		--position.x;
	++position.y;
}


void MTank::Render()
{
	RenderManager::DrawRect(position, rotation, scale);

}

void MTank::Ready_Monster()
{
	if (ReadyCount == 0)
	{
		scale.x = 25;
		scale.y = 25;
		++ReadyCount;
	}
}
