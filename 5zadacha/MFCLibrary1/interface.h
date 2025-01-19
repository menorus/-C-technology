#pragma once
#include "afxdialogex.h"


// Диалоговое окно interface

class okno : public CDialog
{
	DECLARE_DYNAMIC(okno)
	BOOL swap;
public:
	okno(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~okno();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_interface };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
