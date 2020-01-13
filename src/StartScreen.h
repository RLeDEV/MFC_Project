#pragma once


// StartScreen dialog

class StartScreen : public CDialogEx
{
	DECLARE_DYNAMIC(StartScreen)

public:
	StartScreen(CWnd* pParent = nullptr);   // standard constructor
	virtual ~StartScreen();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
