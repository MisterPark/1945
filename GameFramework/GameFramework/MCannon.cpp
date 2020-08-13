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

	GameObject* p = ObjectManager::FindObject(ObjectType::PLAYER);
	if (p == nullptr) return;
	D3DXVECTOR3 posinDirection = p->transform.position;
	posinDirection -= transform.position;
	D3DXVec3Normalize(&posinDirection, &posinDirection);
	posinDirection *= 30.f;
	posinDirection += transform.position;
	RenderManager::DrawLine(transform.position.x, transform.position.y, posinDirection.x, posinDirection.y);

}