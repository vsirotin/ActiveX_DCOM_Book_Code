/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.01.75 */
/* at Thu Jul 09 20:30:35 1998
 */
/* Compiler settings for DCOMShareServer.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IDCOMShareObj = {0x0233BB0E,0x0FA9,0x11D2,{0xB8,0x90,0xB4,0x49,0xFD,0xDB,0x06,0x5F}};


const IID IID_IDCOMShareEvents = {0x19443040,0x112F,0x11d2,{0xB8,0x90,0xB0,0x1E,0xD0,0x50,0x98,0x30}};


const IID LIBID_DCOMSHARESERVERLib = {0x0233BB01,0x0FA9,0x11D2,{0xB8,0x90,0xB4,0x49,0xFD,0xDB,0x06,0x5F}};


const CLSID CLSID_DCOMShareObj = {0x0233BB0F,0x0FA9,0x11D2,{0xB8,0x90,0xB4,0x49,0xFD,0xDB,0x06,0x5F}};


#ifdef __cplusplus
}
#endif

