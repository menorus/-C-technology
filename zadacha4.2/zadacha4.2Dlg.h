
// zadacha4.2Dlg.h: файл заголовка
//

#pragma once


// Диалоговое окно Czadacha42Dlg
class Czadacha42Dlg : public CDialogEx
{
// Создание
public:
	Czadacha42Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZADACHA42_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	static DWORD __stdcall potok(PVOID x);
	HANDLE rol;
	HANDLE otv;
	HANDLE prov;
	HANDLE thr;
	HANDLE sys;
	wchar_t* File;
	afx_msg void OnEnChangeEdit1();
	CEdit exit;
	BOOL ROLE;
};
