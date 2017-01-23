// AcDocDoc.h : interface of the CAcDocDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACDOCDOC_H__4713B54B_062B_11D2_B890_C54647D3D618__INCLUDED_)
#define AFX_ACDOCDOC_H__4713B54B_062B_11D2_B890_C54647D3D618__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CAcDocSrvrItem;

struct ELEM
{
	CString strGUID;
	CString strTyp;
	UINT uCount;
	UINT uPrice;
};

class CAcDocDoc : public COleServerDoc
{
protected: // create from serialization only
	CAcDocDoc();
	DECLARE_DYNCREATE(CAcDocDoc)

// Attributes
public:

	CObList m_oblistElems;

	CAcDocSrvrItem* GetEmbeddedItem()
		{ return (CAcDocSrvrItem*)COleServerDoc::GetEmbeddedItem(); }

// Operations
public:

	void InsertElem(CString strGUID, const CString& strTyp, UINT uCount, UINT uPrice);
	void UpdateElem(CString strGUID, const CString& strTyp, UINT uCount, UINT uPrice);
	bool GetElem(const CString& strTyp, CString* strGUID,UINT* uCount, UINT* uPrice);
	bool DeleteElem(const CString& strTyp);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAcDocDoc)
	protected:
	virtual COleServerItem* OnGetEmbeddedItem();
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAcDocDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual CDocObjectServer* GetDocObjectServer(LPOLEDOCUMENTSITE pDocSite);

// Generated message map functions
protected:
	//{{AFX_MSG(CAcDocDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACDOCDOC_H__4713B54B_062B_11D2_B890_C54647D3D618__INCLUDED_)
