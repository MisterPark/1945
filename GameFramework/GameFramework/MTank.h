#pragma once
#include "Enemy.h"
class MTank :
	public Enemy
{
public:
	MTank();
	virtual ~MTank();

public:
	void Render() override;
	void Update() override;

	virtual void OnCollision(GameObject* _other);
};

