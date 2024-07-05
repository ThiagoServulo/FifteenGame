
// FifteenGameDlg.cpp : implementation file
//

#include <iostream>
#include <algorithm>
#include "pch.h"
#include "framework.h"
#include "FifteenGame.h"
#include "FifteenGameDlg.h"
#include "afxdialogex.h"
#include <random>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};


CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}


void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFifteenGameDlg dialog



CFifteenGameDlg::CFifteenGameDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FIFTEENGAME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CFifteenGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_A, value_button_a);
	DDX_Control(pDX, IDC_BUTTON_B, value_button_b);
	DDX_Control(pDX, IDC_BUTTON_C, value_button_c);
	DDX_Control(pDX, IDC_BUTTON_D, value_button_d);
	DDX_Control(pDX, IDC_BUTTON_E, value_button_e);
	DDX_Control(pDX, IDC_BUTTON_F, value_button_f);
	DDX_Control(pDX, IDC_BUTTON_G, value_button_g);
	DDX_Control(pDX, IDC_BUTTON_H, value_button_h);
	DDX_Control(pDX, IDC_BUTTON_I, value_button_i);
	DDX_Control(pDX, IDC_BUTTON_J, value_button_j);
	DDX_Control(pDX, IDC_BUTTON_K, value_button_k);
	DDX_Control(pDX, IDC_BUTTON_L, value_button_l);
	DDX_Control(pDX, IDC_BUTTON_M, value_button_m);
	DDX_Control(pDX, IDC_BUTTON_N, value_button_n);
	DDX_Control(pDX, IDC_BUTTON_O, value_button_o);
	DDX_Control(pDX, IDC_BUTTON_P, value_button_p);
}

BEGIN_MESSAGE_MAP(CFifteenGameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_A, &CFifteenGameDlg::OnBnClickedButtonA)
	ON_BN_CLICKED(IDC_BUTTON_B, &CFifteenGameDlg::OnBnClickedButtonB)
	ON_BN_CLICKED(IDC_BUTTON_C, &CFifteenGameDlg::OnBnClickedButtonC)
	ON_BN_CLICKED(IDC_BUTTON_D, &CFifteenGameDlg::OnBnClickedButtonD)
	ON_BN_CLICKED(IDC_BUTTON_E, &CFifteenGameDlg::OnBnClickedButtonE)
	ON_BN_CLICKED(IDC_BUTTON_F, &CFifteenGameDlg::OnBnClickedButtonF)
	ON_BN_CLICKED(IDC_BUTTON_G, &CFifteenGameDlg::OnBnClickedButtonG)
	ON_BN_CLICKED(IDC_BUTTON_H, &CFifteenGameDlg::OnBnClickedButtonH)
	ON_BN_CLICKED(IDC_BUTTON_I, &CFifteenGameDlg::OnBnClickedButtonI)
	ON_BN_CLICKED(IDC_BUTTON_J, &CFifteenGameDlg::OnBnClickedButtonJ)
	ON_BN_CLICKED(IDC_BUTTON_K, &CFifteenGameDlg::OnBnClickedButtonK)
	ON_BN_CLICKED(IDC_BUTTON_L, &CFifteenGameDlg::OnBnClickedButtonL)
	ON_BN_CLICKED(IDC_BUTTON_M, &CFifteenGameDlg::OnBnClickedButtonM)
	ON_BN_CLICKED(IDC_BUTTON_N, &CFifteenGameDlg::OnBnClickedButtonN)
	ON_BN_CLICKED(IDC_BUTTON_O, &CFifteenGameDlg::OnBnClickedButtonO)
	ON_BN_CLICKED(IDC_BUTTON_P, &CFifteenGameDlg::OnBnClickedButtonP)
	ON_BN_CLICKED(IDC_NEW_GAME, &CFifteenGameDlg::OnBnClickedNewGame)
	ON_BN_CLICKED(IDC_SHUFFLE, &CFifteenGameDlg::OnBnClickedShuffle)
END_MESSAGE_MAP()


// CFifteenGameDlg message handlers

BOOL CFifteenGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Init game e generate board
	InitGame();

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CFifteenGameDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFifteenGameDlg::OnPaint()
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
HCURSOR CFifteenGameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CFifteenGameDlg::SetButtonValue(CButton& button, int value)
{
	CString aux;
	button.ShowWindow((value == 0) ? SW_HIDE : SW_SHOW);
	aux.Format(_T("%d"), value);
	button.SetWindowTextW(aux);
}


bool CFifteenGameDlg::CheckOwnButtonIsValid(CButton& button)
{
	CString buttonValue;
	button.GetWindowTextW(buttonValue);
	return (buttonValue != _T("0"));
}


bool CFifteenGameDlg::CheckNeighborButtonIsValid(CButton& principalButton, CButton& neighborButton)
{
	CString neighborButtonValue;
	neighborButton.GetWindowTextW(neighborButtonValue);

	if (neighborButtonValue == _T("0"))
	{
		CString principalButtonValue;
		principalButton.GetWindowTextW(principalButtonValue);
		SetButtonValue(neighborButton, atoi(CT2A(principalButtonValue)));
		SetButtonValue(principalButton, 0);
		return true;
	}

	return false;
}


void CFifteenGameDlg::CheckEndGame()
{
	if (CompareButtonValue(value_button_a, 15) && CompareButtonValue(value_button_b, 14) && CompareButtonValue(value_button_c, 13) &&
		CompareButtonValue(value_button_d, 12) && CompareButtonValue(value_button_e, 11) && CompareButtonValue(value_button_f, 10) &&
		CompareButtonValue(value_button_g, 9) && CompareButtonValue(value_button_h, 8) && CompareButtonValue(value_button_i, 7) &&
		CompareButtonValue(value_button_j, 6) && CompareButtonValue(value_button_k, 5) && CompareButtonValue(value_button_l, 4) &&
		CompareButtonValue(value_button_m, 3) && CompareButtonValue(value_button_n, 2) && CompareButtonValue(value_button_o, 1) &&
		CompareButtonValue(value_button_p, 0))
	{
		CString msg = _T("You win. Do you want to start a new game?");
		NewGameMessageBox(msg);
	}
}


bool CFifteenGameDlg::CompareButtonValue(CButton& button, int value)
{
	CString buttonValue;
	button.GetWindowTextW(buttonValue);
	return (atoi(CT2A(buttonValue)) == value);
}


void CFifteenGameDlg::NewGameMessageBox(CString msg)
{
	if (GenerateMessageBox(msg))
	{
		InitGame();
	}
}


bool CFifteenGameDlg::GenerateMessageBox(CString msg)
{
	int option = AfxMessageBox(msg, MB_YESNO);
	return (option == IDYES);
}


void CFifteenGameDlg::OnBnClickedButtonA()
{
	if (CheckOwnButtonIsValid(value_button_a))
	{
		CheckNeighborButtonIsValid(value_button_a, value_button_b);
		CheckNeighborButtonIsValid(value_button_a, value_button_e);
		CheckEndGame();
	}
}


void CFifteenGameDlg::OnBnClickedButtonB()
{
	if (CheckOwnButtonIsValid(value_button_b))
	{
		CheckNeighborButtonIsValid(value_button_b, value_button_c);
		CheckNeighborButtonIsValid(value_button_b, value_button_a);
		CheckNeighborButtonIsValid(value_button_b, value_button_f);
		CheckEndGame();
	}
}


void CFifteenGameDlg::OnBnClickedButtonC()
{
	if (CheckOwnButtonIsValid(value_button_c))
	{
		CheckNeighborButtonIsValid(value_button_c, value_button_b);
		CheckNeighborButtonIsValid(value_button_c, value_button_g);
		CheckNeighborButtonIsValid(value_button_c, value_button_d);
		CheckEndGame();
	}
}


void CFifteenGameDlg::OnBnClickedButtonD()
{
	if (CheckOwnButtonIsValid(value_button_d))
	{
		CheckNeighborButtonIsValid(value_button_d, value_button_c);
		CheckNeighborButtonIsValid(value_button_d, value_button_h);
		CheckEndGame();
	}
}


void CFifteenGameDlg::OnBnClickedButtonE()
{
	if (CheckOwnButtonIsValid(value_button_e))
	{
		CheckNeighborButtonIsValid(value_button_e, value_button_a);
		CheckNeighborButtonIsValid(value_button_e, value_button_f);
		CheckNeighborButtonIsValid(value_button_e, value_button_i);
		CheckEndGame();
	}
}


void CFifteenGameDlg::OnBnClickedButtonF()
{
	if (CheckOwnButtonIsValid(value_button_f))
	{
		CheckNeighborButtonIsValid(value_button_f, value_button_b);
		CheckNeighborButtonIsValid(value_button_f, value_button_e);
		CheckNeighborButtonIsValid(value_button_f, value_button_g);
		CheckNeighborButtonIsValid(value_button_f, value_button_j);
		CheckEndGame();
	}
}


void CFifteenGameDlg::OnBnClickedButtonG()
{
	if (CheckOwnButtonIsValid(value_button_g))
	{
		CheckNeighborButtonIsValid(value_button_g, value_button_c);
		CheckNeighborButtonIsValid(value_button_g, value_button_f);
		CheckNeighborButtonIsValid(value_button_g, value_button_k);
		CheckNeighborButtonIsValid(value_button_g, value_button_h);
		CheckEndGame();
	}
}


void CFifteenGameDlg::OnBnClickedButtonH()
{
	if (CheckOwnButtonIsValid(value_button_h))
	{
		CheckNeighborButtonIsValid(value_button_h, value_button_d);
		CheckNeighborButtonIsValid(value_button_h, value_button_g);
		CheckNeighborButtonIsValid(value_button_h, value_button_l);
		CheckEndGame();
	}
}


void CFifteenGameDlg::OnBnClickedButtonI()
{
	if (CheckOwnButtonIsValid(value_button_i))
	{
		CheckNeighborButtonIsValid(value_button_i, value_button_e);
		CheckNeighborButtonIsValid(value_button_i, value_button_j);
		CheckNeighborButtonIsValid(value_button_i, value_button_m);
		CheckEndGame();
	}
}


void CFifteenGameDlg::OnBnClickedButtonJ()
{
	if (CheckOwnButtonIsValid(value_button_j))
	{
		CheckNeighborButtonIsValid(value_button_j, value_button_i);
		CheckNeighborButtonIsValid(value_button_j, value_button_f);
		CheckNeighborButtonIsValid(value_button_j, value_button_k);
		CheckNeighborButtonIsValid(value_button_j, value_button_n);
		CheckEndGame();
	}
}


void CFifteenGameDlg::OnBnClickedButtonK()
{
	if (CheckOwnButtonIsValid(value_button_k))
	{
		CheckNeighborButtonIsValid(value_button_k, value_button_g);
		CheckNeighborButtonIsValid(value_button_k, value_button_j);
		CheckNeighborButtonIsValid(value_button_k, value_button_l);
		CheckNeighborButtonIsValid(value_button_k, value_button_o);
		CheckEndGame();
	}
}


void CFifteenGameDlg::OnBnClickedButtonL()
{
	if (CheckOwnButtonIsValid(value_button_l))
	{
		CheckNeighborButtonIsValid(value_button_l, value_button_h);
		CheckNeighborButtonIsValid(value_button_l, value_button_k);
		CheckNeighborButtonIsValid(value_button_l, value_button_p);
		CheckEndGame();
	}
}


void CFifteenGameDlg::OnBnClickedButtonM()
{
	if (CheckOwnButtonIsValid(value_button_m))
	{
		CheckNeighborButtonIsValid(value_button_m, value_button_i);
		CheckNeighborButtonIsValid(value_button_m, value_button_n);
		CheckEndGame();
	}
}


void CFifteenGameDlg::OnBnClickedButtonN()
{
	if (CheckOwnButtonIsValid(value_button_n))
	{
		CheckNeighborButtonIsValid(value_button_n, value_button_m);
		CheckNeighborButtonIsValid(value_button_n, value_button_j);
		CheckNeighborButtonIsValid(value_button_n, value_button_o);
		CheckEndGame();
	}
}


void CFifteenGameDlg::OnBnClickedButtonO()
{
	if (CheckOwnButtonIsValid(value_button_o))
	{
		CheckNeighborButtonIsValid(value_button_o, value_button_p);
		CheckNeighborButtonIsValid(value_button_o, value_button_k);
		CheckNeighborButtonIsValid(value_button_o, value_button_n);
		CheckEndGame();
	}
}


void CFifteenGameDlg::OnBnClickedButtonP()
{
	if (CheckOwnButtonIsValid(value_button_p))
	{
		CheckNeighborButtonIsValid(value_button_p, value_button_l);
		CheckNeighborButtonIsValid(value_button_p, value_button_o);
		CheckEndGame();
	}
}


void CFifteenGameDlg::OnBnClickedNewGame()
{
	// Show new game message
	CString msg = _T("Do you want to start a new game?");
	NewGameMessageBox(msg);
}


void CFifteenGameDlg::InitGame()
{
	// Init board array
	for (int i = 0; i < 16; i++)
	{
		board[i] = i + 1;

		if (i == 15)
		{
			board[15] = 0;
		}
	}

	// Init buttons values
	DrawBoard(board);
}


void CFifteenGameDlg::DrawBoard(int values[16])
{
	SetButtonValue(value_button_a, values[0]);
	SetButtonValue(value_button_b, values[1]);
	SetButtonValue(value_button_c, values[2]);
	SetButtonValue(value_button_d, values[3]);
	SetButtonValue(value_button_e, values[4]);
	SetButtonValue(value_button_f, values[5]);
	SetButtonValue(value_button_g, values[6]);
	SetButtonValue(value_button_h, values[7]);
	SetButtonValue(value_button_i, values[8]);
	SetButtonValue(value_button_j, values[9]);
	SetButtonValue(value_button_k, values[10]);
	SetButtonValue(value_button_l, values[11]);
	SetButtonValue(value_button_m, values[12]);
	SetButtonValue(value_button_n, values[13]);
	SetButtonValue(value_button_o, values[14]);
	SetButtonValue(value_button_p, values[15]);
}


void CFifteenGameDlg::OnBnClickedShuffle()
{
	// Shuffle board
	ShuffleBoard();

	// Init buttons values
	DrawBoard(board);
}


void CFifteenGameDlg::ShuffleBoard()
{
	random_device rd;
	mt19937 g(rd());

	std::shuffle(&board[0], &board[16], g);
}