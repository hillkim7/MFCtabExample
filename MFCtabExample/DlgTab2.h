#pragma once

class CMFCtabExampleDlg;

// CDlgTab2 dialog

class CDlgTab2 : public CDialog
{
	DECLARE_DYNAMIC(CDlgTab2)

public:
	CDlgTab2(CWnd* pParent, CMFCtabExampleDlg* pParentDlg);   // standard constructor
	virtual ~CDlgTab2();

// Dialog Data
	enum { IDD = IDD_TAB2 };

	CMFCtabExampleDlg* m_pParentDlg;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedTab2Button();
	virtual void OnCancel();
	virtual void OnOK();
};
