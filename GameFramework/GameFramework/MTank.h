#pragma once
#include "Character.h"
class MTank :
	public Character
{
public:
	MTank();
	virtual ~MTank();

public:
	void Render() override;
	void Update() override;


};

