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
	virtual void OnCollision(GameObject* _other);

	void Attack();
	void Bomb(); /// ½ºÅ³
 
	float subAttackTick = 0.f;
	float subAttackDelay = 0.4f;


	float bombTick = 0.f;
	float bombDelay = 0.5f;


	float c1Tick = 0.f;

	

};

