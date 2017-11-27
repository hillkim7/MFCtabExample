#pragma once

class CMFCtabExampleDlg;

// CDlgTab1 dialog

class CDlgTab1 : public CDialog
{
	DECLARE_DYNAMIC(CDlgTab1)

public:
	CDlgTab1(CWnd* pParent, CMFCtabExampleDlg* pParentDlg);   // standard constructor
	virtual ~CDlgTab1();

// Dialog Data
	enum { IDD = IDD_TAB1 };

	CMFCtabExampleDlg* m_pParentDlg;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedTab1Button();
	virtual void OnOK();
	virtual void OnCancel();
};
