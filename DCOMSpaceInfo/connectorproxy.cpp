// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "connectorproxy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// IConnector properties

/////////////////////////////////////////////////////////////////////////////
// IConnector operations

long IConnector::GetPhysSpaceTotal()
{
	long result;
	InvokeHelper(0x1, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

float IConnector::GetPhysSpaceAvail()
{
	float result;
	InvokeHelper(0x2, DISPATCH_METHOD, VT_R4, (void*)&result, NULL);
	return result;
}
