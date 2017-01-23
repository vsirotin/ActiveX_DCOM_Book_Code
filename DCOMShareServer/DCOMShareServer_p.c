/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 3.01.75 */
/* at Thu Jul 09 20:30:35 1998
 */
/* Compiler settings for DCOMShareServer.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )

#define USE_STUBLESS_PROXY

#include "rpcproxy.h"
#include "DCOMShareServer.h"

#define TYPE_FORMAT_STRING_SIZE   1                                 
#define PROC_FORMAT_STRING_SIZE   43                                

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDCOMShareObj, ver. 0.0,
   GUID={0x0233BB0E,0x0FA9,0x11D2,{0xB8,0x90,0xB4,0x49,0xFD,0xDB,0x06,0x5F}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDCOMShareObj_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IDCOMShareObj_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0
    };

static const MIDL_SERVER_INFO IDCOMShareObj_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IDCOMShareObj_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IDCOMShareObj_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IDCOMShareObj_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(8) _IDCOMShareObjProxyVtbl = 
{
    &IDCOMShareObj_ProxyInfo,
    &IID_IDCOMShareObj,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IDCOMShareObj::AddValue */
};


static const PRPC_STUB_FUNCTION IDCOMShareObj_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IDCOMShareObjStubVtbl =
{
    &IID_IDCOMShareObj,
    &IDCOMShareObj_ServerInfo,
    8,
    &IDCOMShareObj_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IDCOMShareEvents, ver. 0.0,
   GUID={0x19443040,0x112F,0x11d2,{0xB8,0x90,0xB0,0x1E,0xD0,0x50,0x98,0x30}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDCOMShareEvents_ServerInfo;

#pragma code_seg(".orpc")

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    0, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x301004b, /* MIDL Version 3.1.75 */
    0,
    0,
    0,  /* Reserved1 */
    0,  /* Reserved2 */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

static const unsigned short IDCOMShareEvents_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    18
    };

static const MIDL_SERVER_INFO IDCOMShareEvents_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IDCOMShareEvents_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IDCOMShareEvents_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IDCOMShareEvents_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(8) _IDCOMShareEventsProxyVtbl = 
{
    &IDCOMShareEvents_ProxyInfo,
    &IID_IDCOMShareEvents,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IDCOMShareEvents::UpdateState */
};


static const PRPC_STUB_FUNCTION IDCOMShareEvents_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IDCOMShareEventsStubVtbl =
{
    &IID_IDCOMShareEvents,
    &IDCOMShareEvents_ServerInfo,
    8,
    &IDCOMShareEvents_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

#pragma data_seg(".rdata")

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure AddValue */

			0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/*  2 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/*  4 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10 */	0x4,		/* 4 */
			0x1,		/* 1 */

	/* Return value */

/* 12 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 14 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 16 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateState */

/* 18 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 20 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/* 22 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 24 */	NdrFcShort( 0x8 ),	/* 8 */
/* 26 */	NdrFcShort( 0x8 ),	/* 8 */
/* 28 */	0x4,		/* 4 */
			0x2,		/* 2 */

	/* Parameter lTransNumb */

/* 30 */	NdrFcShort( 0x48 ),	/* 72 */
#ifndef _ALPHA_
/* 32 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 36 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 38 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 40 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {

			0x0
        }
    };

const CInterfaceProxyVtbl * _DCOMShareServer_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IDCOMShareObjProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDCOMShareEventsProxyVtbl,
    0
};

const CInterfaceStubVtbl * _DCOMShareServer_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IDCOMShareObjStubVtbl,
    ( CInterfaceStubVtbl *) &_IDCOMShareEventsStubVtbl,
    0
};

PCInterfaceName const _DCOMShareServer_InterfaceNamesList[] = 
{
    "IDCOMShareObj",
    "IDCOMShareEvents",
    0
};

const IID *  _DCOMShareServer_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _DCOMShareServer_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _DCOMShareServer, pIID, n)

int __stdcall _DCOMShareServer_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _DCOMShareServer, 2, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _DCOMShareServer, 2, *pIndex )
    
}

const ExtendedProxyFileInfo DCOMShareServer_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _DCOMShareServer_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _DCOMShareServer_StubVtblList,
    (const PCInterfaceName * ) & _DCOMShareServer_InterfaceNamesList,
    (const IID ** ) & _DCOMShareServer_BaseIIDList,
    & _DCOMShareServer_IID_Lookup, 
    2,
    2
};
