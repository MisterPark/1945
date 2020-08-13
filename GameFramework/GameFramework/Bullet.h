#pragma once
#include "Character.h"
class Bullet :
	public Character
{
public:
	Bullet();
	virtual ~Bullet();

	virtual void Update() override;
	virtual void Render() override;
	virtual void OnCollision(GameObject* _other) override;

	bool isReversing = false;
	bool isAccelerate = false;

	float accelCount = 1.f;


};

