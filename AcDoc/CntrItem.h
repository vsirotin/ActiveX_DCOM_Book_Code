// CntrItem.h : interface of the CAcDocCntrItem class
//

#if !defined(AFX_CNTRITEM_H__4713B554_062B_11D2_B890_C54647D3D618__INCLUDED_)
#define AFX_CNTRITEM_H__4713B554_062B_11D2_B890_C54647D3D618__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CAcDocDoc;
class CAcDocView;

class CAcDocCntrItem : public COleClientItem
{
	DECLARE_SERIAL(CAcDocCntrItem)

// Constructors
public:
	CAcDocCntrItem(CAcDocDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	CAcDocDoc* GetDocument()
		{ return (CAcDocDoc*)COleClientItem::GetDocument(); }
	CAcDocView* GetActiveView()
		{ return (CAcDocView*)COleClientItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAcDocCntrItem)
	public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();
	protected:
	virtual void OnGetItemPosition(CRect& rPosition);
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	virtual BOOL CanActivate();
	//}}AFX_VIRTUAL

// Implementation
public:
	~CAcDocCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNTRITEM_H__4713B554_062B_11D2_B890_C54647D3D618__INCLUDED_)
