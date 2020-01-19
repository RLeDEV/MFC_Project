
// PicFillerDlg.h : header file
//

#pragma once

#include <vector>
#include <stack>
#include "afxwin.h"
#include "afxbutton.h"
#include "resource.h"
#include "Shape.h"
#include "command.h"
#include "Line.h"
#include "iRectangle.h"
#include "iEllipse.h"
#include "iTriangle.h"
#include "iTrapez.h"
#include "addColor.h"
#include "addShape.h"
#include "deleteShape.h"
#include "StartScreen.h"

using namespace std;

// CPicFillerDlg dialog
class CPicFillerDlg : public CDialogEx
{
// Construction
public:
	CPicFillerDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PICFILLER_DIALOG };
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
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CMFCButton button_red;
	CMFCButton button_blue;
	CMFCButton button_green;
	CMFCButton button_yellow;
	CMFCButton button_pink;
	CMFCButton button_purple;
	CMFCButton button_orange;
	CMFCButton button_brown;
	CMFCButton button_white;
	CMFCButton button_gray;
	CMFCButton button_black;
	CMFCButton button_turkiz;
	CSliderCtrl m_red;
	CSliderCtrl m_green;
	CSliderCtrl m_blue;
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	int penType;
	bool FillClrPressed;
	bool MoveShapePressed;
	RECT r;
private:
	int currentShape;
	int shapeType;
	bool isPressed;
	CPoint startP;
	CPoint endP;
	CTypedPtrArray<CObArray, Shape*> Shapes;
	stack<command*> commands, undoes;
public:
	int penSize;
	int moveIndex;
	bool FillPressed;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	CString color_name;
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox penTypeBtn;
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
	CButton load;
	CButton save;
	CButton redo;
	CButton undo;
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton13();
};
