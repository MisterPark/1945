#include "pch.h"
#include "MPlane.h"


MPlane::MPlane()
{
	scale.x = 35;
	scale.y = 35;
	speed = 200.f;
	SecondCount = 0.f;
}

MPlane::~MPlane()
{
}

void MPlane::Update()
{
	++count;
	
	if (count<=100&&SecondCount==0)
	{
		position.x += forceX * speed * TimeManager::DeltaTime();
		if (count == 100)
		{
			
			speed = -50.f;
			count = 0;
			++SecondCount;
		}
	}
	else if (count <= 100 && SecondCount >= 1 &&SecondCount<6)
	{
		position.x += forceX * speed * TimeManager::DeltaTime();
		if (count == 100)
		{
			forceX *= -1.f;
			count = 0;
			++SecondCount;
		}
	}
	else
	{
		speed = 200.f;
		position.x += forceX * speed * TimeManager::DeltaTime();
		position.y += speed * TimeManager::DeltaTime();
	}
}



void MPlane::Render()
{
	RenderManager::DrawRect(position, rotation, scale);

}