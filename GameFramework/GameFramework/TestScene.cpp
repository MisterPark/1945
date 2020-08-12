#include "pch.h"
#include "TestScene.h"
#include "TimeManager.h"
#include "MPlane.h"
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

	//MPLAIN
	if (1 < tick)
	{
		if (iMonsterCount == 0)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::MPLANE);
			pMonster->position = { -100.f,200.f,0.f };
			pMonster->destination = { 0.f,0.f,0.f };
			dynamic_cast<MPlane*>(pMonster)->Set_forceX(1.f);
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::MPLANE);
			pMonster->position = { dfWINDOW_WIDTH+100.f,200.f,0.f };
			pMonster->destination = { 500.f,0.f,0.f };
			dynamic_cast<MPlane*>(pMonster)->Set_forceX(-1.f);
			listObject.push_back(pMonster);

			++iMonsterCount;
		}
	}
////LPLAIN
//if (1 < tick)
//{
//	if (iMonsterCount == 0)
//	{
//		GameObject* pMonster = ObjectManager::CreateObject(ObjectType::LPLANE);
//		pMonster->position = { 500.f,-200,0 };
//		pMonster->destination = { 500.f,0.f,0 };
//		listObject.push_back(pMonster);
//
//		++iMonsterCount;
//	}
//}
	///*SPLANE_2*/
	//if (1 < tick)
	//{
	//	if (iMonsterCount == 0)
	//	{
	//		GameObject* pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
	//		pMonster->position = { 250.f,-50,0 };
	//		pMonster->destination = { dfWINDOW_WIDTH + 50,0.f,0 };
	//		listObject.push_back(pMonster);

	//		pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
	//		pMonster->position = { 350.f,-80,0 };
	//		pMonster->destination = { -50.f,0.f,0 };
	//		listObject.push_back(pMonster);

	//		pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
	//		pMonster->position = { 450.f,-80,0 };
	//		pMonster->destination = { dfWINDOW_WIDTH + 50,0.f,0 };
	//		listObject.push_back(pMonster);

	//		pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
	//		pMonster->position = { 550.f,-50,0 };
	//		pMonster->destination = { -50.f,0.f,0 };
	//		listObject.push_back(pMonster);

	//		++iMonsterCount;
	//	}
	//}

	//SPLANE_1
	//if (1 < tick)
	//{
	//	if (iMonsterCount == 0)
	//	{
	//		GameObject* pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
	//		pMonster->position = { 250.f,-50,0 };
	//		listObject.push_back(pMonster);

	//		pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
	//		pMonster->position = { 350.f,-200,0 };
	//		listObject.push_back(pMonster);

	//		pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
	//		pMonster->position = { 450.f,-350,0 };
	//		listObject.push_back(pMonster);

	//		pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
	//		pMonster->position = { 550.f,-500,0 };
	//		listObject.push_back(pMonster);

	//		++iMonsterCount;
	//	}
	//}

	//if (1 < tick)
	//{
	//	if (iMonsterCount == 0)
	//	{
	//		GameObject* pMonster = ObjectManager::CreateObject(ObjectType::STANK);
	//		pMonster->position = { 400.f,-50,0 };
	//		pMonster->destination = { 450.f,0.f,0 };
	//		listObject.push_back(pMonster);
	//		++iMonsterCount;
	//	}
	//}
	//if (5 < tick)
	//{
	//	if (iMonsterCount == 1)
	//	{
	//		
	//			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::STANK);
	//			pMonster->position = { 600.f,200,0 };
	//			pMonster->destination = { 500.f,0.f,0 };
	//			listObject.push_back(pMonster);
	//		
	//		++iMonsterCount;
	//	}
	//}
	//if (8 < tick)
	//{
	//	if (iMonsterCount == 2)
	//	{
	//		GameObject* pMonster = ObjectManager::CreateObject(ObjectType::MTANK);
	//		pMonster->position = { 400.f,-50,0 };
	//		pMonster->destination = { 400.f,-50,0 };
	//		listObject.push_back(pMonster);

	//		pMonster = ObjectManager::CreateObject(ObjectType::MTANK);
	//		pMonster->position = { 500.f,-150,0 };
	//		pMonster->destination = { 500.f,0,0 };
	//		listObject.push_back(pMonster);
	//		++iMonsterCount;
	//	}
	//}
	//if (10 < tick)
	//{
	//	if (iMonsterCount == 3)
	//	{

	//		GameObject* pMonster = ObjectManager::CreateObject(ObjectType::STANK);
	//		pMonster->position = { 600.f,200,0 };
	//		pMonster->destination = { 500.f,0.f,0 };
	//		listObject.push_back(pMonster);

	//		++iMonsterCount;
	//	}
	//}
}
