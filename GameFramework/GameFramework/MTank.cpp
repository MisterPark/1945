#include "pch.h"
#include "MTank.h"


MTank::MTank()
{
	scale.x = 25;
	scale.y = 25;

}

MTank::~MTank()
{
}

void MTank::Update()
{

	if (destination.x - position.x > 0)
		++position.x;
	if (destination.x - position.x < 0)
		--position.x;
	++position.y;
}



void MTank::Render()
{
	RenderManager::DrawRect(position, rotation, scale);

}