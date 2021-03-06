#pragma once
#include <Windows.h>

class RenderManager
{
private:
	RenderManager();
	~RenderManager();

public:
	static RenderManager* GetInstance();
	static void Release();
	static void DrawRect(float left, float top, float right, float bottom);
	static void DrawRect(Transform transform);
	static void DrawRect(D3DXVECTOR3 pos, D3DXVECTOR3 dir, D3DXVECTOR3 scale);
	static void DrawRect(const RECT& _rc);
	static void DrawRect(const RECT& _rc, COLORREF _innerColor);
	static void DrawRect(const RECT& _rc, COLORREF _innerColor, COLORREF _outlineColor);
	static void DrawSimpleCollider(const RECT& _rc, COLORREF _outlineColor);
	static void DrawCircle(const RECT& _rc);
	static void DrawCircle(const RECT& _rc, COLORREF _innerColor, COLORREF _outlineColor);
	static void DrawString(const WCHAR* _str, int _x, int _y);
	static void DrawString(const WCHAR* _str, int _x, int _y, COLORREF _color);
	static void DrawString(const WCHAR* _str, int _x, int _y, const WCHAR* _font, int _fontSize, COLORREF _color);
	static void DrawLine(float StartX, float StartY, float EndX, float EndY);
	
	static void Present();
	static void Clear();

private:
	HDC hdc;
	HBITMAP hBitmap;
	HDC hBackBufferDC;
	RECT area = { 0,0,dfWINDOW_WIDTH,dfWINDOW_HEIGHT };
};

