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

	if (destination.x - position.x > 0)
		++position.x;
	if (destination.x - position.x < 0)
		--position.x;
	++position.y;
}



void STank::Render()
{
	RenderManager::DrawRect(position, rotation, scale);

}