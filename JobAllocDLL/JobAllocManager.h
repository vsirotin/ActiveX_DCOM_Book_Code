#ifndef _JOBALLOCMANAGER_H_
#define _JOBALLOCMANAGER_H_

// JobAllocManager.h : header file

class AFX_EXT_CLASS CJobAllocManager 
{
public:
	CJobAllocManager();           // protected constructor used by dynamic creation
	~CJobAllocManager();


	// Attributes
public:
	
	UINT m_nCurrJob;
// Operations
public:

	LRESULT Pause(UINT nJob, CString strReason);
	LRESULT NewJob(CString strUserName);
	void JobOk(UINT nJob);


};

#endif _JOBALLOCMANAGER_H_

/////////////////////////////////////////////////////////////////////////////

