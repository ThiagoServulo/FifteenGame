
// FifteenGameDlg.h : header file
//

#pragma once


// CFifteenGameDlg dialog
class CFifteenGameDlg : public CDialogEx
{
// Construction
public:
	CFifteenGameDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIFTEENGAME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	int board[16];
	void SetButtonValue(CButton& button, int value);
	bool CheckOwnButtonIsValid(CButton& button);
	bool CheckNeighborButtonIsValid(CButton& principalButton, CButton& neighborButton);
	void CheckEndGame();
	bool CompareButtonValue(CButton& button, int value);
	void NewGameMessageBox(CString msg);
	bool GenerateMessageBox(CString msg);
	void InitGame();
	void DrawBoard(int values[16]);
	void ShuffleBoard();
	
public:
	CButton value_button_a;
	CButton value_button_b;
	CButton value_button_c;
	CButton value_button_d;
	CButton value_button_e;
	CButton value_button_f;
	CButton value_button_g;
	CButton value_button_h;
	CButton value_button_i;
	CButton value_button_j;
	CButton value_button_k;
	CButton value_button_l;
	CButton value_button_m;
	CButton value_button_n;
	CButton value_button_o;
	CButton value_button_p;
	afx_msg void OnBnClickedButtonA();
	afx_msg void OnBnClickedButtonB();
	afx_msg void OnBnClickedButtonC();
	afx_msg void OnBnClickedButtonD();
	afx_msg void OnBnClickedButtonE();
	afx_msg void OnBnClickedButtonF();
	afx_msg void OnBnClickedButtonG();
	afx_msg void OnBnClickedButtonH();
	afx_msg void OnBnClickedButtonI();
	afx_msg void OnBnClickedButtonJ();
	afx_msg void OnBnClickedButtonK();
	afx_msg void OnBnClickedButtonL();
	afx_msg void OnBnClickedButtonM();
	afx_msg void OnBnClickedButtonN();
	afx_msg void OnBnClickedButtonO();
	afx_msg void OnBnClickedButtonP();
	afx_msg void OnBnClickedNewGame();
	afx_msg void OnBnClickedShuffle();
};
