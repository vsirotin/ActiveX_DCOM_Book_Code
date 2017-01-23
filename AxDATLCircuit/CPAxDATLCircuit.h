
//////////////////////////////////////////////////////////////////////////////
// CProxy_IntCircuitCtlEvents
template <class T>
class CProxy_IntCircuitCtlEvents : public IConnectionPointImpl<T, &DIID__IntCircuitCtlEvents, CComDynamicUnkArray>
{
public:
//methods:
//_IntCircuitCtlEvents : IDispatch
public:
	void Fire_NewOrder(
		BSTR bstrName)
	{
		VARIANTARG* pvars = new VARIANTARG[1];
		for (int i = 0; i < 1; i++)
			VariantInit(&pvars[i]);
		T* pT = (T*)this;
		pT->Lock();
		IUnknown** pp = m_vec.begin();
		while (pp < m_vec.end())
		{
			if (*pp != NULL)
			{
				pvars[0].vt = VT_BSTR;
				pvars[0].bstrVal= bstrName;
				DISPPARAMS disp = { pvars, NULL, 1, 0 };
				IDispatch* pDispatch = reinterpret_cast<IDispatch*>(*pp);
				pDispatch->Invoke(0x1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
			pp++;
		}
		pT->Unlock();
		delete[] pvars;
	}

};

