#include "pch.h"
#include "ObjectManager.h"
#include "Character.h"
#include "UI.h"
#include "Player.h"
#include "STank.h"
#include "MTank.h"
#include "LTank.h"
#include "SPlane_1.h"
#include "SPlane_2.h"
#include "SPlane_3.h"
#include "MPlane.h"
#include "LPlane.h"
#include "MCannon.h"
#include "Boss.h"
#include "Bullet.h"
#include "TestMonster.h"
#include "Panel.h"

ObjectManager* pObjectManager = nullptr;
int lastUid = 0;

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{

}

ObjectManager * ObjectManager::GetInstance()
{
	if (pObjectManager == nullptr)
	{
		pObjectManager = new ObjectManager;
	}
	return pObjectManager;
}

GameObject * ObjectManager::CreateObject(ObjectType _type)
{
	GameObject* pObj = nullptr;
	switch (_type)
	{
	case ObjectType::TEST_MONSTER:
		pObj = new TestMonster;
		break;
	case ObjectType::BULLET:
		pObj = pObjectManager->bulletPool.Alloc();
		break;
	case ObjectType::STANK:
		pObj = new STank;
		break;
	case ObjectType::MTANK:
		pObj = new MTank;
		break;
	case ObjectType::LTANK:
		pObj = new LTank;
		break;
	case ObjectType::SPLANE_1:
		pObj = new SPlane_1;
		break;
	case ObjectType::SPLANE_2:
		pObj = new SPlane_2;
		break;
	case ObjectType::SPLANE_3:
		pObj = new SPlane_3;
		break;

	case ObjectType::MPLANE:
		pObj = new MPlane;
		break;
	case ObjectType::LPLANE:
		pObj = new LPlane;
		break;
	case ObjectType::MCANNON:
		pObj = new MCannon;
		break;
	case ObjectType::BOSS:
		pObj = new Boss;
		break;
	case ObjectType::PLAYER:
		pObj = new Player;
		break;
	case ObjectType::UI:
		pObj = new UI();
		break;
	case ObjectType::PANEL:
		pObj = new Panel;
		break;
	default:
		return nullptr;
	}

	pObj->type = _type;
	pObj->uid = ++lastUid;
	pObjectManager->objectTable[(int)_type].push_back(pObj);

	if (dynamic_cast<Character*>(pObj) != nullptr)
	{
		CollisionManager::RegisterObject(pObj);
	}

	return pObj;
}

bool ObjectManager::DeleteObject(GameObject * _target)
{
	auto& objList = pObjectManager->objectTable[(int)_target->type];
	
	auto target = find(objList.begin(), objList.end(), _target);
	if (target != objList.end())
	{
		_target->Die();
		return true;
	}
	return false;
}

void ObjectManager::DestroyAll()
{
	auto& objTable = pObjectManager->objectTable;
	for (auto&objList  : objTable)
	{
		for (auto& iter : objList)
		{
			iter->Die();
		}
	}
}

void ObjectManager::DestroyAll(ObjectType _type)
{
	auto& objList = pObjectManager->objectTable[(int)_type];
	for (auto iter : objList)
	{
		iter->Die();
	}
}

GameObject* ObjectManager::FindObject(ObjectType _type)
{
	auto& objList = pObjectManager->objectTable[(int)_type];
	if (objList.size() == 0) return nullptr;

	return *objList.begin();
}

void ObjectManager::Release()
{
	delete pObjectManager;
	pObjectManager = nullptr;
}

void ObjectManager::Update()
{
	auto& objTable = pObjectManager->objectTable;
	for (auto& objList : objTable)
	{
		for (auto& iter : objList)
		{
			iter->Update();
		}
	}
	
}

void ObjectManager::LateUpdate()
{
	GameObject* target = nullptr;

	auto& objTable = pObjectManager->objectTable;
	for (auto& objList : objTable)
	{
			auto iter = objList.begin();
			auto end = objList.end();
			for (; iter != end;)
			{
				target = *iter;
				if (target->isDead)
				{
					iter = objList.erase(iter);


					if (dynamic_cast<Character*>(target) != nullptr)
					{
						CollisionManager::DisregisterObject(target);
					}

					if (dynamic_cast<Bullet*>(target) != nullptr)
					{
						pObjectManager->bulletPool.Free((Bullet*)target);
					}
					else
					{
						delete target;
					}
					
				}
				else
				{
					++iter;
				}
			}
	}

	
	
	
}

void ObjectManager::Render()
{
	auto& objTable = pObjectManager->objectTable;
	for (auto& objList : objTable)
	{
		for (auto& iter : objList)
		{
			iter->Render();
		}
	}

	// 디버그용
	TimeManager::RenderFPS();
}
