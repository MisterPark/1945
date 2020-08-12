#include "pch.h"
#include "Monster.h"

void Monster::Update()
{
	Ready_Monster();

	++position.y;
}

void Monster::Ready_Monster()
{
	if (ReadyCount == 0)
	{
		scale.x = 20;
		scale.y = 20;
		++ReadyCount;
	}
}

void Monster::Render()
{
	RenderManager::DrawRect(position, rotation, scale);
}
