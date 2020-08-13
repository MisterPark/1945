#pragma once
#include "Character.h"
class SPlane_1 :
	public Character
{
public:
	SPlane_1();
	virtual ~SPlane_1();

public:
	void Render() override;
	void Update() override;

	bool isShooted = false;
};

