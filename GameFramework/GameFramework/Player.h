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

	float posinLength = 40.f;
	float posinDegree = 0.f;
};
