#include "pch.h"
#include "TestScene.h"

TestScene::TestScene()
{
}

TestScene::~TestScene()
{
}

void TestScene::OnLoaded()
{
	ObjectManager::CreateObject(ObjectType::PLAYER);

	for (int i = 0; i < 10; i++)
	{
		GameObject* m = ObjectManager::CreateObject(ObjectType::MONSTER);
		m->position = { i * 50.f,0,0 };
		listObject.push_back(m);

	}
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
}
