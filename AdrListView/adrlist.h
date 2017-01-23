// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// IAdrList wrapper class

class IAdrList : public COleDispatchDriver
{
public:
	IAdrList() {}		// Calls COleDispatchDriver default constructor
	IAdrList(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IAdrList(const IAdrList& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:
	CString GetName();
	void SetName(LPCTSTR);
	CString GetStrasse();
	void SetStrasse(LPCTSTR);
	CString GetPlz();
	void SetPlz(LPCTSTR);

// Operations
public:
	BOOL Next();
};
