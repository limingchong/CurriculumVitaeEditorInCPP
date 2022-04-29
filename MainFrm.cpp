// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Pic.h"
#include "Picture.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_WM_TIMER()
	ON_WM_INITMENU()
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
// Global variables

CString picPath;

void CMainFrame::showPic(CString picPath){
	CDC *pDC = GetDC();
	RedrawWindow();
	ASSERT(pDC!=NULL);
	CPicture pic;
	pic.Load(picPath);
	CSize size = pic.GetImageSize();
	
	CRect rect;
	rect.top = 35;
	rect.left = 10;
	rect.bottom = 200;
	rect.right = 200;

	pic.Render(pDC,rect);
	/*
	rect.right -= 10;
	rect.bottom -= 25;
	long height = rect.bottom - rect.top;
	long width = rect.right - rect.left;
	CRect newRect = rect;
	if((double)width*(double)size.cy/(double)size.cx>height){
		newRect.right = (double)height*(double)size.cx/(double)size.cy;
	}else{
		newRect.bottom = (double)width*(double)size.cy/(double)size.cx;
	}
	pic.Render(pDC,newRect);
	*/

}

void CMainFrame::OnFileOpen() 
{
	// TODO: Add your command handler code here
	CFileDialog mFileDlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT|OFN_ALLOWMULTISELECT,
		"JPG(*.jpg)|*.jpg|位图文件(*.bmp)|*.bmp|所有文件(*.*)|*.*", NULL/*AfxGetMainWnd()*/);
	if(mFileDlg.DoModal()==IDOK)
	{
		CString path = mFileDlg.GetPathName();
		CString fileName = mFileDlg.GetFileName();
		SetWindowText(fileName);
		picPath = path;
		showPic(path);
	}
}

void CMainFrame::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CFrameWnd::OnTimer(nIDEvent);
}

void CMainFrame::OnInitMenu(CMenu* pMenu) 
{
	CFrameWnd::OnInitMenu(pMenu);
	
	// TODO: Add your message handler code here
	
}

void CMainFrame::OnFileSave() 
{
	// TODO: Add your command handler code here
}

void CMainFrame::OnFileSaveAs() 
{
	// TODO: Add your command handler code here
}
