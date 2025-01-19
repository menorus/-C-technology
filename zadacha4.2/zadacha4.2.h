
// zadacha4.2.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// Czadacha42App:
// Сведения о реализации этого класса: zadacha4.2.cpp
//

class Czadacha42App : public CWinApp
{
public:
	Czadacha42App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern Czadacha42App theApp;
