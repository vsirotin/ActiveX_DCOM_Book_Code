// DCOMSpaceInfoView.cpp : implementation of the CDCOMSpaceInfoView class
//

#include "stdafx.h"
#include "DCOMSpaceInfo.h"

#include "DCOMSpaceInfoDoc.h"
#include "DCOMSpaceInfoView.h"
#include "CompNameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDCOMSpaceInfoView

IMPLEMENT_DYNCREATE(CDCOMSpaceInfoView, CView)

BEGIN_MESSAGE_MAP(CDCOMSpaceInfoView, CView)
	//{{AFX_MSG_MAP(CDCOMSpaceInfoView)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDCOMSpaceInfoView construction/destruction

CDCOMSpaceInfoView::CDCOMSpaceInfoView()
{
	// TODO: add construction code here
	theApp.m_uClientCount++;
}

CDCOMSpaceInfoView::~CDCOMSpaceInfoView()
{
	POSITION pos;
	float* pfVal;

	for(pos = m_oblistValues.GetHeadPosition(); pos != NULL;)
	{
		pfVal = (float*)m_oblistValues.GetNext(pos);
		delete pfVal;
	}
	
	m_oblistValues.RemoveAll();
	
	theApp.m_uClientCount--;
}

BOOL CDCOMSpaceInfoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDCOMSpaceInfoView drawing

void CDCOMSpaceInfoView::OnDraw(CDC* pDC)
{
	CDCOMSpaceInfoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here


	//== Zu wenig Vermessungen?
	if(m_oblistValues.GetCount() < 1)
	{
		pDC->TextOut(10, 20, m_strObjExist);
		return;
	}

	POINT points[102];

	static int x0 = 20;
	static int y0 = 20;
	static int dx = 300;
	static int dy = 100;
	int x, y;

	points[0] = CPoint(x0 + dx, y0 + dy);

	POSITION pos;
	float* pfVal;
	float fVal, fVal0;
	int i = 0;

	for(pos = m_oblistValues.GetHeadPosition(); pos != NULL;)
	{
		pfVal = (float*)m_oblistValues.GetNext(pos);
		fVal = *pfVal;
		
		if(i == 0)
			fVal0 = fVal; //== Letzte Vermessung

		i++;
		x = x0 + dx - 3*(i - 1);
		y = y0 + (int)(fVal);
		points[i] = CPoint(x, y); 
		

	}

	//== Poligon schließen

	points[++i] = CPoint(x, y0 + dy);
	points[++i] = CPoint(x0 + dx, y0 + dy);
	
	//== Poligon mit der rote Farbe ausfüllen

	CBrush bBrushRed(COLORREF(RGB(200, 0, 0)));
	CBrush* pBrudOld = pDC->SelectObject(&bBrushRed);
	pDC->Polygon(points, i);
	pDC->SelectObject(pBrudOld);
	
	//== Hifslinien

	int yTemp = y0;
	int ddy = dy/4;
	int d = 10;

	for(int j = 1; j < 6; j ++)
	{
		pDC->MoveTo(x0 - d, yTemp);
		pDC->LineTo(x0 + dx + d, yTemp);
		yTemp += ddy;
	}
	pDC->TextOut(x0 + dx + d, y0 + dy/2, CString("50"));
	
	//== Letzte Vermessung (unten)
	CString strTmp;
	strTmp.Format("%d", (int)fVal0);
	pDC->TextOut(x0 + dx - d, y0 + dy + d, strTmp);
}

/////////////////////////////////////////////////////////////////////////////
// CDCOMSpaceInfoView printing

BOOL CDCOMSpaceInfoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDCOMSpaceInfoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDCOMSpaceInfoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDCOMSpaceInfoView diagnostics

#ifdef _DEBUG
void CDCOMSpaceInfoView::AssertValid() const
{
	CView::AssertValid();
}

void CDCOMSpaceInfoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDCOMSpaceInfoDoc* CDCOMSpaceInfoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDCOMSpaceInfoDoc)));
	return (CDCOMSpaceInfoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDCOMSpaceInfoView message handlers

void CDCOMSpaceInfoView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	
	CCompNameDlg dlg;
	dlg.DoModal();
	
	m_strComputerName = dlg.m_strCompName;

	if(dlg.m_strCompName.IsEmpty())
	{
		char cComputerName[100];
		DWORD dwSize = 100;
	
		::GetComputerName(cComputerName, &dwSize);
		m_strComputerName = CString(cComputerName);
	}

	GetDocument()->SetTitle(m_strComputerName);
	
	HRESULT hr;
	COSERVERINFO serverinfo;
	serverinfo.dwReserved1 = 0;
	serverinfo.dwReserved2 = 0;
	serverinfo.pwszName = m_strComputerName.AllocSysString();
	serverinfo.pAuthInfo = NULL;


	CLSID clsid;
	hr = ::CLSIDFromString(L"{EEB6743D-087B-11D2-B890-808E7145DC12}", &clsid);

	MULTI_QI qi = {&IID_IUnknown, NULL, 0};
	hr = ::CoCreateInstanceEx(clsid, NULL,
		CLSCTX_LOCAL_SERVER | CLSCTX_REMOTE_SERVER, &serverinfo, 1, &qi);

	::SysFreeString(serverinfo.pwszName);
	
	if(FAILED(hr) || FAILED(qi.hr))
	{
		m_strObjExist.Format("Server %s nicht gefunden. hr = 0x%x qi.h = 0x%x", 
			m_strComputerName, hr, qi.hr);
		return;
	}
	else
	{
		m_strObjExist.Format("Server auf Computer %s gestartet", m_strComputerName);

		LPUNKNOWN pUnk = (LPUNKNOWN)qi.pItf;
		LPDISPATCH pDisp;
		
		VERIFY(pUnk->QueryInterface(IID_IDispatch, (void**)&pDisp) == S_OK);
	
		ASSERT(pDisp != NULL);
		m_server.AttachDispatch(pDisp);
		m_lSpacePhysTotal = m_server.GetPhysSpaceTotal();

		CString strTmp;
		strTmp.Format("%s Total: %d MB", m_strComputerName, (int)(m_lSpacePhysTotal/1000000)); 
		GetDocument()->SetTitle(strTmp);

		pUnk->Release();

		SetTimer(ID_MY_TIMER, 1000, NULL);
	}
	
}

#define MAX_TIMES 100
void CDCOMSpaceInfoView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

	
	if(nIDEvent == ID_MY_TIMER)
	{
		
		if(m_oblistValues.GetCount() >= MAX_TIMES)
		{
			float* pfVal =  (float*)m_oblistValues.GetTail();
			delete pfVal;
			m_oblistValues.RemoveTail();
		}

		float fSpaceFree = m_server.GetPhysSpaceAvail();

		float* pfVal = new float;
		
		*pfVal = fSpaceFree;
		m_oblistValues.AddHead((CObject*)pfVal);
		Invalidate();
	}
	
	CView::OnTimer(nIDEvent);
}
	
