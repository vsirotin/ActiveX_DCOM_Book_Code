// Connector.cpp : implementation file
//

#include "stdafx.h"
#include "DCOMSpaceInfo.h"
#include "Connector.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConnector

IMPLEMENT_DYNCREATE(CConnector, CCmdTarget)

CCriticalSection CConnector::m_critSect;

CConnector::CConnector()
{
	m_critSect.Lock();
	theApp.m_uSvrCount++;
    m_critSect.Unlock();

	EnableAutomation();
	
	// To keep the application running as long as an OLE automation 
	//	object is active, the constructor calls AfxOleLockApp.
	
	AfxOleLockApp();
}

CConnector::~CConnector()
{
	// To terminate the application when all objects created with
	// 	with OLE automation, the destructor calls AfxOleUnlockApp.

	m_critSect.Lock();
	theApp.m_uSvrCount--;
    m_critSect.Unlock();
	
	AfxOleUnlockApp();
}


void CConnector::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CConnector, CCmdTarget)
	//{{AFX_MSG_MAP(CConnector)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CConnector, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CConnector)
	DISP_FUNCTION(CConnector, "GetPhysSpaceTotal", GetPhysSpaceTotal, VT_I4, VTS_NONE)
	DISP_FUNCTION(CConnector, "GetPhysSpaceAvail", GetPhysSpaceAvail, VT_R4, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IConnector to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {EEB6743C-087B-11D2-B890-808E7145DC12}
static const IID IID_IConnector =
{ 0xeeb6743c, 0x87b, 0x11d2, { 0xb8, 0x90, 0x80, 0x8e, 0x71, 0x45, 0xdc, 0x12 } };

BEGIN_INTERFACE_MAP(CConnector, CCmdTarget)
	INTERFACE_PART(CConnector, IID_IConnector, Dispatch)
END_INTERFACE_MAP()

// {EEB6743D-087B-11D2-B890-808E7145DC12}
IMPLEMENT_OLECREATE(CConnector, "DCOMSpaceInfo.Connector", 0xeeb6743d, 0x87b, 0x11d2, 0xb8, 0x90, 0x80, 0x8e, 0x71, 0x45, 0xdc, 0x12)

/////////////////////////////////////////////////////////////////////////////
// CConnector message handlers

long CConnector::GetPhysSpaceTotal() 
{
	// TODO: Add your dispatch handler code here

	MEMORYSTATUS memstat;
	::GlobalMemoryStatus(&memstat);

	return (long)memstat.dwTotalPhys;
}

float CConnector::GetPhysSpaceAvail() 
{
	// TODO: Add your dispatch handler code here

	MEMORYSTATUS memstat;
	::GlobalMemoryStatus(&memstat);

	return (float)(100*memstat.dwAvailPhys/memstat.dwTotalPhys);
}
