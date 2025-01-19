
// 6zadachaDlg.h: файл заголовка
//

#pragma once
#include "obslyga.h"

// Диалоговое окно CMy6zadachaDlg
class CMy6zadachaDlg : public CDialogEx
{
// Создание
public:
	CMy6zadachaDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY6ZADACHA_DIALOG };
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
	float w1;
	float w2;
	float phasa;
	obslyga rysonok;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CButton chek;
	afx_msg void OnBnClickedCheck1();
};
