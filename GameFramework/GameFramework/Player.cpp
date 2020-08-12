#include "pch.h"
#include "Player.h"

Player::Player()
{
	position.x = 100;
	position.y = 100;
	scale.x = 20;
	scale.y = 20;
	speed = 100.f;
}

Player::~Player()
{
}

void Player::Update()
{
	if (InputManager::GetKey(VK_UP))
	{
		position.y -= speed * TimeManager::DeltaTime();
	}
	else if (InputManager::GetKey(VK_DOWN))
	{
		position.y += speed * TimeManager::DeltaTime();
	}

	if (InputManager::GetKey(VK_LEFT))
	{
		position.x -= speed * TimeManager::DeltaTime();
	}
	else if (InputManager::GetKey(VK_RIGHT))
	{
		position.x += speed * TimeManager::DeltaTime();
	}

	if (InputManager::GetKeyDown(VK_LBUTTON))
	{
		Character* b = (Character*)ObjectManager::CreateObject(ObjectType::BULLET);
		b->position = this->position;

		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(g_hwnd, &pt);
		D3DXVECTOR3 targetPos{ 0.f,0.f,0.f };
		targetPos.x = pt.x;
		targetPos.y = pt.y;
		targetPos -= position;
		D3DXVec3Normalize(&targetPos, &targetPos);
		b->radian = atan2f(targetPos.y, targetPos.x);
		b->speed = 100.f;

	}


	
}

void Player::Render()
{
	RECT rc = {};
	rc.left = position.x - scale.x;
	rc.top = position.y - scale.y;
	rc.right = position.x + scale.x;
	rc.bottom = position.y + scale.y;
	
	// x * cos@ - y*sin@ , x*sin@ + y * cos@


	// Æ÷½Å
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hwnd, &pt);
	D3DXVECTOR3 posinDirection = { float(pt.x),float(pt.y),0.f };
	posinDirection -= position;
	D3DXVec3Normalize(&posinDirection, &posinDirection);
	posinDirection *= posinLength;
	posinDirection += position;
	
	RenderManager::DrawRect(position, rotation, scale);
	//RenderManager::DrawRect(rc.left, rc.top, rc.right, rc.bottom);
	RenderManager::DrawLine(position.x, position.y, posinDirection.x, posinDirection.y);
}

void Player::OnCollision(GameObject * _other)
{
	if (_other->type == ObjectType::MONSTER)
	{

	}
}
