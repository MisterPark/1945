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
	D3DXVECTOR3 m_vP[4];// P //������ �������� ������ ������. 
	D3DXVECTOR3 m_vQ[4]; // �� Q�� ����. 
};

