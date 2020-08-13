#include "pch.h"
#include "Missle.h"
#include "Enemy.h"
 

Missle::Missle()
{
}

Missle::~Missle()
{
}

void Missle::Update()
{
	msTick += TimeManager::DeltaTime();

	transform.position.x = transform.position.x + cosf(radian) * speed * TimeManager::DeltaTime();
	transform.position.y = transform.position.y + sinf(radian) * speed * TimeManager::DeltaTime();

	if (transform.position.x < 0 || transform.position.x > dfWINDOW_WIDTH
		|| transform.position.y < -1000 || transform.position.y > dfWINDOW_HEIGHT + 4000)
	{
		Die();
	}


}

void Missle::Render()
{
	RenderManager::DrawRect(transform.position, transform.rotation, transform.scale);
}

void Missle::OnCollision(GameObject * _other)
{
	
	if (dynamic_cast<Enemy*>(_other) && _other->isAlliance != isAlliance)
	{
		Enemy* E = (Enemy*)_other;

		if (msTick > 0.33f)
		{
			E->hp--;

			msTick = 0.f;
		}

		if (E->hp < 0)
		{
			E->Die();
		}


	}


}
