#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	Player();
	virtual ~Player();

	virtual void Update() override;
	virtual void Render() override;
	virtual void OnCollision(GameObject* _other);

	void Attack();

	float posinLength = 40.f;
	float posinDegree = 0.f;

	float attackTick = 0.f;
	float attackDelay = 0.1f;
};

