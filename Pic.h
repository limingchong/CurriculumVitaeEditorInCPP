// Pic.h : main header file for the PIC application
//

#if !defined(AFX_PIC_H__C5F3966C_F818_4BAE_876B_209737A7D6A7__INCLUDED_)
#define AFX_PIC_H__C5F3966C_F818_4BAE_876B_209737A7D6A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPicApp:
// See Pic.cpp for the implementation of this class
//

class CPicApp : public CWinApp
{
public:
	CPicApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL InitApplication();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPicApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIC_H__C5F3966C_F818_4BAE_876B_209737A7D6A7__INCLUDED_)
