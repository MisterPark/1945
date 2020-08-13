#pragma once
#include "Enemy.h"
class LTank :
	public Enemy
{
public:
	LTank();
	virtual ~LTank();
	void Set_forceX(float _forceX) { forceX = _forceX; }


public:
	void Render() override;
	void Update() override;
	virtual void OnCollision(GameObject* _other);
	float forceX = 1.f;

	float count = 0.f;
	float SecondCount = 0.f;
};

