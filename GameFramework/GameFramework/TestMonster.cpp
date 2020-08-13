#include "pch.h"
#include "TestMonster.h"

TestMonster::TestMonster()
{
	transform.localPosition = { 200.f , 200.f,0.f };
	transform.position = { 100.f,100.f,0.f };
	transform.scale = { 20.f,20.f,0.f };
	speed = 100.f;
}

TestMonster::~TestMonster()
{
}

void TestMonster::Update()
{
	transform.localPosition.y += speed * TimeManager::DeltaTime();
	//transform.rotation.z += 10;
	transform.RotateAround(D3DXVECTOR3(0, 0, 0), -1);
}

void TestMonster::Render()
{
	RenderManager::DrawRect(transform.position, transform.rotation, transform.scale);
}

void TestMonster::OnCollision(GameObject* _other)
{
}
