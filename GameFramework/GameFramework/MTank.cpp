#include "pch.h"
#include "MTank.h"


MTank::MTank()
{
	transform.scale.x = 25;
	transform.scale.y = 25;

}

MTank::~MTank()
{
}

void MTank::Update()
{

	if (destination.x - transform.position.x > 0)
		++transform.position.x;
	if (destination.x - transform.position.x < 0)
		--transform.position.x;
	++transform.position.y;
}



void MTank::Render()
{
	RenderManager::DrawRect(transform.position, transform.rotation, transform.scale);

}