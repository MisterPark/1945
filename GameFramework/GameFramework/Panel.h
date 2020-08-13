#pragma once
#include "UI.h"
class Panel :
	public UI
{
public:
	Panel();
	virtual ~Panel();

	virtual void Update() override;
	virtual void Render() override;
};

