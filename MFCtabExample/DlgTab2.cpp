// DlgTab2.cpp : implementation file
//

#include "stdafx.h"
#include "MFCtabExample.h"
#include "DlgTab2.h"
#include "afxdialogex.h"


// CDlgTab2 dialog

IMPLEMENT_DYNAMIC(CDlgTab2, CDialog)

CDlgTab2::CDlgTab2(CWnd* pParent, CMFCtabExampleDlg* pParentDlg)
	: CDialog(CDlgTab2::IDD, pParent)
	, m_pParentDlg(pParentDlg)
{

}

CDlgTab2::~CDlgTab2()
{
}

void CDlgTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgTab2, CDialog)
	ON_BN_CLICKED(IDC_TAB2_BUTTON, &CDlgTab2::OnBnClickedTab2Button)
END_MESSAGE_MAP()


// CDlgTab2 message handlers


void CDlgTab2::OnBnClickedTab2Button()
{
	// TODO: Add your control notification handler code here
}


void CDlgTab2::OnCancel()
{
	TRACE(_T(__FUNCTION__) _T(": prevent dialog closed by ENTER key\n"));
	//CDialog::OnCancel();
}


void CDlgTab2::OnOK()
{
	TRACE(_T(__FUNCTION__) _T(": prevent dialog closed by ESC key\n"));
	//CDialog::OnCancel();
}
