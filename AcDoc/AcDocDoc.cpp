// AcDocDoc.cpp : implementation of the CAcDocDoc class
//

#include "stdafx.h"
#include "AcDoc.h"

#include "AcDocDoc.h"
#include "CntrItem.h"
#include "SrvrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAcDocDoc

IMPLEMENT_DYNCREATE(CAcDocDoc, COleServerDoc)

BEGIN_MESSAGE_MAP(CAcDocDoc, COleServerDoc)
	//{{AFX_MSG_MAP(CAcDocDoc)
	//}}AFX_MSG_MAP
	// Enable default OLE container implementation
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, COleServerDoc::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, COleServerDoc::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, COleServerDoc::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, COleServerDoc::OnEditConvert)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, COleServerDoc::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, COleServerDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI(ID_OLE_VERB_FIRST, COleServerDoc::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAcDocDoc construction/destruction

CAcDocDoc::CAcDocDoc()
{
	// Use OLE compound files
	EnableCompoundFile();

	// TODO: add one-time construction code here

}

CAcDocDoc::~CAcDocDoc()
{
	if(!m_oblistElems.IsEmpty())
	{
		ELEM* pELEM;
		POSITION pos, posOld;
		posOld = pos = m_oblistElems.GetHeadPosition();
		for(pos; pos != NULL; posOld = pos)
		{
			pELEM = (ELEM*)m_oblistElems.GetNext(pos);
			m_oblistElems.RemoveAt(posOld);
			
			ASSERT(pELEM);
			delete pELEM;
		}
	}
	m_oblistElems.RemoveAll();
}

BOOL CAcDocDoc::OnNewDocument()
{
	if (!COleServerDoc::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAcDocDoc server implementation

COleServerItem* CAcDocDoc::OnGetEmbeddedItem()
{
	// OnGetEmbeddedItem is called by the framework to get the COleServerItem
	//  that is associated with the document.  It is only called when necessary.

	CAcDocSrvrItem* pItem = new CAcDocSrvrItem(this);
	ASSERT_VALID(pItem);
	return pItem;
}

/////////////////////////////////////////////////////////////////////////////
// CAcDocDoc ActiveX Document server implementation

CDocObjectServer *CAcDocDoc::GetDocObjectServer(LPOLEDOCUMENTSITE pDocSite)
{
	return new CDocObjectServer(this, pDocSite);
}



/////////////////////////////////////////////////////////////////////////////
// CAcDocDoc serialization

void CAcDocDoc::Serialize(CArchive& ar)
{
	int iCount;
	if (ar.IsStoring())
	{
		iCount = m_oblistElems.GetCount();

		ar << iCount;
		if(!m_oblistElems.IsEmpty())
		{

			ELEM* pELEM;
			POSITION pos, posOld;
			posOld = pos = m_oblistElems.GetHeadPosition();
			for(pos; pos != NULL; posOld = pos)
			{
				pELEM = (ELEM*)m_oblistElems.GetNext(pos);
				ASSERT(pELEM);
				
				ar << pELEM->strGUID;
				ar << pELEM->strTyp;
				ar << pELEM->uCount;
				ar << pELEM->uPrice;

			}
		}
	}
	else
	{
		ar >> iCount;
	
		for(int i = 0; i < iCount; i++)
		{
			ELEM* pELEM = new ELEM;
			ASSERT(pELEM);

			ar >> pELEM->strGUID;
			ar >> pELEM->strTyp;
			ar >> pELEM->uCount;
			ar >> pELEM->uPrice;
			m_oblistElems.AddHead((CObject*)pELEM);
		}

	}

	// Calling the base class COleServerDoc enables serialization
	//  of the container document's COleClientItem objects.
	COleServerDoc::Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CAcDocDoc diagnostics

#ifdef _DEBUG
void CAcDocDoc::AssertValid() const
{
	COleServerDoc::AssertValid();
}

void CAcDocDoc::Dump(CDumpContext& dc) const
{
	COleServerDoc::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAcDocDoc commands

void CAcDocDoc::InsertElem(CString strGUID, const CString& strTyp, UINT uCount, UINT uPrice)
{
	ELEM* pELEM = new ELEM;
	ASSERT(pELEM);

	pELEM->strGUID = strGUID;
	pELEM->strTyp = CString(strTyp);
	pELEM->uCount = uCount;
	pELEM->uPrice = uPrice;
	m_oblistElems.AddHead((CObject*)pELEM);

	SetModifiedFlag(TRUE);
}


void CAcDocDoc::UpdateElem(CString strGUID, const CString& strTyp, UINT uCount, UINT uPrice)
{
	if(!m_oblistElems.IsEmpty())
	{

		ELEM* pELEM = NULL;
		POSITION pos, posOld;
		posOld = pos = m_oblistElems.GetHeadPosition();
		for(pos; pos != NULL; posOld = pos)
		{
			pELEM = (ELEM*)m_oblistElems.GetNext(pos);
			ASSERT(pELEM);
			
			if(pELEM->strGUID.CompareNoCase(strGUID) == 0)
			{
				pELEM->uCount += uCount;
				pELEM->uPrice += uPrice;
				SetModifiedFlag(TRUE);
				return;
			}
		}
	}

	TRACE("Element %s nicht gefunden!\n", strTyp);
	
}


bool CAcDocDoc::GetElem(const CString& strTyp, CString* pstrGUID,UINT* puCount, UINT* puPrice)
{
	if(!m_oblistElems.IsEmpty())
	{

		ELEM* pELEM = NULL;
		POSITION pos, posOld;
		posOld = pos = m_oblistElems.GetHeadPosition();
		for(pos; pos != NULL; posOld = pos)
		{
			pELEM = (ELEM*)m_oblistElems.GetNext(pos);
			ASSERT(pELEM);
			
			if(pELEM->strTyp.CompareNoCase(strTyp) == 0)
			{
				*pstrGUID = pELEM->strGUID;
				*puCount = pELEM->uCount;
				*puPrice = pELEM->uPrice;
				return true;
			}
		}
	}

	TRACE("Element %s nicht gefunden!\n", strTyp);

	return false;
}

bool CAcDocDoc::DeleteElem(const CString& strTyp)
{
	if(!m_oblistElems.IsEmpty())
	{

		ELEM* pELEM = NULL;
		POSITION pos, posOld;
		posOld = pos = m_oblistElems.GetHeadPosition();
		for(pos; pos != NULL; posOld = pos)
		{
			pELEM = (ELEM*)m_oblistElems.GetNext(pos);
			ASSERT(pELEM);
			
			if(pELEM->strTyp.CompareNoCase(strTyp) == 0)
			{
				m_oblistElems.RemoveAt(posOld);
			
				ASSERT(pELEM);
				delete pELEM;
				SetModifiedFlag(TRUE);
				return true;
			}
		}
	}

	
	TRACE("Element %s nicht gefunden!\n", strTyp);

	return false;
}

