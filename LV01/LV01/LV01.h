
// LV01.h : main header file for the LV01 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CLV01App:
// See LV01.cpp for the implementation of this class
//

class CLV01App : public CWinApp
{
public:
	CLV01App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLV01App theApp;
