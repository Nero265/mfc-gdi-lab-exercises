
// IND_19546.h : main header file for the IND_19546 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CIND19546App:
// See IND_19546.cpp for the implementation of this class
//

class CIND19546App : public CWinApp
{
public:
	CIND19546App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CIND19546App theApp;
