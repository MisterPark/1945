#include "pch.h"

Transform::Transform(float x, float y, float z)
{
	position = { x,y,z };
}

Transform::Transform(const Transform & other)
{
	position = other.position;
	rotation = other.rotation;
	scale = other.scale;
}
