#pragma once
#include "Character.h"
class SPlane_2 :
	public Character
{
public:
	SPlane_2();
	virtual ~SPlane_2();



public:
	void Render() override;
	void Update() override;

	float tick = 0.f;
	float delay = 1.f;
};

