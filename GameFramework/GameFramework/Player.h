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

	float posinLength = 40.f;
	float posinDegree = 0.f;
};

