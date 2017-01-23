// AxDCommandLineInfo.h : header file

/////////////////////////////////////////////////////////////////////////////
// CAxDCommandLineInfo 
class CAxDCommandLineInfo : public CCommandLineInfo
{

public:

	CAxDCommandLineInfo();    

	virtual void ParseParam( LPCTSTR lpszParam, BOOL bFlag, BOOL bLast );


// Attributes
public:

// Operations

~CAxDCommandLineInfo();

};

/////////////////////////////////////////////////////////////////////////////
