// PicView.cpp : implementation of the CPicView class
//

#include "stdafx.h"
#include "Pic.h"

#include "PicDoc.h"
#include "PicView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPicView

IMPLEMENT_DYNCREATE(CPicView, CView)

BEGIN_MESSAGE_MAP(CPicView, CView)
	//{{AFX_MSG_MAP(CPicView)
	ON_WM_LBUTTONDOWN()
	ON_WM_CONTEXTMENU()
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPicView construction/destruction

CPicView::CPicView()
{
	// TODO: add construction code here

}

CPicView::~CPicView()
{
}

BOOL CPicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPicView drawing

void CPicView::OnDraw(CDC* pDC)
{
	CPicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	HDC hdc = pDC->GetSafeHdc();
	COLORREF crOld = SetTextColor(hdc, RGB(100,100,100));
	SetBkMode(hdc, TRANSPARENT);
	HBRUSH hbrush = CreateSolidBrush(RGB(0, 0, 0));

	CRect rect;
	rect.top = 5;
	rect.left = 5;
	rect.bottom = 180;
	rect.right = 200;
	
	CClientDC dc(this);
	dc.Rectangle(rect);

	pDC->TextOut(10,10,"1. Click to put cursor");
	pDC->TextOut(10,30,"2. Press keys to print");
	pDC->TextOut(10,50,"3. Load picture to show here");
	pDC->TextOut(10,140,"Author: MingchongLi");
	pDC->TextOut(10,160,"Date: 2021/12/30");
	

	DeleteObject(hbrush);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPicView diagnostics

#ifdef _DEBUG
void CPicView::AssertValid() const
{
	CView::AssertValid();
}

void CPicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPicDoc* CPicView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPicDoc)));
	return (CPicDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPicView message handlers

void CPicView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCaretPos(point);

	CClientDC dc(this);
	dc.TextOut(origin.x,origin.y,str);

	cursor = point;
	origin = point;
	str = "";
	
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CreateSolidCaret(tm.tmAveCharWidth/4, tm.tmHeight + 10);
	ShowCaret();
	CView::OnLButtonDown(nFlags, point);
}

BOOL CPicView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CPicView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	
}

void CPicView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CString type;
	CClientDC dc(this);
	if (nChar == 0x08){
		str = str.Mid(0,str.GetLength()-1);
		str += "  ";
		dc.TextOut(origin.x,origin.y,str);
		str = str.Mid(0,str.GetLength()-2);
	}else if(nChar == 0x0D){
		origin.y += dc.GetTextExtent(str).cy;
		cursor.x = origin.x;
		cursor.y = origin.y;
		str = "";
	}else{
		type.Format(_T("%c"),nChar);
		str += type;
	}
	dc.TextOut(origin.x,origin.y,str);
	cursor.x = origin.x + dc.GetTextExtent(str).cx;
	SetCaretPos(cursor);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
