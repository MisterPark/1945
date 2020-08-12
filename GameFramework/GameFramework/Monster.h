#pragma once
#include "Character.h"
class Monster :
	public Character
{
public:
	Monster() = default;
	~Monster() = default;

public:
	void Render() override;
	void Update() override;
	void Ready_Monster();

	int ReadyCount = 0;
};

