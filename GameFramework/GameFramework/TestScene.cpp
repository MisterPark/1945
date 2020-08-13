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
	GameObject* leftpanel = ObjectManager::CreateObject(ObjectType::PANEL);
	leftpanel->transform.position = { 60,300,0 };
	leftpanel->transform.scale = { 60,300,0 };

	GameObject* rightpanel = ObjectManager::CreateObject(ObjectType::PANEL);
	rightpanel->transform.position = { dfWINDOW_WIDTH - 60,300,0 };
	rightpanel->transform.scale = { 60,300,0 };
	ObjectManager::CreateObject(ObjectType::PLAYER);


	//ObjectManager::CreateObject(ObjectType::TEST_MONSTER);
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


	//STANK
	if (1 < tick)
	{
		if (iMonsterCount == 0)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 400.f,-50,0 };
			pMonster->destination = { 550.f,0.f,0 };
			listObject.push_back(pMonster);
			++iMonsterCount;
		}
	}

	//SPLANE_1
	if (2 < tick)
	{
		if (iPlaneCount == 0)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 250.f,-50,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 350.f,-200,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 450.f,-350,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 550.f,-500,0 };
			listObject.push_back(pMonster);

			++iPlaneCount;
		}
	}
	if (3 < tick)
	{
		if (iMonsterCount == 1)
		{

			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 800.f,50,0 };
			pMonster->destination = { 650.f,0.f,0 };
			listObject.push_back(pMonster);

			++iMonsterCount;
		}
	}
	if (4 < tick)
	{
		if (iMonsterCount == 2)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::MTANK);
			pMonster->transform.position = { 300.f,-50,0 };

			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::MTANK);
			pMonster->transform.position = { 400.f,-150,0 };

			listObject.push_back(pMonster);
			++iMonsterCount;
		}
	}
	//SPLANE_2
	if (6 < tick)
	{
		if (iPlaneCount == 1)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 250.f,-50,0 };
			pMonster->destination = { dfWINDOW_WIDTH + 50,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 350.f,-80,0 };
			pMonster->destination = { -50.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 450.f,-80,0 };
			pMonster->destination = { dfWINDOW_WIDTH + 50,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 550.f,-50,0 };
			pMonster->destination = { -50.f,0.f,0 };
			listObject.push_back(pMonster);

			++iPlaneCount;
		}
	}
	if (7 < tick)
	{
		if (iMonsterCount == 3)
		{

			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 600.f,-50.f,0 };
			pMonster->destination = { 500.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 650.f,-50.f,0 };
			pMonster->destination = { 650.f,0.f,0 };
			listObject.push_back(pMonster);

			++iMonsterCount;
		}
	}

	if (9 < tick)
	{
		if (iMonsterCount == 4)
		{

			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 300.f,-50.f,0 };
			pMonster->destination = { 200.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { -50.f,-120.f,0 };
			pMonster->destination = { 250.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::MCANNON);
			pMonster->transform.position = { 650.f,-120.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 350.f,-180.f,0 };
			pMonster->destination = { 350.f,0.f,0 };
			listObject.push_back(pMonster);

			++iMonsterCount;
		}
	}
	//SPLANE_1
	if (9 < tick)
	{
		if (iPlaneCount == 2)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 250.f,-50,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 350.f,-200,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 450.f,-350,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 550.f,-500,0 };
			listObject.push_back(pMonster);

			++iPlaneCount;
		}
	}
	//SPLANE_2
	if (11 < tick)
	{
		if (iPlaneCount == 3)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 250.f,-50,0 };
			pMonster->destination = { dfWINDOW_WIDTH + 50,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 350.f,-80,0 };
			pMonster->destination = { -50.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 450.f,-80,0 };
			pMonster->destination = { dfWINDOW_WIDTH + 50,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 550.f,-50,0 };
			pMonster->destination = { -50.f,0.f,0 };
			listObject.push_back(pMonster);

			++iPlaneCount;
		}
	}

	//SPLANE_2
	if (12 < tick)
	{
		if (iPlaneCount == 4)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 250.f,-50,0 };
			pMonster->destination = { dfWINDOW_WIDTH + 50,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 350.f,-80,0 };
			pMonster->destination = { -50.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 450.f,-80,0 };
			pMonster->destination = { dfWINDOW_WIDTH + 50,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 550.f,-50,0 };
			pMonster->destination = { -50.f,0.f,0 };
			listObject.push_back(pMonster);

			++iPlaneCount;
		}
	}


	if (12 < tick)
	{
		if (iMonsterCount == 5)
		{

			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 850.f,-50.f,0 };
			pMonster->destination = { 600.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 750.f,-120.f,0 };
			pMonster->destination = { 630.f,0.f,0 };
			listObject.push_back(pMonster);


			++iMonsterCount;
		}
	}
	//SPLANE_1
	if (13.5 < tick)
	{
		if (iPlaneCount == 5)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 250.f,-50,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 350.f,-200,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 450.f,-350,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 550.f,-500,0 };
			listObject.push_back(pMonster);

			++iPlaneCount;
		}
	}
	if (14 < tick)
	{
		if (iMonsterCount == 6)
		{

			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::MTANK);
			pMonster->transform.position = { 400.f,-50.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::MTANK);
			pMonster->transform.position = { 320.f,-120.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::MCANNON);
			pMonster->transform.position = { 200.f,-100.f,0 };
			listObject.push_back(pMonster);

			++iMonsterCount;
		}
	}

	if (16 < tick)
	{
		if (iMonsterCount == 7)
		{

			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 850.f,-50.f,0 };
			pMonster->destination = { 600.f,0.f,0 };
			listObject.push_back(pMonster);



			++iMonsterCount;
		}
	}

	if (17 < tick)
	{
		if (iMonsterCount == 8)
		{

			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 150.f,-50.f,0 };
			pMonster->destination = { 150.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 150.f,-150.f,0 };
			pMonster->destination = { 150.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 500.f,-200.f,0 };
			pMonster->destination = { 250.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::MCANNON);
			pMonster->transform.position = { 650.f,-200.f,0 };
			listObject.push_back(pMonster);


			pMonster = ObjectManager::CreateObject(ObjectType::LTANK);
			pMonster->transform.position = { 400.f,-150.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::LTANK);
			pMonster->transform.position = { 500.f,-200.f,0 };
			listObject.push_back(pMonster);


			++iMonsterCount;
		}
	}
	//SPLANE_1
	if (21 < tick)
	{
		if (iPlaneCount == 6)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 250.f,-50,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 350.f,-200,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 450.f,-350,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 550.f,-500,0 };
			listObject.push_back(pMonster);

			++iPlaneCount;
		}
	}

	if (22 < tick)
	{
		if (iMonsterCount == 9)
		{

			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 800.f,-50.f,0 };
			pMonster->destination = { 670.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 650.f,-110.f,0 };
			pMonster->destination = { 620.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 550.f,-140.f,0 };
			pMonster->destination = { 570.f,0.f,0 };
			listObject.push_back(pMonster);


			pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 200.f,-90.f,0 };
			pMonster->destination = { 200.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 160.f,-135.f,0 };
			pMonster->destination = { 160.f,0.f,0 };
			listObject.push_back(pMonster);

			++iMonsterCount;
		}
	}
	if (22 < tick)
	{
		if (iMonsterCount == 10)
		{

			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 800.f,-50.f,0 };
			pMonster->destination = { 670.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 650.f,-110.f,0 };
			pMonster->destination = { 620.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 550.f,-140.f,0 };
			pMonster->destination = { 570.f,0.f,0 };
			listObject.push_back(pMonster);


			pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 200.f,-90.f,0 };
			pMonster->destination = { 200.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 160.f,-135.f,0 };
			pMonster->destination = { 160.f,0.f,0 };
			listObject.push_back(pMonster);

			++iMonsterCount;
		}
	}
	//SPLANE_1
	if (25 < tick)
	{
		if (iPlaneCount == 7)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 250.f,-50,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 350.f,-200,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 450.f,-350,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 550.f,-500,0 };
			listObject.push_back(pMonster);

			++iPlaneCount;
		}
	}

	if (25 < tick)
	{
		if (iMonsterCount == 11)
		{

			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 180.f,-50.f,0 };
			pMonster->destination = { 280.f,0.f,0 };
			listObject.push_back(pMonster);


			++iMonsterCount;
		}
	}
	//SPLANE_2
	if (25.5 < tick)
	{
		if (iPlaneCount == 8)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 250.f,-50,0 };
			pMonster->destination = { dfWINDOW_WIDTH + 50,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 350.f,-80,0 };
			pMonster->destination = { -50.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 450.f,-80,0 };
			pMonster->destination = { dfWINDOW_WIDTH + 50,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 550.f,-50,0 };
			pMonster->destination = { -50.f,0.f,0 };
			listObject.push_back(pMonster);

			++iPlaneCount;
		}
	}

	//LPLAIN
	if (33 < tick)
	{
		if (iPlaneCount == 9)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::LPLANE);
			pMonster->transform.position = { 500.f,-200,0 };
			pMonster->destination = { 500.f,300.f,0 };
			listObject.push_back(pMonster);

			++iPlaneCount;
		}
	}


	if (28 < tick)
	{
		if (iMonsterCount == 12)
		{


			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 0.f,-50.f,0 };
			pMonster->destination = { 180.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::STANK);
			pMonster->transform.position = { 0.f,-130.f,0 };
			pMonster->destination = { 200.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::LTANK);
			pMonster->transform.position = { 290.f,-150.f,0 };
			listObject.push_back(pMonster); 

			pMonster = ObjectManager::CreateObject(ObjectType::MCANNON);
			pMonster->transform.position = { 360.f,-360.f,0 };
			listObject.push_back(pMonster);

			++iMonsterCount;
		}
	}
	//SPLANE_1+SPLAN_2
	if (35 < tick)
	{
		if (iPlaneCount == 10)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 250.f,-50,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 350.f,-200,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 450.f,-350,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 550.f,-500,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 250.f,-50,0 };
			pMonster->destination = { dfWINDOW_WIDTH + 50,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 350.f,-80,0 };
			pMonster->destination = { -50.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 450.f,-80,0 };
			pMonster->destination = { dfWINDOW_WIDTH + 50,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 550.f,-50,0 };
			pMonster->destination = { -50.f,0.f,0 };
			listObject.push_back(pMonster);
			++iPlaneCount;
		}
	}

	//LPLAIN
	if (39 < tick)
	{
		if (iPlaneCount == 11)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::LPLANE);
			pMonster->transform.position = { 570.f,-120,0 };
			pMonster->destination = { 500.f,180.f,0 };
			listObject.push_back(pMonster);

			++iPlaneCount;
		}
	}

	//SPLANE_1
	if (45 < tick)
	{
		if (iPlaneCount == 12)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 250.f,-50,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 350.f,-200,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 450.f,-350,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_1);
			pMonster->transform.position = { 550.f,-500,0 };
			listObject.push_back(pMonster);

			++iPlaneCount;
		}
	}
	//MPLAIN
	if (51 < tick)
	{
		if (iPlaneCount == 13)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::MPLANE);
			pMonster->transform.position = { -100.f,200.f,0.f };
			pMonster->destination = { 0.f,0.f,0.f };
			dynamic_cast<MPlane*>(pMonster)->Set_forceX(1.f);
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::MPLANE);
			pMonster->transform.position = { dfWINDOW_WIDTH+100.f,200.f,0.f };
			pMonster->destination = { 500.f,0.f,0.f };
			dynamic_cast<MPlane*>(pMonster)->Set_forceX(-1.f);
			listObject.push_back(pMonster);


			pMonster = ObjectManager::CreateObject(ObjectType::MPLANE);
			pMonster->transform.position = { dfWINDOW_WIDTH,400.f,0.f };
			pMonster->destination = { 500.f,0.f,0.f };
			dynamic_cast<MPlane*>(pMonster)->Set_forceX(-1.f);
			listObject.push_back(pMonster);

			++iPlaneCount;
		}
	}
	//SPLANE_2
	if (55 < tick)
	{
		if (iPlaneCount == 14)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 250.f,-50,0 };
			pMonster->destination = { dfWINDOW_WIDTH + 50,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 350.f,-80,0 };
			pMonster->destination = { -50.f,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 450.f,-80,0 };
			pMonster->destination = { dfWINDOW_WIDTH + 50,0.f,0 };
			listObject.push_back(pMonster);

			pMonster = ObjectManager::CreateObject(ObjectType::SPLANE_2);
			pMonster->transform.position = { 550.f,-50,0 };
			pMonster->destination = { -50.f,0.f,0 };
			listObject.push_back(pMonster);

			++iPlaneCount;
		}
	}


	//STANK
	if (60 < tick)
	{
		if (iPlaneCount == 15)
		{
			GameObject* pMonster = ObjectManager::CreateObject(ObjectType::BOSS);
			pMonster->transform.position = { 400.f,-50,0 };
			pMonster->destination = { 550.f,150.f,0 };
			listObject.push_back(pMonster);
			++iPlaneCount;
		}
	}
}
