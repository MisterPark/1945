#include "pch.h"
#include "MCannon.h"


MCannon::MCannon()
{
	transform.scale.x = 35.f;
	transform.scale.y = 35.f;
	transform.rotation.z = 45.f;
}

MCannon::~MCannon()
{
}

void MCannon::Update()
{


	++transform.position.y;
}



void MCannon::Render()
{
	RenderManager::DrawRect(transform.position, transform.rotation, transform.scale);

}