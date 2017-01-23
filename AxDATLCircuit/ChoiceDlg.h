// ChoiceDlg.h : Declaration of the CChoiceDlg

#ifndef __CHOICEDLG_H_
#define __CHOICEDLG_H_

#include "resource.h"       // main symbols

class CChip;
/////////////////////////////////////////////////////////////////////////////
// CChoiceDlg
class CChoiceDlg : 
	public CDialogImpl<CChoiceDlg>
{
public:
	CChoiceDlg();
	~CChoiceDlg();

	enum { IDD = IDD_CHOICEDLG };

BEGIN_MSG_MAP(CChoiceDlg)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	COMMAND_ID_HANDLER(IDOK, OnOK)
	COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
	COMMAND_ID_HANDLER(IDC_INFO, OnInfo)
END_MSG_MAP()

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnInfo(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

	CChip* m_pChip;
};

#endif //__CHOICEDLG_H_
