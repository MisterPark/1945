#pragma once
#include "IScene.h"
class TestScene :
	public IScene
{
public:
	TestScene();
	virtual ~TestScene();
	// IScene��(��) ���� ��ӵ�
	virtual void OnLoaded() override;
	virtual void OnUnloaded() override;
	virtual void Update() override;
};

