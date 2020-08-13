#pragma once
#include "Enemy.h"
class MCannon :
	public Enemy
{
public:
	MCannon();
	virtual ~MCannon();

public:
	void Render() override;
	void Update() override;


};

