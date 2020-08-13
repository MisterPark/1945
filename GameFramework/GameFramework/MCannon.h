#pragma once
#include "Character.h"
class MCannon :
	public Character
{
public:
	MCannon();
	virtual ~MCannon();

public:
	void Render() override;
	void Update() override;


};

