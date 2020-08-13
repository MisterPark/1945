#include "pch.h"
#include "SPlane_1.h"


SPlane_1::SPlane_1()
{
	transform.scale.x = 15;
	transform.scale.y = 15;
	speed = 300.f;
	isAlliance = false;
}

SPlane_1::~SPlane_1()
{
}

void SPlane_1::Update()
{


	transform.position.y += speed*TimeManager::DeltaTime();

	if (transform.position.y > 300)
	{
		speed *= -1.f;
		if (isShooted == false)
		{
			GameObject* p = ObjectManager::FindObject(ObjectType::PLAYER);
			if (p != nullptr)
			{
				Character* b = (Character*)ObjectManager::CreateObject(ObjectType::BULLET);
				b->transform.scale = { 5.f,5.f,0.f };
				b->simpleCollider = { -5,-5,5,5 };
				b->transform.position = this->transform.position;

				D3DXVECTOR3 dir = p->transform.position - transform.position;
				D3DXVec3Normalize(&dir, &dir);

				b->radian = atan2f(dir.y, dir.x);
				b->speed = 400.f;
				
				b->isAlliance = false;
				isShooted = true;
			}
			
		}
	}
	if (speed < 0)
	{
		transform.position.x -= speed * TimeManager::DeltaTime();
	}
}



void SPlane_1::Render()
{
	RenderManager::DrawRect(transform.position, transform.rotation, transform.scale);

}