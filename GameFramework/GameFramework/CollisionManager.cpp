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
	// �߷�
	UpdateGravity();

	// �浹
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

		target->gravityCount += 2;
		float gravityPower = target->gravityCount * dfGRAVITY * TimeManager::DeltaTime();
		target->transform.position.y += gravityPower;
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
	if (_target == nullptr)return false;
	if (_other == nullptr)return false;
	Character* target = dynamic_cast<Character*>(_target);
	if (target == nullptr)return false;
	Character* other = dynamic_cast<Character*>(_other);
	if (other == nullptr)return false;
	RECT targetRect = target->GetCollisionArea();

	RECT otherRect = other->GetCollisionArea();

	if (targetRect.right < otherRect.left) return false;
	if (targetRect.left > otherRect.right) return false;
	if (targetRect.top > otherRect.bottom) return false;
	if (targetRect.bottom < otherRect.top) return false;

	return true;
}
