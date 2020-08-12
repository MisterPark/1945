#pragma once
#include "Character.h"
class LPlane :
	public Character
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

