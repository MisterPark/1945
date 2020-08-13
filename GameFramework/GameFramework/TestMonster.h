#pragma once
#include "Character.h"
class TestMonster : public Character
{
public:
	TestMonster();
	~TestMonster();

	virtual void Update() override;
	virtual void Render() override;
	virtual void OnCollision(GameObject* _other) override;

	D3DXVECTOR3 revolution{ 0.f,0.f,0.f };
	D3DXVECTOR3 parentPos{ 0.f,0.f,0.f };
};

