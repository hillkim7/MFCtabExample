
// MFCtabExampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCtabExample.h"
#include "MFCtabExampleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCtabExampleDlg dialog



CMFCtabExampleDlg::CMFCtabExampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCtabExampleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCtabExampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tabCtrl1);
}

BEGIN_MESSAGE_MAP(CMFCtabExampleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMFCtabExampleDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CMFCtabExampleDlg message handlers

void CMFCtabExampleDlg::ShowCurTabDialog()
{
	for (size_t i = 0; i < N_TABS; ++i)
	{
		if (i == (size_t)m_tabCtrl1.GetCurSel())
			m_tabDialogs[i]->ShowWindow(SW_SHOW);
		else
			m_tabDialogs[i]->ShowWindow(SW_HIDE);
	}
}

BOOL CMFCtabExampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_tabCtrl1.InsertItem(0, _T("Tab1"));
	m_tabCtrl1.InsertItem(1, _T("Tab2"));

	// Compute tab area
	CRect tabRect, itemRect;
	int nX, nY, nXc, nYc;

	m_tabCtrl1.GetClientRect(&tabRect);
	m_tabCtrl1.GetItemRect(0, &itemRect);

	nX = itemRect.left;
	nY = itemRect.bottom + 1;
	nXc = tabRect.right - itemRect.left - 1;
	nYc = tabRect.bottom - nY - 1;

	m_dlgTab1.reset(new CDlgTab1());
	m_dlgTab1->Create(CDlgTab1::IDD, &m_tabCtrl1);
	m_dlgTab1->SetWindowPos(NULL, nX, nY, nXc, nYc, SWP_NOOWNERZORDER);
	m_tabDialogs[0] = m_dlgTab1.get();
	m_dlgTab2.reset(new CDlgTab2());
	m_dlgTab2->Create(CDlgTab2::IDD, &m_tabCtrl1);
	m_dlgTab2->SetWindowPos(NULL, nX, nY, nXc, nYc, SWP_NOOWNERZORDER);
	m_tabDialogs[1] = m_dlgTab2.get();

	m_tabCtrl1.SetCurSel(0);
	ShowCurTabDialog();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCtabExampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCtabExampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCtabExampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCtabExampleDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	ShowCurTabDialog();

	*pResult = 0;
}
