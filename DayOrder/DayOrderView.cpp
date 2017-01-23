// DayOrderView.cpp : implementation of the CDayOrderView class
//

#include "stdafx.h"
#include "DayOrder.h"

#include "DayOrderDoc.h"
#include "DayOrderView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDayOrderView

IMPLEMENT_DYNCREATE(CDayOrderView, CFormView)

BEGIN_MESSAGE_MAP(CDayOrderView, CFormView)
	//{{AFX_MSG_MAP(CDayOrderView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDayOrderView construction/destruction

CDayOrderView::CDayOrderView()
	: CFormView(CDayOrderView::IDD)
{
	//{{AFX_DATA_INIT(CDayOrderView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here
}

CDayOrderView::~CDayOrderView()
{
}

void CDayOrderView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDayOrderView)
	DDX_Control(pDX, IDC_CALENDAR1, m_calendar);
	DDX_Control(pDX, IDC_INTCIRCUITCTL1, m_circuit);
	//}}AFX_DATA_MAP
}

BOOL CDayOrderView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDayOrderView printing

BOOL CDayOrderView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDayOrderView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDayOrderView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CDayOrderView::OnPrint(CDC* pDC, CPrintInfo*)
{
	// TODO: add code to print the controls
}

/////////////////////////////////////////////////////////////////////////////
// CDayOrderView diagnostics

#ifdef _DEBUG
void CDayOrderView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDayOrderView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDayOrderDoc* CDayOrderView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDayOrderDoc)));
	return (CDayOrderDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDayOrderView message handlers

BEGIN_EVENTSINK_MAP(CDayOrderView, CFormView)
    //{{AFX_EVENTSINK_MAP(CDayOrderView)
	ON_EVENT(CDayOrderView, IDC_INTCIRCUITCTL1, 1 /* NewOrder */, OnNewOrderIntcircuitctl1, VTS_BSTR)
	ON_EVENT(CDayOrderView, IDC_CALENDAR1, -600 /* Click */, OnClickCalendar1, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CDayOrderView::OnNewOrderIntcircuitctl1(LPCTSTR bstrName) 
{
	// TODO: Add your control notification handler code here
	
	for(int i = 0; i < 3; i++)
	{
		m_pDAY_ORDER->sVals[i] = m_circuit.GetCountByIndex(i);
	}	
}

void CDayOrderView::OnClickCalendar1() 
{
	// TODO: Add your control notification handler code here
	
	CDayOrderDoc* pDoc = GetDocument();

	short sTag = m_calendar.GetTag();
	short sMonat = m_calendar.GetMonat();
	short sJahr = m_calendar.GetJahr();

	bool bDayFound = false;
	//== Tag ist in der Liste vorhanden? 
	if(!pDoc->m_oblistDayOrder.IsEmpty())
	{
		POSITION pos = pDoc->m_oblistDayOrder.GetHeadPosition();
		for(pos; pos != NULL && !bDayFound;)
		{
			m_pDAY_ORDER = (DAY_ORDER*)pDoc->m_oblistDayOrder.GetNext(pos);
			ASSERT(m_pDAY_ORDER);

			if((m_pDAY_ORDER->sTag == sTag)&&
				(m_pDAY_ORDER->sMonat == sMonat)&&
				(m_pDAY_ORDER->sJahr == sJahr))
			{
				bDayFound = true;
			}

		}
		
	}
	
	if(!bDayFound)
	{
		//== Tag in der Liste nicht gefunden
		m_pDAY_ORDER = new DAY_ORDER;
		ASSERT(m_pDAY_ORDER);
		
		m_pDAY_ORDER->sTag = sTag;
		m_pDAY_ORDER->sMonat = sMonat;
		m_pDAY_ORDER->sJahr = sJahr;

		for(int i = 0; i < 3; i++)
		{
				m_pDAY_ORDER->sVals[i] = 0;
		}

		pDoc->m_oblistDayOrder.AddHead((CObject*)m_pDAY_ORDER);
	}
	
	for(int i = 0; i < 3; i++)
	{
		m_circuit.SetCountByIndex(i, m_pDAY_ORDER->sVals[i]); 
	}
	m_circuit.Invalidate();

	pDoc->SetModifiedFlag();
}

void CDayOrderView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class

	char szBuf[200];
	CString strFind("CLSID\\{90BB18C2-EF5E-11D1-B890-E90CF092812B}\\Version");

	LONG lSize = sizeof(szBuf);
    if (RegQueryValue( HKEY_CLASSES_ROOT, strFind, (char*)(&szBuf), &lSize) == ERROR_SUCCESS)
    {
		CString strValue = CString(szBuf);

		if(strValue.Find("1.") == 0)
		{
			CString strTmp("Auf Ihrem Computer ist Version 1 vom Steuerelemnt IntCircuitCtl istalliert.\r\n");
			strTmp += CString("Instalieren Sie eine neue Version des Steuerelementes.\r\n");
			strTmp += CString("Anwendung wird geslossen.");
			MessageBox(strTmp);
			AfxGetMainWnd()->PostMessage(WM_CLOSE);
			return;
		}
		
	}
	
	OnClickCalendar1(); 
}
