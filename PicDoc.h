// PicDoc.h : interface of the CPicDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PICDOC_H__94519314_72D4_4ECC_AA4F_838BF8A73B39__INCLUDED_)
#define AFX_PICDOC_H__94519314_72D4_4ECC_AA4F_838BF8A73B39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPicDoc : public CDocument
{
protected: // create from serialization only
	CPicDoc();
	DECLARE_DYNCREATE(CPicDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	protected:
	virtual BOOL SaveModified();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPicDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPicDoc)
	afx_msg void OnFileSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICDOC_H__94519314_72D4_4ECC_AA4F_838BF8A73B39__INCLUDED_)
