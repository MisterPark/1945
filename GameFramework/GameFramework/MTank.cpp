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

	GameObject* p = ObjectManager::FindObject(ObjectType::PLAYER);
	if (p == nullptr) return;
	D3DXVECTOR3 posinDirection = p->transform.position;
	posinDirection -= transform.position;
	D3DXVec3Normalize(&posinDirection, &posinDirection);
	posinDirection *= 30.f;
	posinDirection += transform.position;
	RenderManager::DrawLine(transform.position.x, transform.position.y, posinDirection.x, posinDirection.y);

}