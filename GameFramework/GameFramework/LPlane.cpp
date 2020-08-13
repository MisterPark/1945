#include "pch.h"
#include "LPlane.h"


LPlane::LPlane()
{
	scale.x = 50;
	scale.y = 50;
	speed = 100.f;
	
}

LPlane::~LPlane()
{
}

void LPlane::Update()
{
	if (SecondCount < 3)
	{
		if (position.y < 200)
		{
			position.y += speed * TimeManager::DeltaTime();
		}
		if (position.y > 200)
		{
			if (count == 0)
			{
				speed = 4.f;
			}
			++count;

			if (count > 0)
			{
				position.x -= speed * TimeManager::DeltaTime();
			}
		}

		if (count > 150)
		{
			count = 1;
			speed *= -1.f;
			++SecondCount;
		}
	}
	else
	{
		speed = 200.f;
		position.x += speed * TimeManager::DeltaTime();
		position.y += speed * TimeManager::DeltaTime();
	}
}



void LPlane::Render()
{
	RenderManager::DrawRect(position, rotation, scale);

}