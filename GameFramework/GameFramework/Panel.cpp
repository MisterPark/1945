#include "pch.h"
#include "Panel.h"

Panel::Panel()
{
	
}

Panel::~Panel()
{
}

void Panel::Update()
{
}

void Panel::Render()
{
	RenderManager::DrawRect(transform.position, transform.rotation, transform.scale);
}
