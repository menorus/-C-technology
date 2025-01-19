
// 3zadachaDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "3zadacha.h"
#include "3zadachaDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CMy3zadachaDlg



CMy3zadachaDlg::CMy3zadachaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY3ZADACHA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy3zadachaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, a1);
	DDX_Control(pDX, IDC_PROGRESS2, a2);
	DDX_Control(pDX, IDC_SLIDER1, prior1);
	DDX_Control(pDX, IDC_SLIDER2, prior2);
	DDX_Control(pDX, IDC_BUTTON1, but);
}

BEGIN_MESSAGE_MAP(CMy3zadachaDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy3zadachaDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_CHECK1, &CMy3zadachaDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CMy3zadachaDlg::OnBnClickedCheck2)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, &CMy3zadachaDlg::OnBnClickedButtonExit)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// Обработчики сообщений CMy3zadachaDlg

BOOL CMy3zadachaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	a1.SetRange(0, 100);
	a2.SetRange(0, 100);
	prior1.SetRange(THREAD_PRIORITY_LOWEST, THREAD_PRIORITY_NORMAL);
	prior2.SetRange(THREAD_PRIORITY_LOWEST, THREAD_PRIORITY_NORMAL);
	prior1.SetPos(THREAD_PRIORITY_NORMAL);
	prior2.SetPos(THREAD_PRIORITY_NORMAL);
	prior1.SetTicFreq(1);
	prior2.SetTicFreq(1);
	SetProcessAffinityMask(GetCurrentProcess(),1);
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMy3zadachaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMy3zadachaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CMy3zadachaDlg::OnBnClickedButtonStart()
{
	UpdateData(FALSE);
	//d1 = 0;
	//d2 = 0;
	d1=CreateThread(NULL, 0, potok, &x, 0, NULL);
	d2=CreateThread(NULL, 0, potok, &y, 0, NULL);
	SetTimer(1, 500, NULL);
	but.EnableWindow(FALSE);
	//UpdateData(TRUE);
	// TODO: добавьте свой код обработчика уведомлений
}


void CMy3zadachaDlg::OnBnClickedCheck1()
{
	x.flag = !x.flag;
	// TODO: добавьте свой код обработчика уведомлений
}


void CMy3zadachaDlg::OnBnClickedCheck2()
{
	y.flag = !y.flag;
	// TODO: добавьте свой код обработчика уведомлений
}

DWORD WINAPI CMy3zadachaDlg::potok(PVOID x)
{
	double k = 0;
	Thread* t = (Thread*)x;
	while (true) {
		k = cos(k) + sin(k);
		t->value++;
		if (t->flag != false) Sleep(0);
	}
	return 0;
}



void CMy3zadachaDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	double schet1, schet2, sum;
	schet1 = x.value;
	schet2 = y.value;
	sum = schet1 + schet2;
	schet1 = (schet1 / sum) * 100;
	schet2 = schet2 / sum * 100;
	a1.SetPos(schet1);
	a2.SetPos(schet2);
	x.value = 0;
	y.value = 0;

	CDialogEx::OnTimer(nIDEvent);
}


void CMy3zadachaDlg::OnBnClickedButtonExit()
{
	TerminateThread(d1, 0);
	TerminateThread(d2, 0);
	CloseHandle(d1);
	CloseHandle(d2);
	KillTimer(1);
	but.EnableWindow(TRUE);
	// TODO: добавьте свой код обработчика уведомлений
}


void CMy3zadachaDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	SetThreadPriority(d2,prior1.GetPos());
	SetThreadPriority(d1, prior2.GetPos());
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
