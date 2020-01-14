
// PicFillerDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "PicFiller.h"
#include "PicFillerDlg.h"
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


// CPicFillerDlg dialog



CPicFillerDlg::CPicFillerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PICFILLER_DIALOG, pParent)
	, color_name(_T(""))
{
	penType = 0;
	penSize = 1;
	shapeType = 0;
	currentShape = 1;
	ChangeSize = false;
	isPressed = false;
	FillPressed = false;
	MovePressed = false;
	currentShape = 0; // Initialization for currentShape
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPicFillerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, button_red);
	DDX_Control(pDX, IDC_BUTTON2, button_blue);
	DDX_Control(pDX, IDC_BUTTON3, button_green);
	DDX_Control(pDX, IDC_BUTTON4, button_yellow);
	DDX_Control(pDX, IDC_BUTTON5, button_pink);
	DDX_Control(pDX, IDC_BUTTON6, button_purple);
	DDX_Control(pDX, IDC_BUTTON7, button_orange);
	DDX_Control(pDX, IDC_BUTTON8, button_brown);
	DDX_Control(pDX, IDC_BUTTON9, button_white);
	DDX_Control(pDX, IDC_BUTTON10, button_gray);
	DDX_Control(pDX, IDC_BUTTON11, button_black);
	DDX_Control(pDX, IDC_BUTTON12, button_turkiz);
	DDX_Control(pDX, IDC_SLIDER1, m_red);
	DDX_Control(pDX, IDC_SLIDER2, m_green);
	DDX_Control(pDX, IDC_SLIDER3, m_blue);
	DDX_Text(pDX, IDC_EDIT1, color_name);
	DDX_Control(pDX, IDC_COMBO1, penTypeBtn);
	DDX_Control(pDX, IDC_BUTTON19, load);
	DDX_Control(pDX, IDC_BUTTON18, save);
	DDX_Control(pDX, IDC_BUTTON14, redo);
	DDX_Control(pDX, IDC_BUTTON15, undo);
	DDX_Control(pDX, IDC_BUTTON20, Delete);
}

BEGIN_MESSAGE_MAP(CPicFillerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_HSCROLL()
	ON_WM_CTLCOLOR()
	ON_WM_RBUTTONDOWN()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CPicFillerDlg::OnNMCustomdrawSlider1)
	ON_BN_CLICKED(IDC_BUTTON1, &CPicFillerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPicFillerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CPicFillerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CPicFillerDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CPicFillerDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CPicFillerDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CPicFillerDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CPicFillerDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CPicFillerDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CPicFillerDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CPicFillerDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CPicFillerDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_RADIO1, &CPicFillerDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CPicFillerDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CPicFillerDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CPicFillerDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CPicFillerDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CPicFillerDlg::OnBnClickedRadio6)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CPicFillerDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON16, &CPicFillerDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CPicFillerDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CPicFillerDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CPicFillerDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON14, &CPicFillerDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CPicFillerDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON13, &CPicFillerDlg::OnBnClickedButton13)
END_MESSAGE_MAP()


// CPicFillerDlg message handlers

BOOL CPicFillerDlg::OnInitDialog()
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


	r.left = 250;
	r.top = 72;
	r.right = 1350;
	r.bottom = 700;

	// Initialization for default values of sliders
	m_red.SetRangeMax(255);
	m_red.SetRangeMin(0);
	m_green.SetRangeMax(255);
	m_green.SetRangeMin(0);
	m_blue.SetRangeMax(255);
	m_blue.SetRangeMin(0);
	// End of sliders
	CheckRadioButton(IDC_RADIO1, IDC_RADIO6, IDC_RADIO1); // Setting first radio button to default
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPicFillerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPicFillerDlg::OnPaint()
{

	CPaintDC dc(this);
	for (int i = 0; i < Shapes.GetSize(); ++i)
		Shapes[i]->draw(&dc);

	CBrush brush(RGB(m_red.GetPos(), m_green.GetPos(), m_blue.GetPos()));
	CPen pen(PS_SOLID, 1, RGB(m_red.GetPos(), m_green.GetPos(), m_blue.GetPos()));
	CBrush *old = dc.SelectObject(&brush);
	CPen *oldP = dc.SelectObject(&pen);
	dc.Rectangle(200, 400, 32, 300); // Real-time color rectangle
	
	button_red.m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	button_blue.m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	button_green.m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	button_yellow.m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	button_pink.m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	button_purple.m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	button_orange.m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	button_brown.m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	button_white.m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	button_gray.m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	button_black.m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	button_turkiz.m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	button_red.SetFaceColor(RGB(255, 0, 0), true);
	button_blue.SetFaceColor(RGB(0, 128, 255), true);
	button_green.SetFaceColor(RGB(85, 255, 85), true);
	button_yellow.SetFaceColor(RGB(255, 255, 23), true);
	button_pink.SetFaceColor(RGB(255, 104, 180), true);
	button_purple.SetFaceColor(RGB(98, 0, 196), true);
	button_orange.SetFaceColor(RGB(255, 141, 28), true);
	button_brown.SetFaceColor(RGB(89, 0, 0), true);
	button_white.SetFaceColor(RGB(255, 255, 255), true);
	button_gray.SetFaceColor(RGB(89, 89, 89), true);
	button_black.SetFaceColor(RGB(0, 0, 0), true);
	button_turkiz.SetFaceColor(RGB(0, 223, 223), true);

	dc.SelectObject(old);
	dc.SelectObject(oldP);
	
	CDialogEx::OnPaint();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPicFillerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPicFillerDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CPicFillerDlg::OnBnClickedButton1()
{
	// changing color on sliders to red
	m_red.SetPos(255);
	m_green.SetPos(0);
	m_blue.SetPos(0);
	color_name = "Red";
	UpdateData(FALSE);
	Invalidate();
}


void CPicFillerDlg::OnBnClickedButton2()
{
	// changing color on sliders to blue
	m_red.SetPos(0);
	m_green.SetPos(128);
	m_blue.SetPos(255);
	color_name = "Blue";
	UpdateData(FALSE);
	Invalidate();
}



void CPicFillerDlg::OnBnClickedButton3()
{
	// changing color on sliders to green
	m_red.SetPos(85);
	m_green.SetPos(255);
	m_blue.SetPos(85);
	color_name = "Green";
	UpdateData(FALSE);
	Invalidate();
}



void CPicFillerDlg::OnBnClickedButton4()
{
	// changing color on sliders to yellow
	m_red.SetPos(255);
	m_green.SetPos(255);
	m_blue.SetPos(23);
	color_name = "Yellow";
	UpdateData(FALSE);
	Invalidate();
}


void CPicFillerDlg::OnBnClickedButton5()
{
	// changing color on sliders to pink
	m_red.SetPos(255);
	m_green.SetPos(104);
	m_blue.SetPos(180);
	color_name = "Pink";
	UpdateData(FALSE);
	Invalidate();
}


void CPicFillerDlg::OnBnClickedButton6()
{
	// changing color on sliders to purple
	m_red.SetPos(98);
	m_green.SetPos(0);
	m_blue.SetPos(196);
	color_name = "Purple";
	UpdateData(FALSE);
	Invalidate();
}


void CPicFillerDlg::OnBnClickedButton7()
{
	// changing color on sliders to orange
	m_red.SetPos(255);
	m_green.SetPos(141);
	m_blue.SetPos(28);
	color_name = "Orange";
	UpdateData(FALSE);
	Invalidate();
}


void CPicFillerDlg::OnBnClickedButton8()
{
	// changing color on sliders to brown
	m_red.SetPos(89);
	m_green.SetPos(0);
	m_blue.SetPos(0);
	color_name = "Brown";
	UpdateData(FALSE);
	Invalidate();
}



void CPicFillerDlg::OnBnClickedButton9()
{
	// changing color on sliders to white
	m_red.SetPos(255);
	m_green.SetPos(255);
	m_blue.SetPos(255);
	color_name = "White";
	UpdateData(FALSE);
	Invalidate();
}


void CPicFillerDlg::OnBnClickedButton10()
{
	// changing color on sliders to gray
	m_red.SetPos(89);
	m_green.SetPos(89);
	m_blue.SetPos(89);
	color_name = "Gray";
	UpdateData(FALSE);
	Invalidate();
}




void CPicFillerDlg::OnBnClickedButton11()
{
	// changing color on sliders to black
	m_red.SetPos(0);
	m_green.SetPos(0);
	m_blue.SetPos(0);
	color_name = "Black";
	UpdateData(FALSE);
	Invalidate();
}




void CPicFillerDlg::OnBnClickedButton12()
{
	// changing color on sliders to turkiz
	m_red.SetPos(0);
	m_green.SetPos(223);
	m_blue.SetPos(223);
	color_name = "Turkiz";
	UpdateData(FALSE);
	Invalidate();
}


void CPicFillerDlg::OnBnClickedRadio1() // Line
{
		currentShape = 0;
}


void CPicFillerDlg::OnBnClickedRadio2() // Rectangle
{
		currentShape = 1;
}


void CPicFillerDlg::OnBnClickedRadio3() // Ellipse
{

		currentShape = 2;
}




void CPicFillerDlg::OnBnClickedRadio4() // Triangle
{
		currentShape = 3;
}





void CPicFillerDlg::OnBnClickedRadio5() // Trapez
{
		currentShape = 4;
}




void CPicFillerDlg::OnBnClickedRadio6() // Pentagon
{
		currentShape = 5;
}


void CPicFillerDlg::OnCbnSelchangeCombo1()
{
	int choose = penTypeBtn.GetCurSel();

	switch (choose) {
	case 0:
		{
			penType = 1;
			break;
		}
	case 1:
		{
			penType = 4;
			break;
		}
	case 2:
		{
			penType = 7;
			break;
		}
	case 3:
		{
			penType = 9;
			break;
		}
	case 4:
		{
			penType = 12;
			break;
		}
	}
}


void CPicFillerDlg::OnBnClickedButton16()
{
	FillClrPressed = true;
}


void CPicFillerDlg::OnBnClickedButton17()
{
	MoveShapePressed = true;
}


void CPicFillerDlg::OnBnClickedButton18() // save btn
{
	CFile file(L"FILE.$$", CFile::modeWrite | CFile::modeCreate); // write to or create a new one
	CArchive archive(&file, CArchive::store);
	Shapes.Serialize(archive);
	InvalidateRect(&r);
	AfxMessageBox(_T("Saved!"));
}


void CPicFillerDlg::OnBnClickedButton19() // load btn
{
	try {
		CFile file(L"FILE.$$", CFile::modeRead); // read a file
		CArchive archive(&file, CArchive::load);
		Shapes.Serialize(archive);
		InvalidateRect(&r);
		AfxMessageBox(_T("Last work loaded!"));
	}
	catch (...) {
		// Error will be here
	}
}

void CPicFillerDlg::OnMouseMove(UINT nFlags, CPoint point) {
	CPaintDC dc(this);

	if (isPressed) {
		if (MovePressed) {
			Shapes[moveIndex]->endP.x += (point.x - Shapes[moveIndex]->startP.x);
			Shapes[moveIndex]->endP.y += (point.y - Shapes[moveIndex]->startP.y);
			Shapes[moveIndex]->startP.x = point.x;
			Shapes[moveIndex]->startP.y = point.y;
			InvalidateRect(&r);
		}
		else {
			if (ChangeSize) {
				Shapes[moveIndex]->startP.x = point.x;
				Shapes[moveIndex]->startP.y = point.y;
				InvalidateRect(&r);
			}
			else {
				Shapes[Shapes.GetSize() - 1]->setEnd(point);
				InvalidateRect(&r);
			}
		}
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

void CPicFillerDlg::OnLButtonDown(UINT nFlags, CPoint point) {
	isPressed = true;
	if (MovePressed || ChangeSize) {
		for (int i = Shapes.GetSize() - 1; i >= 0; i--) {
			if (Shapes[i]->InShape(point)) { // if point is inside the shape
				moveIndex = i;
				break;
			}
		}
	}
	else {
		if (FillPressed)
		{
			for (int i = Shapes.GetSize() - 1; i >= 0; i--) {
				if (Shapes[i]->InShape(point)) {
					command *c = new addColor(Shapes[i], RGB(m_red.GetPos(), m_green.GetPos(), m_blue.GetPos()));
					c->perform(); // changing the color of the shape
					commands.push(c);
					break;
				}
			}
		}
		else {
			if (DeleteButton) {
				for (int i = Shapes.GetSize() - 1; i >= 0; i--)
				{
					if (Shapes[i]->InShape(point))
					{
						command *c = new deleteShape(Shapes, Shapes[i]);
						c->perform();
						commands.push(c);
						InvalidateRect(&r);
						break;
					}
				}
			}
			else // new shape
			{
				Shape *s = 0;
				switch (currentShape) // create the shape the user pressed
				{
				case 0: s = new Line(); break;
				case 1: s = new iRectangle(); break;
				case 2: s = new iEllipse(); break;
				case 3: s = new iTriangle(); break;
				case 4: s = new iPentagon(); break;
				}
				command *c = new addShape(Shapes, s);
				c->perform(); // add shape to the array
				commands.push(c);
				s->setBg(RGB(m_red.GetPos(), m_green.GetPos(), m_blue.GetPos()));
				s->setP(RGB(m_red.GetPos(), m_green.GetPos(), m_blue.GetPos()));
				s->setPenType(penType);
				s->setPenSize(penSize);
				s->setStart(point);
				s->setEnd(point);
			}
		}
	}
	Invalidate();
	CDialogEx::OnLButtonDown(nFlags, point);
}

void CPicFillerDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	InvalidateRect(&r);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CPicFillerDlg::OnLButtonUp(UINT nFlags, CPoint point) {
	if (!MovePressed && !FillPressed && !DeleteButton && !ChangeSize)
		Shapes[Shapes.GetSize() - 1]->setEnd(point);
	isPressed = false;
	MovePressed = false;
	FillPressed = false;
	DeleteButton = false;
	ChangeSize = false;
	Invalidate();
	CDialogEx::OnLButtonUp(nFlags, point);
}

void CPicFillerDlg::OnRButtonDown(UINT nFlags, CPoint point) {
	for (int i = Shapes.GetSize() - 1; i >= 0; i--) {
		if (Shapes[i]->InShape(point)) {
			command *c = new addColor(Shapes[i], (RGB(m_red.GetPos(), m_green.GetPos(), m_blue.GetPos())));
			c->perform();
			commands.push(c);
			break;
		}
	}
	Invalidate();
	CDialogEx::OnRButtonDown(nFlags, point);
}

void CPicFillerDlg::OnBnClickedButton14() // redo btn
{
	if (!undoes.empty()) {
		command *c = undoes.top();
		c->perform();
		commands.push(c);
		undoes.pop();
	}
	InvalidateRect(&r);
}


void CPicFillerDlg::OnBnClickedButton15() // undo btn
{
	if (!(commands.empty())) {
		command *c = commands.top();
		c->rollback();
		undoes.push(c);
		commands.pop();
	}
	InvalidateRect(&r);
}


void CPicFillerDlg::OnBnClickedButton13()
{
	while (!commands.empty())
		commands.pop();
	while (!undoes.empty())
		undoes.pop();
	Shapes.RemoveAll();
	Invalidate();
}
