/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Wed May 27 21:50:05 1998
 */
/* Compiler settings for AxDATLCircuit.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __AxDATLCircuit_h__
#define __AxDATLCircuit_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IIntCircuitCtl_FWD_DEFINED__
#define __IIntCircuitCtl_FWD_DEFINED__
typedef interface IIntCircuitCtl IIntCircuitCtl;
#endif 	/* __IIntCircuitCtl_FWD_DEFINED__ */


#ifndef ___IntCircuitCtlEvents_FWD_DEFINED__
#define ___IntCircuitCtlEvents_FWD_DEFINED__
typedef interface _IntCircuitCtlEvents _IntCircuitCtlEvents;
#endif 	/* ___IntCircuitCtlEvents_FWD_DEFINED__ */


#ifndef __IntCircuitCtl_FWD_DEFINED__
#define __IntCircuitCtl_FWD_DEFINED__

#ifdef __cplusplus
typedef class IntCircuitCtl IntCircuitCtl;
#else
typedef struct IntCircuitCtl IntCircuitCtl;
#endif /* __cplusplus */

#endif 	/* __IntCircuitCtl_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IIntCircuitCtl_INTERFACE_DEFINED__
#define __IIntCircuitCtl_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IIntCircuitCtl
 * at Wed May 27 21:50:05 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IIntCircuitCtl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("90BB18C1-EF5E-11D1-B890-E90CF092812B")
    IIntCircuitCtl : public IDispatch
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BackColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsStockOK( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Count( 
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ short __RPC_FAR *sCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIntCircuitCtlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIntCircuitCtl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIntCircuitCtl __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIntCircuitCtl __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IIntCircuitCtl __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IIntCircuitCtl __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IIntCircuitCtl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IIntCircuitCtl __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BackColor )( 
            IIntCircuitCtl __RPC_FAR * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BackColor )( 
            IIntCircuitCtl __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsStockOK )( 
            IIntCircuitCtl __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Count )( 
            IIntCircuitCtl __RPC_FAR * This,
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ short __RPC_FAR *sCount);
        
        END_INTERFACE
    } IIntCircuitCtlVtbl;

    interface IIntCircuitCtl
    {
        CONST_VTBL struct IIntCircuitCtlVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIntCircuitCtl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIntCircuitCtl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIntCircuitCtl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIntCircuitCtl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IIntCircuitCtl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IIntCircuitCtl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IIntCircuitCtl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IIntCircuitCtl_put_BackColor(This,clr)	\
    (This)->lpVtbl -> put_BackColor(This,clr)

#define IIntCircuitCtl_get_BackColor(This,pclr)	\
    (This)->lpVtbl -> get_BackColor(This,pclr)

#define IIntCircuitCtl_get_IsStockOK(This,pVal)	\
    (This)->lpVtbl -> get_IsStockOK(This,pVal)

#define IIntCircuitCtl_Count(This,bstrName,sCount)	\
    (This)->lpVtbl -> Count(This,bstrName,sCount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propput] */ HRESULT STDMETHODCALLTYPE IIntCircuitCtl_put_BackColor_Proxy( 
    IIntCircuitCtl __RPC_FAR * This,
    /* [in] */ OLE_COLOR clr);


void __RPC_STUB IIntCircuitCtl_put_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IIntCircuitCtl_get_BackColor_Proxy( 
    IIntCircuitCtl __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);


void __RPC_STUB IIntCircuitCtl_get_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIntCircuitCtl_get_IsStockOK_Proxy( 
    IIntCircuitCtl __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IIntCircuitCtl_get_IsStockOK_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIntCircuitCtl_Count_Proxy( 
    IIntCircuitCtl __RPC_FAR * This,
    /* [in] */ BSTR bstrName,
    /* [retval][out] */ short __RPC_FAR *sCount);


void __RPC_STUB IIntCircuitCtl_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIntCircuitCtl_INTERFACE_DEFINED__ */



#ifndef __AXDATLCIRCUITLib_LIBRARY_DEFINED__
#define __AXDATLCIRCUITLib_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: AXDATLCIRCUITLib
 * at Wed May 27 21:50:05 1998
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_AXDATLCIRCUITLib;

#ifndef ___IntCircuitCtlEvents_DISPINTERFACE_DEFINED__
#define ___IntCircuitCtlEvents_DISPINTERFACE_DEFINED__

/****************************************
 * Generated header for dispinterface: _IntCircuitCtlEvents
 * at Wed May 27 21:50:05 1998
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][uuid] */ 



EXTERN_C const IID DIID__IntCircuitCtlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    interface DECLSPEC_UUID("844AE600-F2F7-11d1-B890-BD996E57C329")
    _IntCircuitCtlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IntCircuitCtlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IntCircuitCtlEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IntCircuitCtlEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IntCircuitCtlEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IntCircuitCtlEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IntCircuitCtlEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IntCircuitCtlEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IntCircuitCtlEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IntCircuitCtlEventsVtbl;

    interface _IntCircuitCtlEvents
    {
        CONST_VTBL struct _IntCircuitCtlEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IntCircuitCtlEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IntCircuitCtlEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IntCircuitCtlEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IntCircuitCtlEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IntCircuitCtlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IntCircuitCtlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IntCircuitCtlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IntCircuitCtlEvents_DISPINTERFACE_DEFINED__ */


#ifdef __cplusplus
EXTERN_C const CLSID CLSID_IntCircuitCtl;

class DECLSPEC_UUID("90BB18C2-EF5E-11D1-B890-E90CF092812B")
IntCircuitCtl;
#endif
#endif /* __AXDATLCIRCUITLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
