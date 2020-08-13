#include "pch.h"
#include "RenderManager.h"

RenderManager* pRenderManager = nullptr;

RenderManager::RenderManager()
{
	hdc = GetDC(g_hwnd);
	hBitmap = CreateCompatibleBitmap(hdc, dfWINDOW_WIDTH, dfWINDOW_HEIGHT);
	hBackBufferDC = CreateCompatibleDC(hdc);
	SelectObject(hBackBufferDC, hBitmap);
	SetBkMode(hBackBufferDC, TRANSPARENT);
}

RenderManager::~RenderManager()
{
	ReleaseDC(g_hwnd, hdc);
	//일단 해제해 주고
	if (hBackBufferDC != nullptr)
	{
		SelectObject(hBackBufferDC, nullptr);
		DeleteDC(hBackBufferDC);
	}
	//백버퍼도 지운다.
	if (hBitmap != nullptr)
	{
		DeleteObject(hBitmap);
	}
}

RenderManager * RenderManager::GetInstance()
{
	if (pRenderManager == nullptr)
	{
		pRenderManager = new RenderManager;
	}
	return pRenderManager;
}

void RenderManager::Release()
{
	delete pRenderManager;
	pRenderManager = nullptr;
}

void RenderManager::DrawRect(float left, float top, float right, float bottom)
{
	MoveToEx(pRenderManager->hBackBufferDC, (int)left, (int)top, nullptr);
	LineTo(pRenderManager->hBackBufferDC, (int)right, (int)top);
	LineTo(pRenderManager->hBackBufferDC, (int)right, (int)bottom);
	LineTo(pRenderManager->hBackBufferDC, (int)left, (int)bottom);
	LineTo(pRenderManager->hBackBufferDC, (int)left, (int)top);
}

void RenderManager::DrawRect(Transform transform)
{
	D3DXVECTOR3 vp[4];
	vp[0] = { -transform.scale.x,-transform.scale.y,0.f };
	vp[1] = { transform.scale.x,-transform.scale.y,0.f };
	vp[2] = { transform.scale.x,transform.scale.y,0.f };
	vp[3] = { -transform.scale.x,transform.scale.y,0.f };

	// Rotate (z)
	// x * cos@ - y*sin@ , x*sin@ + y * cos@
	D3DXVECTOR3 vq[4];
	float radian = D3DXToRadian(transform.rotation.z);
	vq[0].x = vp[0].x * cosf(radian) - vp[0].y * sinf(radian);
	vq[0].y = vp[0].x * sinf(radian) + vp[0].y * cosf(radian);
	vq[1].x = vp[1].x * cosf(radian) - vp[1].y * sinf(radian);
	vq[1].y = vp[1].x * sinf(radian) + vp[1].y * cosf(radian);
	vq[2].x = vp[2].x * cosf(radian) - vp[2].y * sinf(radian);
	vq[2].y = vp[2].x * sinf(radian) + vp[2].y * cosf(radian);
	vq[3].x = vp[3].x * cosf(radian) - vp[3].y * sinf(radian);
	vq[3].y = vp[3].x * sinf(radian) + vp[3].y * cosf(radian);

	vq[0] += transform.position;
	vq[1] += transform.position;
	vq[2] += transform.position;
	vq[3] += transform.position;

	MoveToEx(pRenderManager->hBackBufferDC, (int)vq[0].x, (int)vq[0].y, nullptr);
	LineTo(pRenderManager->hBackBufferDC, (int)vq[1].x, (int)vq[1].y);
	LineTo(pRenderManager->hBackBufferDC, (int)vq[2].x, (int)vq[2].y);
	LineTo(pRenderManager->hBackBufferDC, (int)vq[3].x, (int)vq[3].y);
	LineTo(pRenderManager->hBackBufferDC, (int)vq[0].x, (int)vq[0].y);
}

void RenderManager::DrawRect(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scale)
{
	D3DXVECTOR3 vp[4];
	vp[0] = { -scale.x,-scale.y,0.f };
	vp[1] = { scale.x,-scale.y,0.f };
	vp[2] = { scale.x,scale.y,0.f };
	vp[3] = { -scale.x,scale.y,0.f };

	// Rotate (z)
	// x * cos@ - y*sin@ , x*sin@ + y * cos@
	D3DXVECTOR3 vq[4];
	float radian = D3DXToRadian(rot.z);
	vq[0].x = vp[0].x * cosf(radian) - vp[0].y * sinf(radian);
	vq[0].y = vp[0].x * sinf(radian) + vp[0].y * cosf(radian);
	vq[1].x = vp[1].x * cosf(radian) - vp[1].y * sinf(radian);
	vq[1].y = vp[1].x * sinf(radian) + vp[1].y * cosf(radian);
	vq[2].x = vp[2].x * cosf(radian) - vp[2].y * sinf(radian);
	vq[2].y = vp[2].x * sinf(radian) + vp[2].y * cosf(radian);
	vq[3].x = vp[3].x * cosf(radian) - vp[3].y * sinf(radian);
	vq[3].y = vp[3].x * sinf(radian) + vp[3].y * cosf(radian);

	vq[0] += pos;
	vq[1] += pos;
	vq[2] += pos;
	vq[3] += pos;
	
	MoveToEx(pRenderManager->hBackBufferDC, (int)vq[0].x, (int)vq[0].y, nullptr);
	LineTo(pRenderManager->hBackBufferDC, (int)vq[1].x, (int)vq[1].y);
	LineTo(pRenderManager->hBackBufferDC, (int)vq[2].x, (int)vq[2].y);
	LineTo(pRenderManager->hBackBufferDC, (int)vq[3].x, (int)vq[3].y);
	LineTo(pRenderManager->hBackBufferDC, (int)vq[0].x, (int)vq[0].y);
}

void RenderManager::DrawRect(const RECT& _rc)
{
	Rectangle(pRenderManager->hBackBufferDC, _rc.left, _rc.top, _rc.right, _rc.bottom);
}

void RenderManager::DrawRect(const RECT& _rc, COLORREF _innerColor)
{
	HBRUSH hBrush = CreateSolidBrush(_innerColor);
	HGDIOBJ oldBrush = SelectObject(pRenderManager->hBackBufferDC, hBrush);
	Rectangle(pRenderManager->hBackBufferDC, _rc.left, _rc.top, _rc.right, _rc.bottom);
	SelectObject(pRenderManager->hBackBufferDC, oldBrush);
	DeleteObject(hBrush);
}

void RenderManager::DrawRect(const RECT& _rc, COLORREF _innerColor, COLORREF _outlineColor)
{
	HBRUSH hBrush = CreateSolidBrush(_innerColor);
	HPEN hPen = CreatePen(PS_SOLID, 1, _outlineColor);
	HGDIOBJ oldBrush = SelectObject(pRenderManager->hBackBufferDC, hBrush);
	HGDIOBJ oldPen = SelectObject(pRenderManager->hBackBufferDC, hPen);
	Rectangle(pRenderManager->hBackBufferDC, _rc.left, _rc.top, _rc.right, _rc.bottom);
	SelectObject(pRenderManager->hBackBufferDC, oldBrush);
	SelectObject(pRenderManager->hBackBufferDC, oldPen);
	DeleteObject(hBrush);
	DeleteObject(hPen);
}

void RenderManager::DrawSimpleCollider(const RECT& _rc, COLORREF _outlineColor)
{
	HPEN hPen = CreatePen(PS_SOLID, 1, _outlineColor);
	HGDIOBJ oldPen = SelectObject(pRenderManager->hBackBufferDC, hPen);
	Rectangle(pRenderManager->hBackBufferDC, _rc.left, _rc.top, _rc.right, _rc.bottom);
	SelectObject(pRenderManager->hBackBufferDC, oldPen);
	DeleteObject(hPen);
}


void RenderManager::DrawCircle(const RECT& _rc)
{
	Ellipse(pRenderManager->hBackBufferDC, _rc.left, _rc.top, _rc.right, _rc.bottom);
}

void RenderManager::DrawCircle(const RECT& _rc, COLORREF _innerColor, COLORREF _outlineColor)
{
	HBRUSH hBrush = CreateSolidBrush(_innerColor);
	HPEN hPen = CreatePen(PS_SOLID, 1, _outlineColor);
	HGDIOBJ oldBrush = SelectObject(pRenderManager->hBackBufferDC, hBrush);
	HGDIOBJ oldPen = SelectObject(pRenderManager->hBackBufferDC, hPen);
	Ellipse(pRenderManager->hBackBufferDC, _rc.left, _rc.top, _rc.right, _rc.bottom);
	SelectObject(pRenderManager->hBackBufferDC, oldBrush);
	SelectObject(pRenderManager->hBackBufferDC, oldPen);
	DeleteObject(hBrush);
	DeleteObject(hPen);
}

void RenderManager::DrawString(const WCHAR* _str, int _x, int _y)
{
	TextOutW(pRenderManager->hBackBufferDC, _x, _y, _str, wcslen(_str));
}

void RenderManager::DrawString(const WCHAR* _str, int _x, int _y, COLORREF _color)
{
	COLORREF oldColor = SetTextColor(pRenderManager->hBackBufferDC, _color);
	TextOutW(pRenderManager->hBackBufferDC, _x, _y, _str, wcslen(_str));
	SetTextColor(pRenderManager->hBackBufferDC, oldColor);
}

void RenderManager::DrawString(const WCHAR* _str, int _x, int _y, const WCHAR* _font, int _fontSize, COLORREF _color)
{
	HFONT hFont = CreateFont(_fontSize, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, _font);
	HFONT oldFont = (HFONT)SelectObject(pRenderManager->hBackBufferDC, hFont);
	COLORREF oldColor = SetTextColor(pRenderManager->hBackBufferDC, _color);
	TextOutW(pRenderManager->hBackBufferDC, _x, _y, _str, wcslen(_str));
	SelectObject(pRenderManager->hBackBufferDC, oldFont);
	DeleteObject(hFont);
	SetTextColor(pRenderManager->hBackBufferDC, oldColor);
}

void RenderManager::DrawLine(float StartX, float StartY, float EndX, float EndY)
{
	POINT pt = {};
	MoveToEx(pRenderManager->hBackBufferDC, StartX, StartY, &pt);
	LineTo(pRenderManager->hBackBufferDC, EndX, EndY);
}

void RenderManager::Present()
{
	BitBlt(pRenderManager->hdc, 0, 0, dfWINDOW_WIDTH, dfWINDOW_HEIGHT,
		pRenderManager->hBackBufferDC, 0, 0, SRCCOPY);
}

void RenderManager::Clear()
{
	FillRect(pRenderManager->hBackBufferDC, &pRenderManager->area,
		(HBRUSH)GetStockObject(WHITE_BRUSH));
}
