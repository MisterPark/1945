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

	void MonsterCreate();
private:
	list<GameObject*> listObject;
	float tick = 0.f;
	float delay = 5.f;
	int iMonsterCount = 0;
	int iPlaneCount = 0;
};

