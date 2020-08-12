#pragma once
#include "Character.h"
class STank :
	public Character
{
public:
	STank();
	virtual ~STank();

public:
	void Render() override;
	void Update() override;
	void Ready_Monster();

	int ReadyCount = 0;
};

