#include "pch.h"
#include "MainGame.h"
#include "TestScene.h"

MainGame* pMainGame = nullptr;

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
}

MainGame * MainGame::GetInstance()
{
	if (pMainGame == nullptr)
	{
		pMainGame = new MainGame();
	}
	return pMainGame;
}

void MainGame::Initialize()
{
	TimeManager::GetInstance();
	TimeManager::SetFrame(dfFPS);

	InputManager::GetInstance();
	ObjectManager::GetInstance();
	RenderManager::GetInstance();
	SceneManager::GetInstance();
	CollisionManager::GetInstance();
	SceneManager::LoadScene<TestScene>();
}

void MainGame::Release()
{
	SceneManager::Release();
	TimeManager::Release();
	ObjectManager::Release();
	RenderManager::Release();
	InputManager::Release();
	CollisionManager::Release();
}

void MainGame::Run()
{

	InputManager::Update();
	if (pMainGame->isPause == false)
	{
		ObjectManager::Update();
	}
	ObjectManager::LateUpdate();
	CollisionManager::Update();
	if (!TimeManager::SkipFrame())
	{
		RenderManager::Clear();
		ObjectManager::Render();
		RenderManager::Present();
	}
	SceneManager::Update();
}

void MainGame::Pause()
{
	pMainGame->isPause = true;
}

void MainGame::Resume()
{
	pMainGame->isPause = false;
}

void MainGame::Shutdown()
{
	PostQuitMessage(0);
}
