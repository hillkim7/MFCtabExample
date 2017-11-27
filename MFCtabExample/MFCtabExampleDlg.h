
// MFCtabExampleDlg.h : header file
//

#pragma once
#include "afxcmn.h"

#include "DlgTab1.h"
#include "DlgTab2.h"

#include <memory>

// CMFCtabExampleDlg dialog
class CMFCtabExampleDlg : public CDialogEx
{
// Construction
public:
	CMFCtabExampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCTABEXAMPLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	static const size_t N_TABS = 2;
	HICON m_hIcon;
	std::unique_ptr<CDlgTab1> m_dlgTab1;
	std::unique_ptr<CDlgTab2> m_dlgTab2;
	CDialog* m_tabDialogs[N_TABS];
	CTabCtrl m_tabCtrl1;

protected:
	void ShowCurTabDialog();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void SetTabInput(LPCTSTR msg);
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
