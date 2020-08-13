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
	if (InputManager::GetKey('C'))
	{
		Bomb();
	}


	attackTick += TimeManager::DeltaTime();
	subAttackTick += TimeManager::DeltaTime();
	c1Tick += TimeManager::DeltaTime();
	bombTick += TimeManager::DeltaTime();

	if (transform.position.x < 0 || transform.position.x > dfWINDOW_WIDTH)
	{
		transform.position.x = oldPos.x;
	}

	if (transform.position.y <0 || transform.position.y > dfWINDOW_HEIGHT)
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
		b->speed = 1100.f;
		b->simpleCollider = { -5,-30,5,30 };
	}



	if (subAttackTick > subAttackDelay)  
	{
		Character* c1 = (Character*)ObjectManager::CreateObject(ObjectType::BULLET);
		//크기, 충돌체
		c1->transform.scale = { 5.f,30.f,0.f };
		c1->simpleCollider = { -5,-30,5,30 };
		
		//생성위치 
		c1->transform.position = this->transform.position;
		c1->transform.position.y += 25.f;	//기체 살짝 후방으로 재조정
		c1->radian = D3DXToRadian(270.f);	//12시방향

		c1->speed =- 100.f;

		while (c1->speed < 450)
		{
			c1->speed += c1Tick * TimeManager::DeltaTime()/10;
		}
		c1Tick = 0;
		subAttackTick = 0.f;
	}


	 
}

void Player::Bomb()
{

	if (bombTick > bombDelay)
	{

		Character* mss = (Character*)ObjectManager::CreateObject(ObjectType::MISSILE);
		
		mss->missile = true;

		//크기, 충돌체
		mss->transform.scale = { 50.f,200.f,0.f };
		mss->simpleCollider = { -55,-200,55,200 };

		//생성위치 
		mss->transform.position = this->transform.position;
		mss->transform.position.y = 800;	//기체 후방
		mss->radian = D3DXToRadian(270.f);	//12시방향

		mss->speed = 180.f;
 
		bombTick = 0;
	}
}
