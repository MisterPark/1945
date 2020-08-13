#include "pch.h"
#include "TestMonster.h"

TestMonster::TestMonster()
{
	position = { 100.f , -100.f,0.f };
	scale = { 20.f,20.f,0.f };
	speed = 100.f;
}

TestMonster::~TestMonster()
{
}

void TestMonster::Update()
{
	position.y += speed * TimeManager::DeltaTime();
	rotation.z += 10;
	position += D3DXVECTOR3(10, 10, 10);
}

void TestMonster::Render()
{
	RenderManager::DrawRect(position, rotation, scale);
}

void TestMonster::OnCollision(GameObject* _other)
{
}
