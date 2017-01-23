// DayOrderDoc.cpp : implementation of the CDayOrderDoc class
//

#include "stdafx.h"
#include "DayOrder.h"

#include "DayOrderDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDayOrderDoc

IMPLEMENT_DYNCREATE(CDayOrderDoc, CDocument)

BEGIN_MESSAGE_MAP(CDayOrderDoc, CDocument)
	//{{AFX_MSG_MAP(CDayOrderDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDayOrderDoc construction/destruction

CDayOrderDoc::CDayOrderDoc()
{
	// TODO: add one-time construction code here

}

CDayOrderDoc::~CDayOrderDoc()
{
	if(!m_oblistDayOrder.IsEmpty())
	{
		DAY_ORDER* pDAY_ORDER;
		POSITION pos, posOld;
		posOld = pos = m_oblistDayOrder.GetHeadPosition();
		for(pos; pos != NULL; posOld = pos)
		{
			pDAY_ORDER = (DAY_ORDER*)m_oblistDayOrder.GetNext(pos);
			m_oblistDayOrder.RemoveAt(posOld);
			
			ASSERT(pDAY_ORDER);
			delete pDAY_ORDER;
		}
	}
	m_oblistDayOrder.RemoveAll();
}

BOOL CDayOrderDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDayOrderDoc serialization

void CDayOrderDoc::Serialize(CArchive& ar)
{
	int iCount;
	if (ar.IsStoring())
	{
		iCount = m_oblistDayOrder.GetCount();

		ar << iCount;
		if(!m_oblistDayOrder.IsEmpty())
		{

			DAY_ORDER* pDAY_ORDER;
			POSITION pos, posOld;
			posOld = pos = m_oblistDayOrder.GetHeadPosition();
			for(pos; pos != NULL; posOld = pos)
			{
				pDAY_ORDER = (DAY_ORDER*)m_oblistDayOrder.GetNext(pos);
				ASSERT(pDAY_ORDER);
				
				ar << pDAY_ORDER->sTag;
				ar << pDAY_ORDER->sMonat;
				ar << pDAY_ORDER->sJahr;

				for(UINT j = 0; j < 3; j++)
				{
					ar << pDAY_ORDER->sVals[j];
				}
			}
		}
	}
	else
	{
		ar >> iCount;
	
		for(int i = 0; i < iCount; i++)
		{
			DAY_ORDER* pDAY_ORDER = new DAY_ORDER;
			ASSERT(pDAY_ORDER);
				
			ar >> pDAY_ORDER->sTag;
			ar >> pDAY_ORDER->sMonat;
			ar >> pDAY_ORDER->sJahr;

			for(int j = 0; j < 3; j++)
			{
				ar >> pDAY_ORDER->sVals[j];
			}
			m_oblistDayOrder.AddHead((CObject*)pDAY_ORDER);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDayOrderDoc diagnostics

#ifdef _DEBUG
void CDayOrderDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDayOrderDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDayOrderDoc commands
