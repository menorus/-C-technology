// interface.cpp: файл реализации
//

#include "pch.h"
#include "MFCLibrary1.h"
#include "afxdialogex.h"
#include "interface.h"


// Диалоговое окно interface

IMPLEMENT_DYNAMIC(okno, CDialog)

okno::okno(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_interface, pParent)
{
	swap = TRUE;
}

okno::~okno()
{
}

void okno::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(okno, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &okno::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений interface


void okno::OnBnClickedButton1()
{

	SystemParametersInfo(SPI_SETMOUSESONAR, 0, (PVOID)swap, 0);
	swap = !swap;
	// TODO: добавьте свой код обработчика уведомлений
}
