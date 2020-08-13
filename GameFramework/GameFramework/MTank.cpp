#include "pch.h"
#include "MTank.h"


MTank::MTank()
{
	transform.scale.x = 25.f;
	transform.scale.y = 25.f;
	transform.rotation.z = 45.f;
}

MTank::~MTank()
{
}

void MTank::Update()
{


	++transform.position.y;
}



void MTank::Render()
{
	RenderManager::DrawRect(transform.position, transform.rotation, transform.scale);

}