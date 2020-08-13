#include "pch.h"
#include "Player.h"

Player::Player()
{
	transform.position.x = 400;
	transform.position.y = 500;
	transform.scale.x = 20;
	transform.scale.y = 20;
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
	RECT rc = {};
	rc.left = transform.position.x - transform.scale.x;
	rc.top = transform.position.y - transform.scale.y;
	rc.right = transform.position.x + transform.scale.x;
	rc.bottom = transform.position.y + transform.scale.y;
	
	// x * cos@ - y*sin@ , x*sin@ + y * cos@


	// Æ÷½Å
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hwnd, &pt);
	D3DXVECTOR3 posinDirection = { float(pt.x),float(pt.y),0.f };
	posinDirection -= transform.position;
	D3DXVec3Normalize(&posinDirection, &posinDirection);
	posinDirection *= posinLength;
	posinDirection += transform.position;
	
	RenderManager::DrawRect(transform.position, transform.rotation, transform.scale);
	//RenderManager::DrawRect(rc.left, rc.top, rc.right, rc.bottom);
	RenderManager::DrawLine(transform.position.x, transform.position.y, posinDirection.x, posinDirection.y);
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
	}
}
