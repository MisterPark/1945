#include "pch.h"
#include "Missle.h"
 

Missle::Missle()
{
}

Missle::~Missle()
{
}

void Missle::Update()
{

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
}
