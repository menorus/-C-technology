
// MFCApplication2Dlg.cpp: файл реализации
//
//#define FROMDLL
#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"

#include <cstring>
//#include 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CMFCApplication2Dlg



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
	, obzor(_T(""))
	, vvod(_T(""))
	, opisanie(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, obzor);
	DDX_Text(pDX, IDC_EDIT2, vvod);
	DDX_Text(pDX, IDC_EDIT3, opisanie);
	//DDX_Control(pDX, IDCANCEL, Icon);
	DDX_Control(pDX, IDC_ICONN, Iconn);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication2Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCApplication2Dlg

BOOL CMFCApplication2Dlg::OnInitDialog()
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

void CMFCApplication2Dlg::OnPaint()
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
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//LONG WINAPI CPlapplet()

void CMFCApplication2Dlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}


void CMFCApplication2Dlg::OnBnClickedButton1()
{
	CFileDialog pam_pam(TRUE, NULL,  NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"aplet |*.cpl|");

	CString name;
	CString	ihfo; 
	HICON icon;
	pam_pam.DoModal(); 
	CString str=pam_pam.GetFileName();
	obzor=str;
	UpdateData(FALSE);
	mydll = LoadLibrary(str);
	
	str = L"";
	if (mydll == NULL) {
		MessageBox(L"не найдено cpl", L"error", NULL);
		FreeLibrary(mydll);
	}
	tan_tan = (APPLET_PROC)GetProcAddress(mydll, "CPlApplet");
	if (tan_tan == NULL) {
		MessageBox(L"не найдено cpl", L"error", NULL);
		FreeLibrary(mydll);
	}
	else {
		//tan_tan(NULL, CPL_INIT, 0, 0);
		if (tan_tan(NULL, CPL_INIT, 0, 0)) {
			if (tan_tan(NULL, CPL_GETCOUNT, 0, 0) >= 1) {
				CPLINFO ranram;
				tan_tan(NULL, CPL_INQUIRE, 0, (LPARAM)&ranram);
				name.LoadString(mydll, ranram.idName);
				vvod = name;

				ihfo.LoadString(mydll, ranram.idInfo);
				opisanie = ihfo;

				icon = LoadIcon(mydll, MAKEINTRESOURCE(ranram.idIcon));
				Iconn.SetIcon(icon);
				UpdateData(FALSE);
			}
		}
	}
	
	// TODO: добавьте свой код обработчика уведомлений
}




void CMFCApplication2Dlg::OnBnClickedButton2()
{
	tan_tan(NULL, CPL_DBLCLK, 0, 0);
	// TODO: добавьте свой код обработчика уведомлений
}
