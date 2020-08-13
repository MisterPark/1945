#pragma once
#include "Enemy.h"
class SPlane_3 :
	public Enemy
{
public:
	SPlane_3();
	virtual ~SPlane_3();

public:
	void Render() override;
	void Update() override;

	int i = 0;
private:
	D3DXVECTOR3 m_vP[4];// P //원점을 기준으로 가만히 있을놈. 
	D3DXVECTOR3 m_vQ[4]; // 점 Q의 역할. 
};

