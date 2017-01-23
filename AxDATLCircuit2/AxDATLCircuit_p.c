/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 3.01.75 */
/* at Thu Jun 11 09:55:52 1998
 */
/* Compiler settings for AxDATLCircuit.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )

#define USE_STUBLESS_PROXY

#include "rpcproxy.h"
#include "AxDATLCircuit.h"

#define TYPE_FORMAT_STRING_SIZE   43                                
#define PROC_FORMAT_STRING_SIZE   163                               

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


/* Object interface: IIntCircuitCtl, ver. 0.0,
   GUID={0x90BB18C1,0xEF5E,0x11D1,{0xB8,0x90,0xE9,0x0C,0xF0,0x92,0x81,0x2B}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IIntCircuitCtl_ServerInfo;

#pragma code_seg(".orpc")
extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[1];

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
    UserMarshalRoutines,
    0,  /* Reserved1 */
    0,  /* Reserved2 */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

static const unsigned short IIntCircuitCtl_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    24,
    48,
    72,
    102,
    132
    };

static const MIDL_SERVER_INFO IIntCircuitCtl_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IIntCircuitCtl_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IIntCircuitCtl_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IIntCircuitCtl_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(13) _IIntCircuitCtlProxyVtbl = 
{
    &IIntCircuitCtl_ProxyInfo,
    &IID_IIntCircuitCtl,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IIntCircuitCtl::put_BackColor */ ,
    (void *)-1 /* IIntCircuitCtl::get_BackColor */ ,
    (void *)-1 /* IIntCircuitCtl::get_IsStockOK */ ,
    (void *)-1 /* IIntCircuitCtl::Count */ ,
    (void *)-1 /* IIntCircuitCtl::get_CountByIndex */ ,
    (void *)-1 /* IIntCircuitCtl::put_CountByIndex */
};


static const PRPC_STUB_FUNCTION IIntCircuitCtl_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IIntCircuitCtlStubVtbl =
{
    &IID_IIntCircuitCtl,
    &IIntCircuitCtl_ServerInfo,
    13,
    &IIntCircuitCtl_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

#pragma data_seg(".rdata")

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[1] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, [wire_marshal] or [user_marshal] attribute.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure put_BackColor */

			0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/*  2 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/*  4 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/*  6 */	NdrFcShort( 0x8 ),	/* 8 */
/*  8 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10 */	0x4,		/* 4 */
			0x2,		/* 2 */

	/* Parameter clr */

/* 12 */	NdrFcShort( 0x48 ),	/* 72 */
#ifndef _ALPHA_
/* 14 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 16 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 18 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 20 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 22 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_BackColor */

/* 24 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 26 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 28 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 30 */	NdrFcShort( 0x0 ),	/* 0 */
/* 32 */	NdrFcShort( 0x10 ),	/* 16 */
/* 34 */	0x4,		/* 4 */
			0x2,		/* 2 */

	/* Parameter pclr */

/* 36 */	NdrFcShort( 0x2150 ),	/* 8528 */
#ifndef _ALPHA_
/* 38 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 40 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 42 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 44 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 46 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IsStockOK */

/* 48 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 50 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 52 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x10 ),	/* 16 */
/* 58 */	0x4,		/* 4 */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 60 */	NdrFcShort( 0x2150 ),	/* 8528 */
#ifndef _ALPHA_
/* 62 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 68 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Count */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 74 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 76 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 78 */	NdrFcShort( 0x0 ),	/* 0 */
/* 80 */	NdrFcShort( 0xe ),	/* 14 */
/* 82 */	0x6,		/* 6 */
			0x3,		/* 3 */

	/* Parameter bstrName */

/* 84 */	NdrFcShort( 0x8b ),	/* 139 */
#ifndef _ALPHA_
/* 86 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 88 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter sCount */

/* 90 */	NdrFcShort( 0x2150 ),	/* 8528 */
#ifndef _ALPHA_
/* 92 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 94 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 96 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 98 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_CountByIndex */

/* 102 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 104 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 106 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 108 */	NdrFcShort( 0x6 ),	/* 6 */
/* 110 */	NdrFcShort( 0xe ),	/* 14 */
/* 112 */	0x4,		/* 4 */
			0x3,		/* 3 */

	/* Parameter sIndex */

/* 114 */	NdrFcShort( 0x48 ),	/* 72 */
#ifndef _ALPHA_
/* 116 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 118 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 120 */	NdrFcShort( 0x2150 ),	/* 8528 */
#ifndef _ALPHA_
/* 122 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 124 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 126 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 128 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_CountByIndex */

/* 132 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 134 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
/* 136 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 138 */	NdrFcShort( 0xc ),	/* 12 */
/* 140 */	NdrFcShort( 0x8 ),	/* 8 */
/* 142 */	0x4,		/* 4 */
			0x3,		/* 3 */

	/* Parameter sIndex */

/* 144 */	NdrFcShort( 0x48 ),	/* 72 */
#ifndef _ALPHA_
/* 146 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 148 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 150 */	NdrFcShort( 0x48 ),	/* 72 */
#ifndef _ALPHA_
/* 152 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 154 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 156 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 158 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  2 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/*  4 */	
			0x12, 0x0,	/* FC_UP */
/*  6 */	NdrFcShort( 0xc ),	/* Offset= 12 (18) */
/*  8 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 10 */	NdrFcShort( 0x2 ),	/* 2 */
/* 12 */	0x9,		/* 9 */
			0x0,		/*  */
/* 14 */	NdrFcShort( 0xfffffffc ),	/* -4 */
/* 16 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 18 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 20 */	NdrFcShort( 0x8 ),	/* 8 */
/* 22 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (8) */
/* 24 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 26 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 28 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 30 */	NdrFcShort( 0x0 ),	/* 0 */
/* 32 */	NdrFcShort( 0x4 ),	/* 4 */
/* 34 */	NdrFcShort( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (4) */
/* 38 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 40 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

const CInterfaceProxyVtbl * _AxDATLCircuit_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IIntCircuitCtlProxyVtbl,
    0
};

const CInterfaceStubVtbl * _AxDATLCircuit_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IIntCircuitCtlStubVtbl,
    0
};

PCInterfaceName const _AxDATLCircuit_InterfaceNamesList[] = 
{
    "IIntCircuitCtl",
    0
};

const IID *  _AxDATLCircuit_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _AxDATLCircuit_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _AxDATLCircuit, pIID, n)

int __stdcall _AxDATLCircuit_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_AxDATLCircuit_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo AxDATLCircuit_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _AxDATLCircuit_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _AxDATLCircuit_StubVtblList,
    (const PCInterfaceName * ) & _AxDATLCircuit_InterfaceNamesList,
    (const IID ** ) & _AxDATLCircuit_BaseIIDList,
    & _AxDATLCircuit_IID_Lookup, 
    1,
    2
};
