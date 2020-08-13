#pragma once
#include "Character.h"

class Missle :
	public Character
{
public:
	Missle();
	virtual ~Missle();

	virtual void Update() override;
	virtual void Render() override;
	virtual void OnCollision(GameObject* _other) override;

};

