#pragma once
#include "Define.h"
#include "Transform.h"
enum class ObjectType
{
	NONE,
	MONSTER,
	PLAYER,
	UI,

	END
};



class GameObject
{
public:
	GameObject();
	virtual ~GameObject();


	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void OnCollision(GameObject* _other) {};
	virtual void Die();

	void SetPosition(float _x, float _y);
	

	D3DXVECTOR3 position{ 0.f,0.f,0.f };
	D3DXVECTOR3 direction{ 1.f,0.f,0.f };
	D3DXVECTOR3 rotation{ 0.f,0.f,0.f };
	D3DXVECTOR3 scale{ 1.f,1.f,1.f };
	
	ObjectType type = ObjectType::NONE;
	int uid = 0;
	bool isDead = false;
	bool isEnable = true;
	bool isVisible = true;
	bool jumpFlag = false;
};