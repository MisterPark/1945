#include "pch.h"
#include "LTank.h"


LTank::LTank()
{
	transform.scale.x = 35;
	transform.scale.y = 35;
	transform.rotation.z = 45.f;
	speed = 10.f;
	SecondCount = 0.f;
	attackDelay = rand() % 3 + 3;
	isAlliance = false;
	simpleCollider = { -35,-35,35,35 };
	hp = 7;
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

void LTank::OnCollision(GameObject* _other)
{
	if (_other->type == ObjectType::BULLET && _other->isAlliance != isAlliance)
	{
		hp--;
		if (hp < 0)
		{
			Die();
		}
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