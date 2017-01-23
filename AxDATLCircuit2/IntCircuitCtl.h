// IntCircuitCtl.h : Declaration of the CIntCircuitCtl

#ifndef __INTCIRCUITCTL_H_
#define __INTCIRCUITCTL_H_

#include "resource.h"       // main symbols
#include "CPAxDATLCircuit.h"

class CChip;
/////////////////////////////////////////////////////////////////////////////
// CIntCircuitCtl
class ATL_NO_VTABLE CIntCircuitCtl : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CIntCircuitCtl, &CLSID_IntCircuitCtl>,
	public CComControl<CIntCircuitCtl>,
	public CStockPropImpl<CIntCircuitCtl, IIntCircuitCtl, &IID_IIntCircuitCtl, &LIBID_AXDATLCIRCUITLib>,
	public IProvideClassInfo2Impl<&CLSID_IntCircuitCtl, &DIID__IntCircuitCtlEvents, &LIBID_AXDATLCIRCUITLib>,
	public IPersistStreamInitImpl<CIntCircuitCtl>,
	public IPersistStorageImpl<CIntCircuitCtl>,
	public IQuickActivateImpl<CIntCircuitCtl>,
	public IOleControlImpl<CIntCircuitCtl>,
	public IOleObjectImpl<CIntCircuitCtl>,
	public IOleInPlaceActiveObjectImpl<CIntCircuitCtl>,
	public IViewObjectExImpl<CIntCircuitCtl>,
	public IOleInPlaceObjectWindowlessImpl<CIntCircuitCtl>,
	public IDataObjectImpl<CIntCircuitCtl>,
	public ISupportErrorInfo,
	public ISpecifyPropertyPagesImpl<CIntCircuitCtl>,
	public CProxy_IntCircuitCtlEvents<CIntCircuitCtl>,
	public IConnectionPointContainerImpl<CIntCircuitCtl>,
	public IObjectSafetyImpl<CIntCircuitCtl>
{
public:
	CIntCircuitCtl()
	{	
		m_bWindowOnly = TRUE; 

		m_clrBackColor = RGB(240, 240, 240);
		m_rectGabarit.left = 0;
		m_rectGabarit.top = 0;
		m_rectGabarit.right = 0;
		m_rectGabarit.bottom = 0;

		SetSampleData();
 
	}

DECLARE_REGISTRY_RESOURCEID(IDR_INTCIRCUITCTL)

BEGIN_COM_MAP(CIntCircuitCtl)
	COM_INTERFACE_ENTRY(IIntCircuitCtl)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY_IMPL(IViewObjectEx)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IViewObject2, IViewObjectEx)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IViewObject, IViewObjectEx)
	COM_INTERFACE_ENTRY_IMPL(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IOleInPlaceObject, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY_IMPL(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY_IMPL(IOleControl)
	COM_INTERFACE_ENTRY_IMPL(IOleObject)
	COM_INTERFACE_ENTRY_IMPL(IQuickActivate)
	COM_INTERFACE_ENTRY_IMPL(IPersistStorage)
	COM_INTERFACE_ENTRY_IMPL(IPersistStreamInit)
	COM_INTERFACE_ENTRY_IMPL(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY_IMPL(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_IMPL(IObjectSafety)
END_COM_MAP()


BEGIN_CONNECTION_POINT_MAP(CIntCircuitCtl)
	CONNECTION_POINT_ENTRY(DIID__IntCircuitCtlEvents)
END_CONNECTION_POINT_MAP()


BEGIN_PROPERTY_MAP(CIntCircuitCtl)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	PROP_PAGE(CLSID_StockColorPage)
END_PROPERTY_MAP()


BEGIN_MSG_MAP(CIntCircuitCtl)
	MESSAGE_HANDLER(WM_PAINT, OnPaint)
	MESSAGE_HANDLER(WM_SETFOCUS, OnSetFocus)
	MESSAGE_HANDLER(WM_KILLFOCUS, OnKillFocus)
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
END_MSG_MAP()


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IViewObjectEx
	STDMETHOD(GetViewStatus)(DWORD* pdwStatus)
	{
		ATLTRACE(_T("IViewObjectExImpl::GetViewStatus\n"));
		*pdwStatus = VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE;
		return S_OK;
	}

// IIntCircuitCtl
public:
	HRESULT OnDraw(ATL_DRAWINFO& di);
	LRESULT CIntCircuitCtl::OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHanled);

	OLE_COLOR m_clrBackColor;

//== Attributes:
private:

	CChip* m_pChipsArr[5];

	UINT m_uCountChip;
	RECT m_rectGabarit;

public:	
	STDMETHOD(get_CountByIndex)(/*[in]*/ short sIndex, /*[out, retval]*/ short *pVal);
	STDMETHOD(put_CountByIndex)(/*[in]*/ short sIndex, /*[in]*/ short newVal);
	STDMETHOD(Count)(/*[in]*/ BSTR bstrName, /*[out, retval]*/ short* sCount);
	STDMETHOD(get_IsStockOK)(/*[out, retval]*/ BOOL *pVal);

	
//== Operations:
	void FinalRelease();
	void SetSampleData();
	void UpdateGabRect(const RECT& newRect);

};

#endif //__INTCIRCUITCTL_H_
