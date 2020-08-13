#include "pch.h"
#include "Boss.h"


Boss::Boss()
{
	transform.scale.x = 1;
	transform.scale.y = 1;
	speed = 100.f;
	yspeed = 100.f;
	leftarm.scale = { 0.25f,0.5f,0.f };
	leftarm.rotation = { 0.f,0.f,0.f };
	rightarm.scale = { 0.25f,0.5f,0.f };
	rightarm.rotation = { 0.f,0.f,0.f };
}

Boss::~Boss()
{
}

void Boss::Update()
{
	
	if (SecondCount == 0)
	{
		if (transform.scale.x < 100)
		{
			leftarm.position = { transform.position.x - 200,transform.position.y + 100,0.f };
			rightarm.position = { transform.position.x + 200,transform.position.y + 100,0.f };
			transform.position.y += speed * TimeManager::DeltaTime();
			transform.rotation.z += speed;
			++transform.scale.x;
			++transform.scale.y;
			leftarm.scale.x += 0.25;
			leftarm.scale.y += 0.25;
			rightarm.scale.x += 0.25;
			rightarm.scale.y += 0.25;
		}
		else
		{
			++SecondCount;
		}
	}
	else
	{
		if (transform.position.x < 250)
			speed *= -1.f;
		else if (transform.position.x > 550)
			speed *= -1.f;

		if (transform.position.y < 100)
		{
			yspeed *= -1.f;
		}
		else if (transform.position.y > 300)
		{
			yspeed *= -1.f;
		}
		transform.position.x -= speed * TimeManager::DeltaTime();
		transform.position.y -= yspeed * TimeManager::DeltaTime();
		leftarm.position.x -= speed * TimeManager::DeltaTime();
		rightarm.position.x -= speed * TimeManager::DeltaTime();
		leftarm.position.y -= yspeed * TimeManager::DeltaTime();
		rightarm.position.y -= yspeed * TimeManager::DeltaTime();
		if (SecondCount == 1)
		{

			++count;

			if (int(count) % 50 == 0)
			{
				transform.rotation.z += speed;
			}
			if (count > 100)
			{
				++SecondCount;
				yspeed = 200.f;
				speed = 200.f;
				count = 0;
			}
		}
	}

	if (SecondCount == 2)
	{
		++count;
		if (int(count) % 12 == 0)
		{
			transform.rotation.z += speed;
		}
		if (count > 100)
		{
			++SecondCount;
			yspeed = 300.f;
			speed = 300.f;
			count = 0;
		}
	}
	if (SecondCount == 3)
	{

			transform.rotation.z += speed;

	}
}



void Boss::Render()
{

	if (SecondCount == 1)
	{
		
	}

	if (SecondCount >= 2)
	{
		/*RenderManager::DrawRect(leftarm.position, leftarm.rotation, leftarm.scale);*/
				//´«
		RenderManager::DrawRect(D3DXVECTOR3{ transform.position.x - 50 ,transform.position.y - 30,0.f }, D3DXVECTOR3{ 0.f ,0.f,0.f }, transform.scale * 0.1);
		RenderManager::DrawRect(D3DXVECTOR3{ transform.position.x - 40 ,transform.position.y - 30,0.f }, D3DXVECTOR3{ 0.f ,0.f,0.f }, transform.scale * 0.1);
		RenderManager::DrawRect(D3DXVECTOR3{ transform.position.x + 50 ,transform.position.y - 30,0.f }, D3DXVECTOR3{ 0.f ,0.f,0.f }, transform.scale * 0.1);
		RenderManager::DrawRect(D3DXVECTOR3{ transform.position.x + 40 ,transform.position.y - 30,0.f }, D3DXVECTOR3{ 0.f ,0.f,0.f }, transform.scale * 0.1);
	}
	if (SecondCount == 3)
	{



		//ÀÔ
		RenderManager::DrawRect(D3DXVECTOR3{ transform.position.x - 10 ,transform.position.y+10,0.f }, D3DXVECTOR3{ 0.f ,0.f,0.f }, transform.scale * 0.1);
		RenderManager::DrawRect(D3DXVECTOR3{ transform.position.x - 20 ,transform.position.y+10,0.f }, D3DXVECTOR3{ 0.f ,0.f,0.f }, transform.scale * 0.1);
		
		RenderManager::DrawRect(D3DXVECTOR3{ transform.position.x + 10 ,transform.position.y + 10,0.f }, D3DXVECTOR3{ 0.f ,0.f,0.f }, transform.scale * 0.1);
		RenderManager::DrawRect(D3DXVECTOR3{ transform.position.x + 20 ,transform.position.y + 10,0.f }, D3DXVECTOR3{ 0.f ,0.f,0.f }, transform.scale * 0.1);
		

		
		RenderManager::DrawRect(D3DXVECTOR3{ transform.position.x - 30 ,transform.position.y+20,0.f }, D3DXVECTOR3{ 0.f ,0.f,0.f }, transform.scale * 0.1);
		RenderManager::DrawRect(D3DXVECTOR3{ transform.position.x - 20 ,transform.position.y+20,0.f }, D3DXVECTOR3{ 0.f ,0.f,0.f }, transform.scale * 0.1);
		
		RenderManager::DrawRect(D3DXVECTOR3{ transform.position.x + 30 ,transform.position.y + 20,0.f }, D3DXVECTOR3{ 0.f ,0.f,0.f }, transform.scale * 0.1);
		RenderManager::DrawRect(D3DXVECTOR3{ transform.position.x + 20 ,transform.position.y + 20,0.f }, D3DXVECTOR3{ 0.f ,0.f,0.f }, transform.scale * 0.1);
	}

	if (SecondCount <= 3)
	{
		RenderManager::DrawRect(leftarm.position, leftarm.rotation, leftarm.scale);
		RenderManager::DrawRect(rightarm.position, rightarm.rotation, rightarm.scale);
		RenderManager::DrawRect(transform.position, transform.rotation, transform.scale);
		RenderManager::DrawRect(transform.position, -transform.rotation, transform.scale * 0.9);
		RenderManager::DrawRect(transform.position, transform.rotation, transform.scale * 0.8);
	}
	if (SecondCount <= 2)
	{

		RenderManager::DrawRect(transform.position, -transform.rotation, transform.scale * 0.7);
		RenderManager::DrawRect(transform.position, transform.rotation, transform.scale * 0.6);
		RenderManager::DrawRect(transform.position, -transform.rotation, transform.scale * 0.5);
		RenderManager::DrawRect(transform.position, transform.rotation, transform.scale * 0.4);
		
	}
	if (SecondCount <= 1)
	{
		
		RenderManager::DrawRect(transform.position, -transform.rotation, transform.scale * 0.3);
		RenderManager::DrawRect(transform.position, transform.rotation, transform.scale * 0.2);
		RenderManager::DrawRect(transform.position, -transform.rotation, transform.scale * 0.1);
		
	}
	
}