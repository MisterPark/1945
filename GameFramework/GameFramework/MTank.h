#pragma once
#include "Character.h"
class MTank :
	public Character
{
public:
	MTank() = default;
	~MTank() = default;

public:
	void Render() override;
	void Update() override;
	void Ready_Monster();

	int ReadyCount = 0;
};

