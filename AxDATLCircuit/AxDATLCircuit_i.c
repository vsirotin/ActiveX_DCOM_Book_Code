/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.01.75 */
/* at Wed May 27 21:50:05 1998
 */
/* Compiler settings for AxDATLCircuit.idl:
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

const IID IID_IIntCircuitCtl = {0x90BB18C1,0xEF5E,0x11D1,{0xB8,0x90,0xE9,0x0C,0xF0,0x92,0x81,0x2B}};


const IID LIBID_AXDATLCIRCUITLib = {0x17EEE381,0xEDCF,0x11D1,{0xB8,0x90,0xF8,0xED,0x05,0xE1,0x95,0x2C}};


const IID DIID__IntCircuitCtlEvents = {0x844AE600,0xF2F7,0x11d1,{0xB8,0x90,0xBD,0x99,0x6E,0x57,0xC3,0x29}};


const CLSID CLSID_IntCircuitCtl = {0x90BB18C2,0xEF5E,0x11D1,{0xB8,0x90,0xE9,0x0C,0xF0,0x92,0x81,0x2B}};


#ifdef __cplusplus
}
#endif

