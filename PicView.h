// PicView.h : interface of the CPicView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PICVIEW_H__F255C7F1_6505_4F87_A13A_FFDA19C7D7BB__INCLUDED_)
#define AFX_PICVIEW_H__F255C7F1_6505_4F87_A13A_FFDA19C7D7BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPicView : public CView
{
protected: // create from serialization only
	CPicView();
	DECLARE_DYNCREATE(CPicView)

// Attributes
public:
	CString str;
	CPoint cursor, origin;
	CPicDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPicView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PicView.cpp
inline CPicDoc* CPicView::GetDocument()
   { return (CPicDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICVIEW_H__F255C7F1_6505_4F87_A13A_FFDA19C7D7BB__INCLUDED_)
