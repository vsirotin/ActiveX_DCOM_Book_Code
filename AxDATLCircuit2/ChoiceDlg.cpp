// ChoiceDlg.cpp : Implementation of CChoiceDlg
#include "stdafx.h"
#include "ChoiceDlg.h"
#include "Chip.h"



/////////////////////////////////////////////////////////////////////////////
// CChoiceDlg

CChoiceDlg::CChoiceDlg()
{
}

CChoiceDlg::~CChoiceDlg()
{
}

LRESULT CChoiceDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if(m_pChip == NULL)
		return -1;

	char cTmp[100];
	
	::wsprintf(cTmp, "%s : %d Ersatzchips vorhanden\n", m_pChip->m_strName, m_pChip->m_sCount);
	HWND hWnd = GetDlgItem(IDC_ORDER_INFO);

	if(hWnd == NULL)
		return -1;

	::SetWindowText(hWnd, cTmp);

	return 1;  // Let the system set the focus
}

LRESULT CChoiceDlg::OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	if(m_pChip == NULL)
		return 0;
	m_pChip->m_sCount--; //== Bestellen

	EndDialog(wID);
	return 0;
}

LRESULT CChoiceDlg::OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	EndDialog(wID);
	return 0;
}

LRESULT CChoiceDlg::OnInfo(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	char cTmp[100];
	
	::wsprintf(cTmp, "c:\\AxDATLCircuitHTMLs\\%s.htm", m_pChip->m_strName);

	HINSTANCE hInstRes = ::ShellExecute(NULL, "open", cTmp, NULL, NULL, SW_SHOW);

	EndDialog(wID);
	return 0;
}

