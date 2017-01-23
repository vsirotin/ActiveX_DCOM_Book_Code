/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Thu Jul 09 20:30:35 1998
 */
/* Compiler settings for DCOMShareServer.idl:
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

#ifndef __DCOMShareServer_h__
#define __DCOMShareServer_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IDCOMShareObj_FWD_DEFINED__
#define __IDCOMShareObj_FWD_DEFINED__
typedef interface IDCOMShareObj IDCOMShareObj;
#endif 	/* __IDCOMShareObj_FWD_DEFINED__ */


#ifndef __IDCOMShareEvents_FWD_DEFINED__
#define __IDCOMShareEvents_FWD_DEFINED__
typedef interface IDCOMShareEvents IDCOMShareEvents;
#endif 	/* __IDCOMShareEvents_FWD_DEFINED__ */


#ifndef __DCOMShareObj_FWD_DEFINED__
#define __DCOMShareObj_FWD_DEFINED__

#ifdef __cplusplus
typedef class DCOMShareObj DCOMShareObj;
#else
typedef struct DCOMShareObj DCOMShareObj;
#endif /* __cplusplus */

#endif 	/* __DCOMShareObj_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IDCOMShareObj_INTERFACE_DEFINED__
#define __IDCOMShareObj_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDCOMShareObj
 * at Thu Jul 09 20:30:35 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IDCOMShareObj;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("0233BB0E-0FA9-11D2-B890-B449FDDB065F")
    IDCOMShareObj : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddValue( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDCOMShareObjVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDCOMShareObj __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDCOMShareObj __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDCOMShareObj __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDCOMShareObj __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDCOMShareObj __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDCOMShareObj __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDCOMShareObj __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddValue )( 
            IDCOMShareObj __RPC_FAR * This);
        
        END_INTERFACE
    } IDCOMShareObjVtbl;

    interface IDCOMShareObj
    {
        CONST_VTBL struct IDCOMShareObjVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDCOMShareObj_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDCOMShareObj_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDCOMShareObj_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDCOMShareObj_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDCOMShareObj_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDCOMShareObj_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDCOMShareObj_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDCOMShareObj_AddValue(This)	\
    (This)->lpVtbl -> AddValue(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDCOMShareObj_AddValue_Proxy( 
    IDCOMShareObj __RPC_FAR * This);


void __RPC_STUB IDCOMShareObj_AddValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDCOMShareObj_INTERFACE_DEFINED__ */


#ifndef __IDCOMShareEvents_INTERFACE_DEFINED__
#define __IDCOMShareEvents_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDCOMShareEvents
 * at Thu Jul 09 20:30:35 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IDCOMShareEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("19443040-112F-11d2-B890-B01ED0509830")
    IDCOMShareEvents : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateState( 
            /* [in] */ long lTransNumb) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDCOMShareEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDCOMShareEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDCOMShareEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDCOMShareEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDCOMShareEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDCOMShareEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDCOMShareEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDCOMShareEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateState )( 
            IDCOMShareEvents __RPC_FAR * This,
            /* [in] */ long lTransNumb);
        
        END_INTERFACE
    } IDCOMShareEventsVtbl;

    interface IDCOMShareEvents
    {
        CONST_VTBL struct IDCOMShareEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDCOMShareEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDCOMShareEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDCOMShareEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDCOMShareEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDCOMShareEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDCOMShareEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDCOMShareEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDCOMShareEvents_UpdateState(This,lTransNumb)	\
    (This)->lpVtbl -> UpdateState(This,lTransNumb)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDCOMShareEvents_UpdateState_Proxy( 
    IDCOMShareEvents __RPC_FAR * This,
    /* [in] */ long lTransNumb);


void __RPC_STUB IDCOMShareEvents_UpdateState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDCOMShareEvents_INTERFACE_DEFINED__ */



#ifndef __DCOMSHARESERVERLib_LIBRARY_DEFINED__
#define __DCOMSHARESERVERLib_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: DCOMSHARESERVERLib
 * at Thu Jul 09 20:30:35 1998
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_DCOMSHARESERVERLib;

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_DCOMShareObj;

class DECLSPEC_UUID("0233BB0F-0FA9-11D2-B890-B449FDDB065F")
DCOMShareObj;
#endif
#endif /* __DCOMSHARESERVERLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
