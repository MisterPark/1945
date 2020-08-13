#pragma once
#include "GameObject.h"
class Character : public GameObject
{
public:
	Character() = default;
	~Character() = default;

	virtual void Update() override;
	virtual void Render() override;

	bool isCollided(const GameObject* _target);
	RECT GetCollisionArea();
	void SetColliderSize(LONG left, LONG top, LONG right, LONG bottom);

	void PushOut(Character* target, float _force);

public:
	float speed = 0.f;
	RECT simpleCollider; // ��ü�� ���δ� Ŀ�ٶ� �簢����
	vector<RECT> colliders; // ���� �浹����
	int score = 0;
	// �߷�
	bool useGravity = false;
	int gravityCount = 0;
	int hp = 1;
	int jumpCount = 0;

	float attackTick = 0.f;
	float attackDelay = 0.1f;
};
