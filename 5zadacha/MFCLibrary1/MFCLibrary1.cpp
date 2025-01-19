// MFCLibrary1.cpp: определяет процедуры инициализации для библиотеки DLL.
//

#include "pch.h"
#include "framework.h"
#include "MFCLibrary1.h"
#include "Resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <Cpl.h>
#include "interface.h"
//
//TODO: если эта библиотека DLL динамически связана с библиотеками DLL MFC,
//		все функции, экспортированные из данной DLL-библиотеки, которые выполняют вызовы к
//		MFC, должны содержать макрос AFX_MANAGE_STATE в
//		самое начало функции.
//
//		Например:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// тело нормальной функции
//		}
//
//		Важно, чтобы данный макрос был представлен в каждой
//		функции до вызова MFC.  Это означает, что
//		должен стоять в качестве первого оператора в
//		функции и предшествовать даже любым объявлениям переменных объекта,
//		поскольку их конструкторы могут выполнять вызовы к MFC
//		DLL.
//
//		В Технических указаниях MFC 33 и 58 содержатся более
//		подробные сведения.
//

// CMFCLibrary1App

BEGIN_MESSAGE_MAP(CMFCLibrary1App, CWinApp)
END_MESSAGE_MAP()


// Создание CMFCLibrary1App

CMFCLibrary1App::CMFCLibrary1App()
{
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект CMFCLibrary1App

CMFCLibrary1App theApp;


// Инициализация CMFCLibrary1App

BOOL CMFCLibrary1App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
LONG WINAPI CPlApplet(HWND hwndCPL, UINT uMsg, LPARAM lparam1, LPARAM lparam2)
		{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		CPLINFO* read;
		switch (uMsg)
		{
		case CPL_INIT: return TRUE;
		case CPL_GETCOUNT: return 1;
		case CPL_INQUIRE:
			read = (CPLINFO*)lparam2;
			read->idIcon=IDI_ICON1;
			read->idName= IDS_1AP;
			read->idInfo= IDS_2AP;
			read->lData = 0;

		case CPL_DBLCLK:
		{
			okno rer;
			rer.DoModal();
		}
			break;
		}
		return 0;
	}
//SystemParametersInfo