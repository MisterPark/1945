#include "pch.h"
#include "MCannon.h"


MCannon::MCannon()
{
	transform.scale.x = 35.f;
	transform.scale.y = 35.f;
	transform.rotation.z = 45.f;
	attackDelay = rand() % 3 + 3;
	isAlliance = false;
}

MCannon::~MCannon()
{
}

void MCannon::Update()
{


	++transform.position.y;

	attackTick += TimeManager::DeltaTime();
	if (attackTick > attackDelay)
	{
		attackTick = 0.f;
		GameObject* p = ObjectManager::FindObject(ObjectType::PLAYER);
		if (p == nullptr) return;
		D3DXVECTOR3 posinDirection = p->transform.position;
		posinDirection -= transform.position;
		D3DXVec3Normalize(&posinDirection, &posinDirection);
		posinDirection *= 30.f;
		posinDirection += transform.position;

		Character* b = (Character*)ObjectManager::CreateObject(ObjectType::BULLET);
		b->transform.scale = { 5.f,5.f,0.f };
		b->simpleCollider = { -5,-5,5,5 };
		b->transform.position = this->transform.position;

		D3DXVECTOR3 dir = p->transform.position - transform.position;
		D3DXVec3Normalize(&dir, &dir);

		b->radian = atan2f(dir.y, dir.x);
		b->speed = 400.f;

		b->isAlliance = false;

	}
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