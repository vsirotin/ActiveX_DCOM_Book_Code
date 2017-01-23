// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "adrlist.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// IAdrList properties

CString IAdrList::GetName()
{
	CString result;
	GetProperty(0x1, VT_BSTR, (void*)&result);
	return result;
}

void IAdrList::SetName(LPCTSTR propVal)
{
	SetProperty(0x1, VT_BSTR, propVal);
}

CString IAdrList::GetStrasse()
{
	CString result;
	GetProperty(0x3, VT_BSTR, (void*)&result);
	return result;
}

void IAdrList::SetStrasse(LPCTSTR propVal)
{
	SetProperty(0x3, VT_BSTR, propVal);
}

CString IAdrList::GetPlz()
{
	CString result;
	GetProperty(0x2, VT_BSTR, (void*)&result);
	return result;
}

void IAdrList::SetPlz(LPCTSTR propVal)
{
	SetProperty(0x2, VT_BSTR, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// IAdrList operations

BOOL IAdrList::Next()
{
	BOOL result;
	InvokeHelper(0x4, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}
