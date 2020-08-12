#pragma once
#include "Character.h"
class SPlane_1 :
	public Character
{
public:
	SPlane_1() = default;
	~SPlane_1() = default;

public:
	void Render() override;
	void Update() override;
	void Ready_Monster();

	int ReadyCount = 0;
};

