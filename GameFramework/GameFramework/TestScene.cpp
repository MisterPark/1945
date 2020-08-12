#include "pch.h"
#include "TestScene.h"
#include "TimeManager.h"

TestScene::TestScene()
{
}

TestScene::~TestScene()
{
}

void TestScene::OnLoaded()
{
	ObjectManager::CreateObject(ObjectType::PLAYER);


}

void TestScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void TestScene::Update()
{
	
	if (InputManager::GetKeyDown(VK_ESCAPE))
	{
		MainGame::Shutdown();
	}

	MonsterCreate();
}

void TestScene::MonsterCreate()
{
	tick += TimeManager::DeltaTime();
	if (1 < tick)
	{
		if (iMonsterCount == 0)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->position = { 400.f,-50,0 };
			pMonster->direction = { 450.f,150.f,0 };
			listObject.push_back(pMonster);
			++iMonsterCount;
		}
	}
	if (5 < tick)
	{
		if (iMonsterCount == 1)
		{
			
				GameObject* pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
				pMonster->position = { 600.f,200,0 };
				pMonster->direction = { 500.f,150.f,0 };
				listObject.push_back(pMonster);
			
			++iMonsterCount;
		}
	}
	if (8 < tick)
	{
		if (iMonsterCount == 2)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::MTANK);
			pMonster->position = { 600.f,200,0 };
			pMonster->direction = { 500.f,150.f,0 };
			listObject.push_back(pMonster);
			++iMonsterCount;
		}
	}
}
