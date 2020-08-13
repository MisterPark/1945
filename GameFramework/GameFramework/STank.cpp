#include "pch.h"
#include "STank.h"


STank::STank()
{
	transform.scale.x = 20;
	transform.scale.y = 20;
	transform.rotation.z = 45.f;
}

STank::~STank()
{
}

void STank::Update()
{

	if (destination.x - transform.position.x > 0)
		++transform.position.x;
	if (destination.x - transform.position.x < 0)
		--transform.position.x;
	++transform.position.y;
}



void STank::Render()
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