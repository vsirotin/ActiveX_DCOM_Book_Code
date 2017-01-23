// RoomWWWView.cpp : implementation of the CRoomWWWView class
//

#include "stdafx.h"
#include "RoomWWW.h"

#include "RoomWWWDoc.h"
#include "RoomWWWView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRoomWWWView

IMPLEMENT_DYNCREATE(CRoomWWWView, CView)

BEGIN_MESSAGE_MAP(CRoomWWWView, CView)
	//{{AFX_MSG_MAP(CRoomWWWView)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

BEGIN_EVENTSINK_MAP(CRoomWWWView, CView)
	ON_EVENT(CRoomWWWView, ID_TEAM_ROOM, 2, OnFireClickInRoom, VTS_BSTR)
END_EVENTSINK_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoomWWWView construction/destruction

CRoomWWWView::CRoomWWWView()
{
	// TODO: add construction code here

}

CRoomWWWView::~CRoomWWWView()
{
}

BOOL CRoomWWWView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRoomWWWView drawing

void CRoomWWWView::OnDraw(CDC* pDC)
{
	CRoomWWWDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CRoomWWWView printing

BOOL CRoomWWWView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRoomWWWView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRoomWWWView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRoomWWWView diagnostics

#ifdef _DEBUG
void CRoomWWWView::AssertValid() const
{
	CView::AssertValid();
}

void CRoomWWWView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRoomWWWDoc* CRoomWWWView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRoomWWWDoc)));
	return (CRoomWWWDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRoomWWWView message handlers

CString g_strWWWPath("C:\\AxDWWWRoomHTMLs\\"); 
CRoomWWWView* pViewWithBrowser = NULL;
int CRoomWWWView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here

	static UINT uViewNumb = 0; 
	
	DWORD dwStyle = WS_VISIBLE|WS_CHILD;

	//== TeamRoom Spalte

	if( uViewNumb++ == 0)
	{
		if (m_teamroom.Create(NULL, dwStyle, CRect(0, 0, 200, 300),
			this, ID_TEAM_ROOM) == 0)
		{
			TRACE("Problem beim Anlegen TeamRoom\n");
			return -1;
		}

		//== Festlegen der Geometrie

		m_teamroom.Room(0, 10, 20, 0, 20, 5);
		m_teamroom.SetName(0, "Vertrieb");
		
		m_teamroom.Room(0, 40, 40, 25, 35, 25);
		m_teamroom.SetName(1, "Entwicklung");

		m_teamroom.Room(0, 25, 20, 10, 20, 17);
		m_teamroom.SetName(2, "Leiter");
		
		return 0;

	}
	
	//== WebBrowser Control Spalte

	if (m_webbrowser.Create(NULL, dwStyle, CRect(0, 0, 2000, 2000),
			this, ID_WEBBROWSER) == 0)
		{
			TRACE("Problem beim Anlegen WebBrowser\n");
			return -1;
		}

	pViewWithBrowser = this;
	static CString strWWWdefault = g_strWWWPath + CString("default.htm"); 
	m_webbrowser.Navigate(strWWWdefault, NULL, NULL, NULL, NULL);
	return 0;
}


void CRoomWWWView::OnFireClickInRoom(LPCTSTR strText)
{
	CString strWWW = g_strWWWPath + CString(strText) + CString(".htm") ; 
	ASSERT(pViewWithBrowser);
	pViewWithBrowser->m_webbrowser.Navigate(strWWW, NULL, NULL, NULL, NULL);
}
