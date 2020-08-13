#include "pch.h"
#include "TestMonster.h"

TestMonster::TestMonster()
{
	transform.localPosition = { 200.f , 200.f,0.f };
	transform.position = { 100.f,100.f,0.f };
	transform.scale = { 20.f,20.f,0.f };
	simpleCollider = { -20,-20,20,20 };
	speed = 100.f;
	isAlliance = false;
}

TestMonster::~TestMonster()
{
}

void TestMonster::Update()
{
	
	//transform.rotation.z += 10;
	transform.RotateAround(D3DXVECTOR3(100, 100, 0), -1);
	//transform.position.y += speed * TimeManager::DeltaTime();
}

void TestMonster::Render()
{
	RenderManager::DrawRect(transform.position, transform.rotation, transform.scale);
}

void TestMonster::OnCollision(GameObject* _other)
{
	if (_other->type == ObjectType::BULLET && _other->isAlliance != isAlliance)
	{
		Die();
	}
}
