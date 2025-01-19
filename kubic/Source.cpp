#define WINVER 0x601
#include <afxwin.h>
#include <cmath>
#include <gdiplus.h>
#include <gl/GL.h>
using namespace Gdiplus;
class App :public CWinApp {
public:

	virtual BOOL InitInstance();
};
App app;
class Win : public CFrameWnd
{
public:
	float anglez = 0;
	float angley = 0;
	float anglex = 0;
	Win()
	{
		Create(NULL, L"okno");
	};
	DECLARE_MESSAGE_MAP()
	HGLRC glRC;
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
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
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


void Win::OnPaint()
{
	CRect r;
	CPaintDC dc(this);
	wglMakeCurrent(dc, glRC);
	GetClientRect(&r);
	if (r.Width() > r.Height()) {
		glViewport(r.Width() / 2 - r.Height() / 2, 0, r.Height(), r.Height());
	}
	else
	{
		glViewport(0, r.Height() / 2 - r.Width() / 2, r.Width(), r.Width());
	}
	
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-2, 2, -2, 2, 1, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(0, 0, -3);
	glRotated(anglex, 0,1,0);
	glRotated(angley, 0, 0, 1);
	glRotated(anglez, 1, 0, 0);
	
	glEnable(GL_CULL_FACE);
	glBegin(GL_QUADS);

	glColor3d(0, 0, 1); glVertex3d(-1, 1, 1);//лицо
	glColor3d(0, 1, 1); glVertex3d(-1, -1, 1);
	glColor3d(1, 0, 1); glVertex3d(1, -1, 1);
	glColor3d(0, 3, 1); glVertex3d(1, 1, 1);

	glColor3d(0, 1, 1); glVertex3d(1, 1, 1);//право
	glColor3d(0, 0, 1); glVertex3d(1, -1, 1);
	glColor3d(0, 1, 1); glVertex3d(1, -1, -1);
	glColor3d(1, 0, 1); glVertex3d(1, 1, -1);

	glColor3d(1, 0, 1); glVertex3d(1, 1, -1);//низ
	glColor3d(0, 0, 1); glVertex3d(1, -1, -1);
	glColor3d(0, 3, 1); glVertex3d(-1, -1, -1);
	glColor3d(1, 0, 1); glVertex3d(-1, 1, -1);

	glColor3d(0, 1, 1); glVertex3d(-1, 1, 1);//бок лево
	glColor3d(0, 0, 1); glVertex3d(-1, 1, -1);
	glColor3d(0, 1, 1); glVertex3d(-1, -1, -1);
	glColor3d(1, 0, 1); glVertex3d(-1, -1, 1);

	glColor3d(0, 3, 1); glVertex3d(-1, 1, 1);//вверх
	glColor3d(0, 0, 1); glVertex3d(1, 1, 1);
	glColor3d(0, 1, 1); glVertex3d(1, 1, -1);
	glColor3d(1, 0, 1); glVertex3d(-1, 1, -1);

	glColor3d(3, 0, 1); glVertex3d(1, -1, -1);//задняя
	glColor3d(0, 0, 1); glVertex3d(-1, -1, -1);
	glColor3d(0, 1, 1); glVertex3d(-1, 1, -1);
	glColor3d(1, 0, 1); glVertex3d(1, 1, -1);

	glEnd();
	glFlush();
	SwapBuffers(dc);
	wglMakeCurrent(NULL, NULL);
	// device context for painting
	// TODO: добавьте свой код обработчика сообщений
	// Не вызывать CFrameWnd::OnPaint() для сообщений рисования
}


void Win::OnSize(UINT nType, int cx, int cy)
{
	CFrameWnd::OnSize(nType, cx, cy);
	if (glRC != NULL)wglDeleteContext(glRC);
	CDC* dc = GetDC();
	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,32

	};
	pfd.cDepthBits = 24;
	int pixelFormat = ChoosePixelFormat(*dc, &pfd);
	SetPixelFormat(*dc, pixelFormat, &pfd);
	glRC = wglCreateContext(*dc);
	ReleaseDC(dc);
	Invalidate(FALSE);
	// TODO: добавьте свой код обработчика сообщений
}


void Win::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	switch (nChar)
	{
	case VK_LEFT:angley = angley + 1;
		break;
	case VK_RIGHT:angley = angley - 1;
		break;
	case VK_UP: anglez = anglez - 1;
		break;
	case VK_DOWN:anglez = anglez + 1;
		break;
	case '1':anglex = anglex + 1;
		break;
	case '3':anglex = anglex - 1;
		break;

	}
	Invalidate(FALSE);
	CFrameWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
