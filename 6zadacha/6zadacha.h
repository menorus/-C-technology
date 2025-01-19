
// 6zadacha.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMy6zadachaApp:
// Сведения о реализации этого класса: 6zadacha.cpp
//

class CMy6zadachaApp : public CWinApp
{
public:
	CMy6zadachaApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMy6zadachaApp theApp;
