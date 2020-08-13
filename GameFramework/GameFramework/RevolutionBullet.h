#pragma once
#include "Bullet.h"
class RevolutionBullet :
    public Bullet
{
public:
	RevolutionBullet();
	virtual ~RevolutionBullet();

	virtual void Update() override;
	virtual void Render() override;
	virtual void OnCollision(GameObject* _other) override;
};

