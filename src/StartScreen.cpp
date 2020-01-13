// StartScreen.cpp : implementation file
//

#include "pch.h"
#include "PicFiller.h"
#include "StartScreen.h"
#include "afxdialogex.h"
#include "PicFillerDlg.h"


// StartScreen dialog

IMPLEMENT_DYNAMIC(StartScreen, CDialogEx)

StartScreen::StartScreen(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

StartScreen::~StartScreen()
{
}

void StartScreen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(StartScreen, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &StartScreen::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &StartScreen::OnBnClickedButton2)
END_MESSAGE_MAP()


// StartScreen message handlers


void StartScreen::OnBnClickedButton1()
{
	CPicFillerDlg dlg;
	this->OnOK();
	dlg.DoModal();
}


void StartScreen::OnBnClickedButton2()
{
	AfxMessageBox(_T("Closing now.."));
	this->OnCancel();
}
