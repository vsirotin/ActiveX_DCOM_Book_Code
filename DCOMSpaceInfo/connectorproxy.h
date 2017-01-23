// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// IConnector wrapper class

class IConnector : public COleDispatchDriver
{
public:
	IConnector() {}		// Calls COleDispatchDriver default constructor
	IConnector(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IConnector(const IConnector& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetPhysSpaceTotal();
	float GetPhysSpaceAvail();
};
