// PicDoc.cpp : implementation of the CPicDoc class
//

#include "stdafx.h"
#include "Pic.h"

#include "PicDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPicDoc

IMPLEMENT_DYNCREATE(CPicDoc, CDocument)

BEGIN_MESSAGE_MAP(CPicDoc, CDocument)
	//{{AFX_MSG_MAP(CPicDoc)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPicDoc construction/destruction

CPicDoc::CPicDoc()
{
	// TODO: add one-time construction code here

}

CPicDoc::~CPicDoc()
{
}

BOOL CPicDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPicDoc serialization

void CPicDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPicDoc diagnostics

#ifdef _DEBUG
void CPicDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPicDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPicDoc commands

BOOL CPicDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	return CDocument::OnSaveDocument(lpszPathName);
}

BOOL CPicDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	
	return TRUE;
}

BOOL CPicDoc::SaveModified() 
{
	// TODO: Add your specialized code here and/or call the base class
	return CDocument::SaveModified();
}

void CPicDoc::OnFileSave() 
{
	// TODO: Add your command handler code here
	CString  strFilter = L"Bitmap image(*.bmp)|*.bmp|JPG image(*.jpg)|*.jpg|GIF image(*.gif)|*.gif|PNG image(*.png)|*.png|others(*.*)|*.*|";  
	CFileDialog dlg(FALSE, _T("bmp"), _T("utitled.bmp"), NULL, strFilter);
	if(dlg.DoModal()==IDOK)
	{
		CString path = dlg.GetPathName();
		CString fileName = dlg.GetFileName();
		HBITMAP hbmp;

		CFile file(path, CFile::modeCreate | CFile::modeWrite);
		file.Write("hello",5);
		file.Close();
		//CFile file(path,CFile::typeBinary|CFile::modeWrite|CFile::modeCreate);
	}
}
