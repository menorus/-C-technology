
// 3zadacha.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMy3zadachaApp:
// Сведения о реализации этого класса: 3zadacha.cpp
//

class CMy3zadachaApp : public CWinApp
{
public:
	CMy3zadachaApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMy3zadachaApp theApp;
