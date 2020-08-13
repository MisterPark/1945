#pragma once
#include "Enemy.h"
class Boss :
	public Enemy
{
public:
	Boss();
	virtual ~Boss();

public:
	void Render() override;
	void Update() override;
	virtual void OnCollision(GameObject* _other);

	Transform leftarm;
	Transform rightarm;
	float count = 0.f;
	float SecondCount = 0.f;
	float yspeed = 0.f;
};

