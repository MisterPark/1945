#pragma once
#include "Enemy.h"
class LPlane :
	public Enemy
{
public:
	LPlane();
	virtual ~LPlane();

public:
	void Render() override;
	void Update() override;

	float count=0.f;
	float SecondCount = 0.f;
};

