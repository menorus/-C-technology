#define _USE_MATH_DEFINES
#include <afxwin.h>
#include <cmath>

class App:public CWinApp {
public:
	virtual BOOL InitInstance();
};
App Put;
class Win : public CFrameWnd
{
public:
	Win()
	{
		Create(NULL, L"Круги");
	};
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();

	CPoint c1, c2;
	BOOL flag;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};


BOOL App::InitInstance()
{
	// TODO: добавьте специализированный код или вызов базового класса
	m_pMainWnd = new Win;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return CWinApp::InitInstance();
}
void DrawLineBrezenham(HDC hDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	int x = x1, y = y1, dx = abs(x2 - x1), dy = abs(y2 - y1);
	int xp, yp;
	double e;
	if (x1 < x2) xp = 1; else xp = -1;
	if (y1 < y2) yp = 1; else yp = -1;
	
	if (dy <= dx) {
		e = (double)dy / dx - 0.5;
		while (x != x2) {
			::SetPixel(hDC, x, y, color);
			if (e >= 0) {
				y+=yp; e -= 1;

			}x += xp; e += (double)dy / dx;

		}
	}
	else {
		e = (double)dx / dy - 0.5;
		while (y!= y2) {
			::SetPixel(hDC, x, y, color);
			if (e >= 0) {
				x+=xp; e -= 1;
				
			}
			y+=yp; e += (double)dx / dy;

		}
	}
}
void DiagonalStep(int& x, int& y, int& e) {
	x++; y--; e += 2 * (x - y + 1);
}
void VerticalStep(int& y, int& e) {
	 y--; e -= 2 * y -1;
}
void HorizonalStep(int& x, int& e) {
	x++; e += 2 * x+1;
}
void DrawCircule(HDC hDC, int R,  int xc, int yc,COLORREF color) {
	int x = 0, y = R, e = 2 * (1 - R);
	while(y >= 0) {
		::SetPixel(hDC, x + xc, y + yc, color);
		::SetPixel(hDC, xc-x, y + yc, color);
		::SetPixel(hDC, x + xc, yc-y, color);
		::SetPixel(hDC, xc-x, yc-y, color);
		if (e == 0) DiagonalStep(x, y, e);
		else
			if (e < 0)
				if (2 * (e + y) - 1 <= 0) HorizonalStep(x, e);
				else DiagonalStep(x, y, e);
			else
				if (2 * (e - x) - 1 <= 0) DiagonalStep(x, y, e);
				else VerticalStep(y, e);
	}


	//for(int i = 0; i <= 360; i += 10) {
	//	x2 = round(x + R * cos(i * M_PI / 180));
	//	y2= round(y + R * cos(i * M_PI / 180));
	//	DrawLineBrezenham(hDC, x1, y1, x2, y2, RGB(0, 0, 0));
	//	x1 = x2;
	//	y1 = y2;
	//}
}

BEGIN_MESSAGE_MAP(Win, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


void Win::OnPaint()
{
	int rad = sqrt(pow(c2.x - c1.x, 2) + pow(c2.y - c1.y, 2));
	CPaintDC dc(this); // device context for painting
	// TODO: добавьте свой код обработчика сообщений
	// Не вызывать CFrameWnd::OnPaint() для сообщений рисования
    DrawLineBrezenham(dc, c1.x, c1.y, c2.x, c2.y, RGB(0, 0, 255));
	DrawCircule(dc, rad, c1.x, c1.y, RGB(0, 0, 0));
}


void Win::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	flag = FALSE;
	CFrameWnd::OnLButtonUp(nFlags, point);
}


void Win::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	c1 = point;
	flag = TRUE;
	CFrameWnd::OnLButtonDown(nFlags, point);
}


void Win::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if (flag) {
		c2 = point;
		Invalidate();
		}
	CFrameWnd::OnMouseMove(nFlags, point);
}
