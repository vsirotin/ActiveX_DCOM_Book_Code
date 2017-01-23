//Joballocinterfaces.h
#ifndef _JOBALLOCINTERFACES_H_
#define _JOBALLOCINTERFACES_H_

struct IJobAlloc : public IUnknown
{
public:
	STDMETHOD_(int&, Pause)(int nJob, BSTR bstrReason) = 0;
	STDMETHOD_(int&, NewJob)(BSTR bstrUserName) = 0;
	STDMETHOD (JobOk)(int nJob) = 0;
};


struct IJobInfo : public IUnknown
{
public:
	STDMETHOD_(BSTR&, GetInfo)(int nJob) = 0;
};


// {6E5A3D80-A13A-11d1-A259-00A0C941DD59}
static const IID IID_IJobAlloc = 
{ 0x6e5a3d80, 0xa13a, 0x11d1, { 0xa2, 0x59, 0x0, 0xa0, 0xc9, 0x41, 0xdd, 0x59 } };


// {803C7621-A9D1-11d1-A263-00A0C941DD59}
static const IID IID_IJobInfo = 
{ 0x803c7621, 0xa9d1, 0x11d1, { 0xa2, 0x63, 0x0, 0xa0, 0xc9, 0x41, 0xdd, 0x59 } };

#endif //_JOBALLOCINTERFACES_H_
