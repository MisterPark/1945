#include "pch.h"
#include "Transform.h"

Transform::Transform(float x, float y, float z)
{
	position = { x,y,z };
}

Transform::Transform(const Transform & other)
{
	position = other.position;
	rotation = other.rotation;
	scale = other.scale;
	localPosition = other.localPosition;
}

void Transform::RotateAround(D3DXVECTOR3 point, float angle)
{
	// x * cos@ - y*sin@ , x*sin@ + y * cos@

	rotation.z += angle;

	float rad = D3DXToRadian(angle);
	D3DXVECTOR3 pos = position;
	pos.x = position.x * cosf(rad) - position.y * sinf(rad);
	pos.y = position.x *sinf(rad) + position.y * cos(rad);

	//pos.x += 10;
	//pos.y += 10;

	position = pos;
	//pos.x = point.x;
	//pos.y = point.y;

}
