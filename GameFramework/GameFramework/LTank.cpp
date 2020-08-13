#include "pch.h"
#include "LTank.h"


LTank::LTank()
{
	transform.scale.x = 35;
	transform.scale.y = 35;
	transform.rotation.z = 45.f;
	speed = 10.f;
	SecondCount = 0.f;
}

LTank::~LTank()
{
}

void LTank::Update()
{
	++count;
	if (count < 300 && SecondCount == 0)
	{
		++transform.position.y;
	}
	if (count > 300 && SecondCount == 0)
	{
		transform.position.y -= speed * TimeManager::DeltaTime();
		if (count > 400)
		{
			++SecondCount;
		}
	}
	if (SecondCount == 1)
	{
		++transform.position.y;
	}

}



void LTank::Render()
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