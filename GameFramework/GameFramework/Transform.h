#pragma once
class Transform
{
public:
	Transform(float x = 0.f,float y = 0.f, float z = 0.f);
	Transform(const Transform& other);

	// angle is degree.
	void RotateAround(D3DXVECTOR3 point, float angle);

	D3DXVECTOR3 position{ 0.f,0.f, 0.f };
	D3DXVECTOR3 rotation{ 0.f,0.f, 0.f };
	D3DXVECTOR3 scale{ 0.f,0.f, 0.f };
	D3DXVECTOR3 localPosition{ 0.f,0.f,0.f };
};