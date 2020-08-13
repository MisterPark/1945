#pragma once
#include "Enemy.h"
class SPlane_1 :
	public Enemy
{
public:
	SPlane_1();
	virtual ~SPlane_1();

public:
	void Render() override;
	void Update() override;

	bool isShooted = false;
};

