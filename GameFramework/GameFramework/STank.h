#pragma once
#include "Enemy.h"
class STank :
	public Enemy
{
public:
	STank();
	virtual ~STank();

public:
	void Render() override;
	void Update() override;

};

