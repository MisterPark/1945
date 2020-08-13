#include "pch.h"
#include "Player.h"

Player::Player()
{
	transform.position.x = dfWINDOW_WIDTH / 2;
	transform.position.y = dfWINDOW_HEIGHT - 100;
	transform.scale.x = 20;
	transform.scale.y = 20;
	simpleCollider = { -20,-20,20,20 };
	speed = 300.f;
}

Player::~Player()
{
}

void Player::Update()
{
	D3DXVECTOR3 oldPos = transform.position;

	if (InputManager::GetKey(VK_UP))
	{
		transform.position.y -= speed * TimeManager::DeltaTime();
	}
	else if (InputManager::GetKey(VK_DOWN))
	{
		transform.position.y += speed * TimeManager::DeltaTime();
	}

	if (InputManager::GetKey(VK_LEFT))
	{
		transform.position.x -= speed * TimeManager::DeltaTime();
	}
	else if (InputManager::GetKey(VK_RIGHT))
	{
		transform.position.x += speed * TimeManager::DeltaTime();
	}

	if (InputManager::GetKeyDown(VK_LBUTTON))
	{
		Character* b = (Character*)ObjectManager::CreateObject(ObjectType::BULLET);
		b->transform.position = this->transform.position;

		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(g_hwnd, &pt);
		D3DXVECTOR3 targetPos{ 0.f,0.f,0.f };
		targetPos.x = pt.x;
		targetPos.y = pt.y;
		targetPos -= transform.position;
		D3DXVec3Normalize(&targetPos, &targetPos);
		b->radian = atan2f(targetPos.y, targetPos.x);
		b->speed = 300.f;

	}

	if (InputManager::GetKey(VK_SPACE))
	{
		Attack();
	}


	attackTick += TimeManager::DeltaTime();

	if (transform.position.x < 0 || transform.position.x > dfWINDOW_WIDTH)
	{
		transform.position.x = oldPos.x;
	}

	if(transform.position.y <0 || transform.position.y > dfWINDOW_HEIGHT)
	{
		transform.position.y = oldPos.y;
	}
}

void Player::Render()
{
	RenderManager::DrawRect(transform.position, transform.rotation, transform.scale);
}

void Player::OnCollision(GameObject * _other)
{
	if (_other->type == ObjectType::STANK)
	{

	}
}

void Player::Attack()
{
	if (attackTick > attackDelay)
	{
		attackTick = 0.f;
		Character* b = (Character*)ObjectManager::CreateObject(ObjectType::BULLET);
		b->transform.scale = { 5.f,30.f,0.f };
		b->transform.position = this->transform.position;
		b->radian = D3DXToRadian(270.f);
		b->speed = 700.f;
		b->simpleCollider = { -5,-30,5,30 };
	}
}
