#include "pch.h"
#include "CollisionManager.h"
#include "Character.h"

CollisionManager* pCollisionManager = nullptr;

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

CollisionManager* CollisionManager::GetInstance()
{
	if (pCollisionManager == nullptr)
	{
		pCollisionManager = new CollisionManager;
	}

	return pCollisionManager;
}

void CollisionManager::Release()
{
	delete pCollisionManager;
}

void CollisionManager::Update()
{
	// 중력
	UpdateGravity();

	// 충돌
	for (auto src : pCollisionManager->objectList)
	{
		for (auto dest : pCollisionManager->objectList)
		{
			if (src == dest) continue;

			if (CollisionManager::IsCollided(src, dest))
			{
				src->OnCollision(dest);
			}
		}
	}

	

}

void CollisionManager::UpdateGravity()
{
	Character* target = nullptr;
	for (auto iter : pCollisionManager->objectList)
	{
		target = dynamic_cast<Character*>(iter);
		if (target == nullptr) continue;
		if (target->useGravity == false) continue;

		target->gravityCount+=2;
		float gravityPower = target->gravityCount * dfGRAVITY * TimeManager::DeltaTime();
		target->position.y += gravityPower;
	}
}

void CollisionManager::RegisterObject(GameObject* _pObj)
{
	if (FindObject(_pObj))
	{
		return;
	}

	pCollisionManager->objectList.push_back(_pObj);
}

void CollisionManager::DisregisterObject(GameObject* _pObj)
{
	if (FindObject(_pObj))
	{
		pCollisionManager->objectList.remove(_pObj);
	}
}

bool CollisionManager::FindObject(GameObject* _pObj)
{
	if (_pObj == nullptr) return false;
	for (auto iter : pCollisionManager->objectList)
	{
		if (iter != _pObj) continue;

		return true;
	}
	return false;
}

bool CollisionManager::IsCollided(GameObject* _target, GameObject* _other)
{

	return true;
}
