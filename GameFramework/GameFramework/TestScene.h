#pragma once
#include "IScene.h"
class TestScene :
	public IScene
{
public:
	TestScene();
	virtual ~TestScene();
	// IScene을(를) 통해 상속됨
	virtual void OnLoaded() override;
	virtual void OnUnloaded() override;
	virtual void Update() override;
};

