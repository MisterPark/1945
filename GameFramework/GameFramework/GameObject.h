#pragma once
#include "Define.h"
#include "Transform.h"
enum class ObjectType
{
	NONE,
	TEST_MONSTER,
	BULLET,
	STANK,
	MTANK,
	LTANK,
	SPLANE_1,
	SPLANE_2,
	SPLANE_3,
	MPLANE,
	LPLANE,
	MCANNON,
	BOSS,
	PLAYER,
	UI,
	PANEL,

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
	
	void SetDirection(float _x, float _y);

public:
	D3DXVECTOR3 position{ 0.f,0.f,0.f };
	D3DXVECTOR3 rotation{ 0.f,0.f,0.f };
	D3DXVECTOR3 scale{ 1.f,1.f,0.f };
	
	float radian = 0.f;

	D3DXVECTOR3 destination{ 0.f,0.f,0.f };
	GameObject* target = nullptr;

	ObjectType type = ObjectType::NONE;
	int uid = 0;
	bool isDead = false;
	bool isEnable = true;
	bool isVisible = true;
	bool jumpFlag = false;
	bool isAlliance = true;
};