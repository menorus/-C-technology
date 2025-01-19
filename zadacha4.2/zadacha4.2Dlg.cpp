
// zadacha4.2Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "zadacha4.2.h"
#include "zadacha4.2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно Czadacha42Dlg


Czadacha42Dlg::Czadacha42Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ZADACHA42_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void Czadacha42Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, exit);
}

BEGIN_MESSAGE_MAP(Czadacha42Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Czadacha42Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &Czadacha42Dlg::OnEnChangeEdit1)
END_MESSAGE_MAP()

// Обработчики сообщений Czadacha42Dlg


BOOL Czadacha42Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	sys = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 50, L"memory");
	File = (wchar_t*)MapViewOfFile(sys, FILE_MAP_READ| FILE_MAP_WRITE, 0, 0, 50);
	rol = CreateEvent(NULL, TRUE, FALSE, L"role");
	otv = CreateEvent(NULL, TRUE, FALSE, L"tetx");
	prov = CreateEvent(NULL, FALSE, FALSE, L"otprov");
	DWORD dw = WaitForSingleObject(rol, 0);
	if (dw==WAIT_TIMEOUT) {
		SetEvent(rol);
		exit.SetReadOnly(FALSE);
		SetWindowText(L"отправитель");
		ROLE = TRUE;
	}
	else
	{
		thr = CreateThread(NULL, 0, potok, this, 0, NULL);
		exit.SetReadOnly(TRUE);
		SetWindowText(L"получатель");
		ROLE = FALSE;
	}
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void Czadacha42Dlg::OnPaint()
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
HCURSOR Czadacha42Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Czadacha42Dlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (ROLE) {
		SetEvent(prov);
	}
	CloseHandle(thr);
	CloseHandle(rol);
	CloseHandle(otv);
	CloseHandle(prov);
	EndDialog(NULL);
}
DWORD WINAPI Czadacha42Dlg::potok(PVOID x)
{
	Czadacha42Dlg* dl = (Czadacha42Dlg*)x;
	DWORD dw;
	HANDLE hnd[] = { dl->otv, dl->prov};
	while (true) {
		dw = WaitForMultipleObjects(2, hnd , FALSE, INFINITE);
		switch (dw) {
		case WAIT_OBJECT_0:
			dl->exit.SetWindowTextW(CString(dl->File));
				break;
		case WAIT_OBJECT_0+1:
			dl->ROLE = TRUE;
			dl->exit.SetReadOnly(FALSE);
			dl->exit.SetWindowTextW(L"");
			dl->SetWindowText(L"отправитель");
			return 0;
		}
		//return 0;
	}
	return 0;
}


void Czadacha42Dlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO:  Добавьте код элемента управления
	if (ROLE) {
		exit.GetWindowText(File, exit.GetWindowTextLengthW()+1);

		PulseEvent(otv);
	}
}
