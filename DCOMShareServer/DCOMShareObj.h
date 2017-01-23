// DCOMShareObj.h : Declaration of the CDCOMShareObj

#ifndef __DCOMSHAREOBJ_H_
#define __DCOMSHAREOBJ_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDCOMShareObj
class ATL_NO_VTABLE CDCOMShareObj : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDCOMShareObj, &CLSID_DCOMShareObj>,
	public IConnectionPointContainerImpl<CDCOMShareObj>,
	public IDispatchImpl<IDCOMShareObj, &IID_IDCOMShareObj, &LIBID_DCOMSHARESERVERLib>,
	public IConnectionPointImpl<CDCOMShareObj, &IID_IDCOMShareEvents>
{
public:
	CDCOMShareObj() 
	{
		InitObj();
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DCOMSHAREOBJ)

BEGIN_COM_MAP(CDCOMShareObj)
	COM_INTERFACE_ENTRY(IDCOMShareObj)
	COM_INTERFACE_ENTRY2(IDispatch, IDCOMShareEvents)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CDCOMShareObj)
	CONNECTION_POINT_ENTRY(IID_IDCOMShareEvents)
END_CONNECTION_POINT_MAP()


// IDCOMShareObj
public:

//== Globaler Zustand und Thread

	static HANDLE m_hThread;
	static unsigned int _stdcall DoLoop(void* p);
//	static unsigned int _cdecl DoLoop(void* p);
	static CComCriticalSection m_critsec;
	
//== Lokale Variable
	int m_iMyNumber;

//== Zusätzliche Methoden

	void FinalRelease();
	void InitGlobalData();
	void InitObj();

	STDMETHOD(AddValue)(void);


// IDCOMShareEvents

	void UpdateState(long lTransNumb);

};

#endif //__DCOMSHAREOBJ_H_
