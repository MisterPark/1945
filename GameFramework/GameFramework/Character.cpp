#include "pch.h"
#include "Character.h"
#include "Bullet.h"

void Character::Update()
{
	
}

void Character::Render()
{
}

bool Character::isCollided(const GameObject* _target)
{


	return false;
}

RECT Character::GetCollisionArea()
{
	RECT rc;
	rc.left = simpleCollider.left + transform.position.x;
	rc.right = simpleCollider.right + transform.position.x;
	rc.top = simpleCollider.top + transform.position.y;
	rc.bottom = simpleCollider.bottom + transform.position.y;
	return rc;
}

void Character::SetColliderSize(LONG left, LONG top, LONG right, LONG bottom)
{
	simpleCollider.left = left;
	simpleCollider.top = top;
	simpleCollider.right = right;
	simpleCollider.bottom = bottom;
}

void Character::PushOut(Character* target, float _force)
{


}

void Character::Shot(GameObject* target)
{
	if (target == nullptr) return;

	D3DXVECTOR3 dir = target->transform.position - transform.position;
	D3DXVec3Normalize(&dir, &dir);
	float rad = atan2f(dir.y, dir.x);

	Character* b = (Character*)ObjectManager::CreateObject(ObjectType::BULLET);
	b->transform.scale = { 5.f,5.f,0.f };
	b->simpleCollider = { -5,-5,5,5 };
	b->transform.position = this->transform.position;
	b->radian = rad;
	b->speed = 300.f;
	b->isAlliance = false;
	
}

void Character::Shot(GameObject* target, D3DXVECTOR3 pos)
{
	if (target == nullptr) return;

	D3DXVECTOR3 dir = target->transform.position - pos;
	D3DXVec3Normalize(&dir, &dir);
	float rad = atan2f(dir.y, dir.x);

	Character* b = (Character*)ObjectManager::CreateObject(ObjectType::BULLET);
	b->transform.scale = { 5.f,5.f,0.f };
	b->simpleCollider = { -5,-5,5,5 };
	b->transform.position = pos;
	b->radian = rad;
	b->speed = 300.f;
	b->isAlliance = false;
}

void Character::MultiShot(GameObject* target, int count)
{
	if (target == nullptr) return;

	D3DXVECTOR3 dir = target->transform.position - transform.position;
	D3DXVec3Normalize(&dir, &dir);
	float rad = atan2f(dir.y, dir.x);

	int s = count / 2 * -1;
	int e = count / 2 + 1;
	for (int i = s; i < e; i++)
	{
		Character* b = (Character*)ObjectManager::CreateObject(ObjectType::BULLET);
		b->transform.scale = { 5.f,5.f,0.f };
		b->simpleCollider = { -5,-5,5,5 };
		b->transform.position = this->transform.position;
		b->radian = rad + D3DXToRadian(i * 15);
		b->speed = 300.f;
		b->isAlliance = false;
	}
}

void Character::MultiShot(GameObject* target, D3DXVECTOR3 pos, int count)
{
	if (target == nullptr) return;

	D3DXVECTOR3 dir = target->transform.position - pos;
	D3DXVec3Normalize(&dir, &dir);
	float rad = atan2f(dir.y, dir.x);

	int s = count / 2 * -1;
	int e = count / 2 + 1;
	for (int i = s; i < e; i++)
	{
		Character* b = (Character*)ObjectManager::CreateObject(ObjectType::BULLET);
		b->transform.scale = { 5.f,5.f,0.f };
		b->simpleCollider = { -5,-5,5,5 };
		b->transform.position = pos;
		b->radian = rad + D3DXToRadian(i * 15);
		b->speed = 300.f;
		b->isAlliance = false;
	}
}

void Character::MultiShotRev(GameObject* target, D3DXVECTOR3 pos, int count, bool reverse)
{
	if (target == nullptr) return;

	D3DXVECTOR3 dir = target->transform.position - pos;
	D3DXVec3Normalize(&dir, &dir);
	float rad = atan2f(dir.y, dir.x);

	int s = count / 2 * -1;
	int e = count / 2 + 1;
	for (int i = s; i < e; i++)
	{
		Bullet* b = (Bullet*)ObjectManager::CreateObject(ObjectType::REV_BULLET);
		b->transform.scale = { 5.f,5.f,0.f };
		b->simpleCollider = { -5,-5,5,5 };
		b->transform.position = pos;
		b->radian = rad + D3DXToRadian(i * 15);
		b->speed = 300.f;
		b->isAlliance = false;
		b->isReversing = reverse;
	}
}



