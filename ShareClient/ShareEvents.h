// ShareEvents.h: interface for the CShareEvents class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHAREEVENTS_H__71E16CE1_144A_11D2_B890_83020B4236AE__INCLUDED_)
#define AFX_SHAREEVENTS_H__71E16CE1_144A_11D2_B890_83020B4236AE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CShareEvents:
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IDCOMShareEvents, &IID_IDCOMShareEvents, &LIBID_DCOMSHARESERVERLib>
{
public:
	CShareEvents();
	
	BEGIN_COM_MAP(CShareEvents)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IDCOMShareEvents)
	END_COM_MAP()

	STDMETHOD(UpdateState)(long lLastTran);

};

#endif // !defined(AFX_SHAREEVENTS_H__71E16CE1_144A_11D2_B890_83020B4236AE__INCLUDED_)
