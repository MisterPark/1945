#pragma once
#include "Character.h"
class Monster :
	public Character
{
public:
	Monster() = default;
	~Monster() = default;

	virtual void Update() override;
	virtual void Render() override;
};

