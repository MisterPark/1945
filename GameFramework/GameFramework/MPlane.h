#pragma once
#include "Character.h"
class MPlane :
	public Character
{
public:
	MPlane();
	virtual ~MPlane();
	void Set_forceX(float _forceX) { forceX = _forceX; }


public:
	void Render() override;
	void Update() override;
	float forceX = 1.f;

	float count = 0.f;
	float SecondCount = 0.f;
};

