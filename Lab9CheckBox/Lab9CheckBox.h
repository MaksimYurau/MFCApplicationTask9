
// Lab9CheckBox.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CLab9CheckBoxApp:
// Сведения о реализации этого класса: Lab9CheckBox.cpp
//

class CLab9CheckBoxApp : public CWinApp
{
public:
	CLab9CheckBoxApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CLab9CheckBoxApp theApp;
