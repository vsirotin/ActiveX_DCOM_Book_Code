// AcDocView.cpp : implementation of the CAcDocView class
//

#include "stdafx.h"
#include "AcDoc.h"

#include "AcDocDoc.h"
#include "CntrItem.h"
#include "AcDocView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAcDocView

IMPLEMENT_DYNCREATE(CAcDocView, CFormView)

BEGIN_MESSAGE_MAP(CAcDocView, CFormView)
	//{{AFX_MSG_MAP(CAcDocView)
	ON_WM_DESTROY()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, OnCancelEditCntr)
	ON_COMMAND(ID_CANCEL_EDIT_SRVR, OnCancelEditSrvr)
	ON_BN_CLICKED(IDC_ELEM_TO_LIST, OnElemToList)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	ON_BN_CLICKED(IDC_NEW_ELEM, OnNewElem)
	ON_EN_UPDATE(IDC_TYP, OnUpdateTyp)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAcDocView construction/destruction

CAcDocView::CAcDocView()
	: CFormView(CAcDocView::IDD)
{
	//{{AFX_DATA_INIT(CAcDocView)
	m_uCount = 0;
	m_strGUID = _T("");
	m_uPrice = 0;
	m_strTyp = _T("");
	//}}AFX_DATA_INIT
	m_pSelection = NULL;
	// TODO: add construction code here

}

CAcDocView::~CAcDocView()
{
}

void CAcDocView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAcDocView)
	DDX_Control(pDX, IDC_LIST1, m_listbox);
	DDX_Text(pDX, IDC_COUNT, m_uCount);
	DDX_Text(pDX, IDC_ID, m_strGUID);
	DDX_Text(pDX, IDC_PRICE, m_uPrice);
	DDX_Text(pDX, IDC_TYP, m_strTyp);
	//}}AFX_DATA_MAP
}

BOOL CAcDocView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CAcDocView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();


	InitElem();
	CAcDocDoc* pDoc = GetDocument();
	
	if(!pDoc->m_oblistElems.IsEmpty()) 
	{
		ELEM* pELEM;
		POSITION pos, posOld;
		posOld = pos = pDoc->m_oblistElems.GetHeadPosition();
		for(pos; pos != NULL; posOld = pos)
		{
			pELEM = (ELEM*)pDoc->m_oblistElems.GetNext(pos);
			m_listbox.AddString(pELEM->strTyp);
			
		}
	}

	UpdateData(FALSE);

	// TODO: remove this code when final selection model code is written
//	m_pSelection = NULL;    // initialize selection

}

/////////////////////////////////////////////////////////////////////////////
// CAcDocView printing

BOOL CAcDocView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAcDocView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAcDocView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CAcDocView::OnPrint(CDC* pDC, CPrintInfo*)
{
	// TODO: add code to print the controls
}

void CAcDocView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used.
   CFormView::OnDestroy();
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
}


/////////////////////////////////////////////////////////////////////////////
// OLE Client support and commands

BOOL CAcDocView::IsSelected(const CObject* pDocItem) const
{
	// The implementation below is adequate if your selection consists of
	//  only CAcDocCntrItem objects.  To handle different selection
	//  mechanisms, the implementation here should be replaced.

	// TODO: implement this function that tests for a selected OLE client item

	return pDocItem == m_pSelection;
}

void CAcDocView::OnInsertObject()
{
	// Invoke the standard Insert Object dialog box to obtain information
	//  for new CAcDocCntrItem object.
	COleInsertDialog dlg;
	if (dlg.DoModal() != IDOK)
		return;

	BeginWaitCursor();

	CAcDocCntrItem* pItem = NULL;
	TRY
	{
		// Create new item connected to this document.
		CAcDocDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CAcDocCntrItem(pDoc);
		ASSERT_VALID(pItem);

		// Initialize the item from the dialog data.
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // any exception will do
		ASSERT_VALID(pItem);

		// If item created from class list (not from file) then launch
		//  the server to edit the item.
		if (dlg.GetSelectionType() == COleInsertDialog::createNewItem)
			pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);

		// As an arbitrary user interface design, this sets the selection
		//  to the last item inserted.

		// TODO: reimplement selection as appropriate for your application

		m_pSelection = pItem;   // set selection to last inserted item
		pDoc->UpdateAllViews(NULL);
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the container (not the server) causes the deactivation.
void CAcDocView::OnCancelEditCntr()
{
	// Close any in-place active item on this view.
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}

// Special handling of OnSetFocus and OnSize are required for a container
//  when an object is being edited in-place.
void CAcDocView::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// need to set focus to this item if it is in the same view
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != NULL)
		{
			pWnd->SetFocus();   // don't call the base class
			return;
		}
	}

	CFormView::OnSetFocus(pOldWnd);
}

void CAcDocView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
		pActiveItem->SetItemRects();
}

/////////////////////////////////////////////////////////////////////////////
// OLE Server support

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the server (not the container) causes the deactivation.
void CAcDocView::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CAcDocView diagnostics

#ifdef _DEBUG
void CAcDocView::AssertValid() const
{
	CFormView::AssertValid();
}

void CAcDocView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CAcDocDoc* CAcDocView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAcDocDoc)));
	return (CAcDocDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
void CAcDocView::OnElemToList() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int iCount = m_listbox.GetCount();
	bool bInserted = true;

	CString strTmp;
	for(int i = 0; i < iCount; i++)
	{
		m_listbox.GetText(i, strTmp);
		if(strTmp.CompareNoCase(m_strTyp) == 0)
		{
			GetDocument()->UpdateElem(m_strGUID, m_strTyp, m_uCount, m_uPrice);
			InitElem(); 
			m_listbox.SetCurSel(i);
			return;
		}
	}

	GetDocument()->InsertElem(m_strGUID, m_strTyp, m_uCount, m_uPrice);
	m_listbox.AddString(m_strTyp);
	m_listbox.SetCurSel(m_listbox.GetCount() - 1);
	InitElem(); 
}

void CAcDocView::OnSelchangeList1() 
{
	// TODO: Add your control notification handler code here
	int iCurrSel = m_listbox.GetCurSel();
	
	m_listbox.GetText(iCurrSel, m_strTyp);

	GetDocument()->GetElem(m_strTyp, &m_strGUID, &m_uCount, &m_uPrice);
	
	UpdateData(FALSE);
	
	CWnd* pWnd = GetDlgItem(IDC_ELEM_TO_LIST);
	ASSERT(pWnd != NULL);
	pWnd->EnableWindow(FALSE);
}

void CAcDocView::OnNewElem() 
{
	// TODO: Add your control notification handler code here
		InitElem();

}

void CAcDocView::OnUpdateTyp() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	
	CWnd* pWnd = GetDlgItem(IDC_ELEM_TO_LIST);
	ASSERT(pWnd != NULL);
	
	UpdateData(TRUE);
	BOOL bEnabled = FALSE;
	if(m_strTyp.GetLength() > 0)
		bEnabled = TRUE;

	pWnd->EnableWindow(bEnabled);

}

void CAcDocView::InitElem() 
{
	GUID guid;

	HRESULT hr = ::CoCreateGuid(&guid);
	if(hr != S_OK)
	{
		TRACE("Problem in CAcDocView::InitElemßn");
		return;
	}

	m_strGUID.Format("%08lX-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X",
		guid.Data1, guid.Data2, guid.Data3, 
		guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3],
		guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);

	m_strTyp.Empty();
	m_uCount = m_uPrice = 0;
	UpdateData(FALSE);
	
	CWnd* pWnd = GetDlgItem(IDC_ELEM_TO_LIST);
	ASSERT(pWnd != NULL);
	pWnd->EnableWindow(FALSE);
}

//== Arbeit mit der Zwischenablage


void CAcDocView::OnEditCopy() 
{
	// TODO: Add your command handler code here
	
	UpdateData(TRUE);
	CString strTmp;
	
	strTmp.Format("GUID: %s\r\nTyp: %s\r\nAnzahl: %d\r\nPreis: %d\r\n",
		m_strGUID, m_strTyp, m_uCount, m_uPrice);

	COleDataSource* pSource = new COleDataSource();
	HGLOBAL hText = ::GlobalAlloc(GMEM_SHARE, strTmp.GetLength() + 1);
	LPSTR lpstrText = (LPSTR)::GlobalLock(hText);
	ASSERT(lpstrText);
	::strcpy(lpstrText, strTmp);
	::GlobalUnlock(hText);
	pSource->CacheGlobalData(CF_TEXT, hText);

	pSource->SetClipboard();

}

void CAcDocView::OnEditCut() 
{
	// TODO: Add your command handler code here
	
	int iCurrSel = m_listbox.GetCurSel();

	if(iCurrSel < 0)
	{
		TRACE("Problem in CAcDocView::OnEditCut() \n");
		return;
	}

	OnEditCopy();
	m_listbox.GetText(iCurrSel, m_strTyp);
	m_listbox.DeleteString(iCurrSel);
	GetDocument()->DeleteElem(m_strTyp);

	InitElem();
}

void CAcDocView::OnEditPaste() 
{
	// TODO: Add your command handler code here
	
	COleDataObject dataObject;

	if(!dataObject.AttachClipboard())
	{
		TRACE("Problem in CAcDocView::OnEditPaste()\n");
		return;
	}

	if(!dataObject.IsDataAvailable(CF_TEXT))
	{
		TRACE("CF_TEXT Format ist nicht verfügbar\n");
		return;
	}

	STGMEDIUM stgmed;
	FORMATETC format;

	format.cfFormat = CF_TEXT;
	format.dwAspect = DVASPECT_CONTENT;
	format.ptd = NULL;
	format.tymed = TYMED_HGLOBAL;
	format.lindex = -1;

	if(!dataObject.GetData(CF_TEXT, &stgmed, &format))
	{
		TRACE("Text ist nicht verfügbar\n");
	}

	HGLOBAL hText = stgmed.hGlobal;

	CString strTmp;
	strTmp = (LPSTR)::GlobalLock(hText);
	::GlobalUnlock(hText);

	CString strID, strTyp, strPrice, strCount;
	UINT uCount, uPrice;
	int iPos0, iPos1;
	
	//== ------- GUID -----------
	iPos0 = strTmp.Find(' '); //== Blank - symbol
	iPos1 = strTmp.Find('\n'); //== Blank - symbol

	if(iPos1 < 0)
		return;

	if(iPos0 < 0) 
		iPos0 = 0;

	strID = strTmp.Mid(iPos0 + 1, iPos1 - iPos0 - 2);

	int iLength = strTmp.GetLength();
	strTmp = strTmp.Right(iLength - iPos1 - 1);

	//== ------- Typ -----------
	iPos0 = strTmp.Find(' '); //== Blank - symbol
	iPos1 = strTmp.Find('\n'); //== Blank - symbol

	if(iPos1 < 0)
		return;

	if(iPos0 < 0) 
		iPos0 = 0;

	strTyp = strTmp.Mid(iPos0 + 1, iPos1 - iPos0 - 2);

	iLength = strTmp.GetLength();
	strTmp = strTmp.Right(iLength - iPos1 - 1);

	//== ------- Anzahl -----------
	iPos0 = strTmp.Find(' '); //== Blank - symbol
	iPos1 = strTmp.Find('\n'); //== Blank - symbol

	if(iPos1 < 0)
		return;

	if(iPos0 < 0) 
		iPos0 = 0;

	strCount = strTmp.Mid(iPos0 + 1, iPos1 - iPos0 - 2);
	uCount = (UINT)::atoi(strCount);

	iLength = strTmp.GetLength();
	strTmp = strTmp.Right(iLength - iPos1 - 1);

	//== ------- Preis -----------
	iPos0 = strTmp.Find(' '); //== Blank - symbol
	iPos1 = strTmp.Find('\n'); //== Blank - symbol

	if(iPos1 < 0)
		iPos1 = strTmp.GetLength();

	if(iPos0 < 0) 
		iPos0 = 0;

	strPrice = strTmp.Mid(iPos0 + 1, iPos1 - iPos0 - 2);

	iLength = strTmp.GetLength();
	strTmp = strTmp.Right(iLength - iPos1 - 1);
	uPrice = (UINT)::atoi(strPrice);

	m_strGUID = strID;
	m_strTyp = strTyp;
	m_uCount = uCount;
	m_uPrice = uPrice;

	UpdateData(FALSE);

}

void CAcDocView::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	COleDataObject dataObject;

	BOOL bEnable = FALSE;
	if((dataObject.AttachClipboard())
		&&(dataObject.IsDataAvailable(CF_TEXT)))
		bEnable = TRUE;

	pCmdUI->Enable(bEnable);	
}
