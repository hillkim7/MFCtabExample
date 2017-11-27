// DlgTab1.cpp : implementation file
//

#include "stdafx.h"
#include "MFCtabExample.h"
#include "DlgTab1.h"
#include "afxdialogex.h"
#include "MFCtabExampleDlg.h"

// CDlgTab1 dialog

IMPLEMENT_DYNAMIC(CDlgTab1, CDialog)

CDlgTab1::CDlgTab1(CWnd* pParent, CMFCtabExampleDlg* pParentDlg)
	: CDialog(CDlgTab1::IDD, pParent)
	, m_pParentDlg(pParentDlg)
{

}

CDlgTab1::~CDlgTab1()
{
}

void CDlgTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgTab1, CDialog)
	ON_BN_CLICKED(IDC_TAB1_BUTTON, &CDlgTab1::OnBnClickedTab1Button)
END_MESSAGE_MAP()


// CDlgTab1 message handlers

void CDlgTab1::OnBnClickedTab1Button()
{
	CString text;

	GetDlgItemText(IDC_EDIT1, text);
	m_pParentDlg->SetTabInput(text);
}
