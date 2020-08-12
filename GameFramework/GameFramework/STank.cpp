#include "pch.h"
#include "STank.h"


STank::STank()
{
	scale.x = 20;
	scale.y = 20;
}

STank::~STank()
{
}

void STank::Update()
{
	/*Ready_Monster();*/
	if (direction.x - position.x > 0)
		++position.x;
	if (direction.x - position.x < 0)
		--position.x;
	++position.y;
}



void STank::Render()
{
	RenderManager::DrawRect(position, rotation, scale);

}

void STank::Ready_Monster()
{
	if (ReadyCount == 0)
	{
		
		scale.x = 20;
		scale.y = 20;
		++ReadyCount;
	}
}
