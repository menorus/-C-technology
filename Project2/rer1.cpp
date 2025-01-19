#define _USE_MATH_DEFINES
#include <afxwin.h>
#include <cmath>
#include <gdiplus.h>
#include "math3d.h"
using namespace Gdiplus;
using namespace math3d;
class App :public CWinApp {
public:

	virtual BOOL InitInstance();
};
App Put;
class Win : public CFrameWnd
{
	float anglez=0;
	float angley = 0;
public:
	Win()
	{
		ULONG_PTR token;
		GdiplusStartupInput input;
		Status s;
		s = GdiplusStartup(&token, &input, NULL);
		if (s != Ok)
		{
			MessageBox(L"broken");
		}
		Create(NULL, L"okno");
	};

	/*Win()
	{
		Create(NULL, L"Фигура туда-сюда");
		ULONG_PTR token;
		GdiplusStartupInput input;
		Status s;
		s = GdiplusStartup(&token, &input, NULL);
	};*/


	//DECLARE_MESSAGE_MAP()
	
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};


BOOL App::InitInstance()
{
	// TODO: добавьте специализированный код или вызов базового класса
	m_pMainWnd = new Win;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return CWinApp::InitInstance();
}
BEGIN_MESSAGE_MAP(Win, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

float z(float x, float y) {
	return cos(x * x + y * y) / (x * x + y * y + 1);
}
void Win::OnPaint()
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	Graphics gr2(dc);
	Bitmap pict(rect.Width(), rect.Height(), &gr2);
	Graphics gr(&pict);
	gr.Clear(Color::White);
	Matrix matr;
	CRect r;
	GetClientRect(&r);
	float res1 = r.Width() / 4;
	float res2 = r.Height() / 1.5;
	matr.Scale(res1, -res2);
	matr.Translate(2, -1);
	gr.SetTransform(&matr);
	Pen p(Color::Chocolate, 0.001);
	SolidBrush zx(Color::Green);
	//gr.DrawLine(&p, -2.0f, 1.0f, 2.0f, -0.5f);
	int N = 40;
	float iter = 4. / 40.;
	mat4 gg;
	gg.rotateZ(anglez).scale(0.7,0.7,0.7);
	gg.rotateY(angley).scale(0.7, 0.7, 0.7);

	for (int i = 0; i < N; i++) {
		float x1 = -2. + iter * i, x2 = x1 + iter, x3 = x2, x4 = x1;
		for (float j = 0.f; j < N; j++) {
			float y1 = -2. + iter * j, y2 = y1, y3 = y1+iter, y4 = y3;
			float z1 = z(x1, y1), z2 = z(x2, y2), z3 = z(x3, y3), z4 = z(x4, y4);
			vec4 q1(x1, y1, z1);
			vec4 q2(x2, y2, z2);
			vec4 q3(x3, y3, z3);
			vec4 q4(x4, y4, z4);
			q1 = q1 * gg;
			q2 = q2 * gg;
			q3 = q3 * gg;
			q4 = q4 * gg;
			PointF tochki[4] = { PointF(q1.y(),q1.z()),PointF(q2.y(),q2.z()), PointF(q3.y(),q3.z()), PointF(q4.y(),q4.z())};
			gr.FillPolygon(&zx, tochki, 4);
			gr.DrawPolygon(&p, tochki, 4);
			
		}
	}
	gr2.DrawImage(&pict, 0, 0);
	// device context for painting
	// TODO: добавьте свой код обработчика сообщений
	// Не вызывать CFrameWnd::OnPaint() для сообщений рисования
}


void Win::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{

	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	switch (nChar)
	{
	case VK_RIGHT:anglez += 1; break;
	case VK_LEFT:anglez -= 1; break;
	case VK_UP:angley += 1; break;
	case VK_DOWN:angley -= 1; break;
	}
	Invalidate(FALSE);
	CFrameWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
