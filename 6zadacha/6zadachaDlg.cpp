
// 6zadachaDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "6zadacha.h"
#include "6zadachaDlg.h"
#include "afxdialogex.h"
#include "obslyga.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CMy6zadachaDlg



CMy6zadachaDlg::CMy6zadachaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY6ZADACHA_DIALOG, pParent)
	, w1(100)
	, w2(90)
	, phasa(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy6zadachaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, w1);
	DDX_Text(pDX, IDC_EDIT2, w2);
	DDX_Control(pDX, IDC_OKNORISOVANIA, rysonok);
	DDX_Control(pDX, IDC_CHECK1, chek);
}

BEGIN_MESSAGE_MAP(CMy6zadachaDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy6zadachaDlg::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECK1, &CMy6zadachaDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// Обработчики сообщений CMy6zadachaDlg

BOOL CMy6zadachaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMy6zadachaDlg::OnPaint()
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
HCURSOR CMy6zadachaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy6zadachaDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	rysonok.peredacha(w1, w2, phasa);
	// TODO: добавьте свой код обработчика уведомлений
}


void CMy6zadachaDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	phasa += 0.1;
	rysonok.peredacha(w1, w2, phasa);
	CDialogEx::OnTimer(nIDEvent);
}


void CMy6zadachaDlg::OnBnClickedCheck1()
{
	if (chek.GetCheck() == BST_CHECKED) {
		SetTimer(1, 100, NULL);

	}
	else { KillTimer(1); }
		
	// TODO: добавьте свой код обработчика уведомлений
}
