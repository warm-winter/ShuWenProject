
// MFCApplication2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <cstring>
#include <string>

#include <highgui.hpp>
#include "CreateNoise.h"

#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
public:
	afx_msg void OnBnClickedOk();
	CButton a;
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, a);
}







CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_JIZHUOMI_STATIC, m_jzmPicture);
	DDX_Control(pDX, IDC_JIZHUOMI_STATIC2, m_jzmPicture2);
	DDX_Control(pDX, IDC_JIZHUOMI_STATIC3, m_jzmPicture3);
	DDX_Control(pDX, IDC_JIZHUOMI_STATIC4, m_jzmPicture4);
	DDX_Control(pDX, IDC_WEB_COMBO, m_comboWeb);
	DDX_Control(pDX, IDC_WEB_COMBO7, m_comboWeb7);
	DDX_Control(pDX, IDC_WEB_COMBO9, m_comboWeb9);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_horiScrollbar);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_horiScrollbar2);
	DDX_Control(pDX, IDC_SCROLLBAR3, m_horiScrollbar3);
	DDX_Control(pDX, IDC_JIZHUOMI_STATIC5, m_jzmPicture5);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication2Dlg::OnBnClickedButton4)
	ON_STN_CLICKED(IDC_JIZHUOMI_STATIC3, &CMFCApplication2Dlg::OnStnClickedJizhuomiStatic3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication2Dlg::OnBnClickedButton5)
	ON_CBN_SELCHANGE(IDC_WEB_COMBO, &CMFCApplication2Dlg::OnCbnSelchangeWebCombo)
	ON_CBN_SELCHANGE(IDC_WEB_COMBO7, &CMFCApplication2Dlg::OnCbnSelchangeWebCombo7)
	ON_CBN_SELCHANGE(IDC_WEB_COMBO9, &CMFCApplication2Dlg::OnCbnSelchangeWebCombo9)
	//ON_EN_CHANGE(IDC_HSCROLL_EDIT, &CMFCApplication2Dlg::OnEnChangeHscrollEdit)
	//ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR1, &CMFCApplication2Dlg::OnNMThemeChangedScrollbar1)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_HSCROLL_EDIT1, &CMFCApplication2Dlg::OnEnChangeHscrollEdit1)
	ON_STN_CLICKED(IDC_JIZHUOMI_STATIC4, &CMFCApplication2Dlg::OnStnClickedJizhuomiStatic4)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR3, &CMFCApplication2Dlg::OnNMThemeChangedScrollbar3)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 消息处理程序

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	m_comboWeb.AddString(_T("--未选择--")); 
	m_comboWeb.AddString(_T("高斯噪声"));
	m_comboWeb.AddString(_T("椒噪声"));
	m_comboWeb.AddString(_T("盐噪声"));

	// 默认选择第一项   
	m_comboWeb.SetCurSel(0);


	m_comboWeb7.AddString(_T("--未选择--"));
	m_comboWeb7.AddString(_T("高斯滤波"));
	m_comboWeb7.AddString(_T("方框滤波"));
	m_comboWeb7.AddString(_T("均值滤波"));
	m_comboWeb7.AddString(_T("中值滤波"));
	m_comboWeb7.AddString(_T("双边滤波"));

	// 默认选择第一项   
	m_comboWeb7.SetCurSel(0);


	m_comboWeb9.AddString(_T("--未选择--"));
	m_comboWeb9.AddString(_T("Sobel算子"));
	m_comboWeb9.AddString(_T("Canny算子"));
	m_comboWeb9.AddString(_T("Laplace算子"));
	m_comboWeb9.AddString(_T("roberts算子"));
	// 默认选择第一项   
	m_comboWeb9.SetCurSel(0);


	// TODO: Add extra initialization here   
   // 设置水平滚动条的滚动范围为1到100   
	m_horiScrollbar.SetScrollRange(1, 50);
	// 设置水平滚动条的初始位置为20   
	m_horiScrollbar.SetScrollPos(3);
	// 在编辑框中显示20   
	SetDlgItemInt(IDC_HSCROLL_EDIT, 3);


	// TODO: Add extra initialization here   
// 设置水平滚动条的滚动范围为1到100   
	m_horiScrollbar2.SetScrollRange(1, 200);
	// 设置水平滚动条的初始位置为20   
	m_horiScrollbar2.SetScrollPos(40);
	// 在编辑框中显示20   
	SetDlgItemInt(IDC_HSCROLL_EDIT1, 40);


	// TODO: Add extra initialization here   
// 设置水平滚动条的滚动范围为1到100   
	m_horiScrollbar3.SetScrollRange(1, 500);
	// 设置水平滚动条的初始位置为20   
	m_horiScrollbar3.SetScrollPos(228);
	// 在编辑框中显示20   
	SetDlgItemInt(IDC_HSCROLL_EDIT2, 228);



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication2Dlg::OnBnClickedButton1()
{
	String path = CStringA(gReadFilePathName);

	// TODO: 在此添加控件通知处理程序代码
	Mat origin = imread(path);

	cvtColor(origin, origin, COLOR_BGR2GRAY);

	GaussianBlur(origin, origin,Size(3, 3), 0, 0);

	Canny(origin, origin, 40, 170);

	gReadFilePathName_CANNY = gReadFilePathName_PART + CString("_canny.bmp");
	path = CStringA(gReadFilePathName_CANNY);

	imwrite(path, origin);


	HBITMAP hBitmap = (HBITMAP)::LoadImage(
		NULL,
		gReadFilePathName_CANNY,
		IMAGE_BITMAP,
		400, 400,
		LR_DEFAULTCOLOR | LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	m_jzmPicture5.SetBitmap(hBitmap);
}


void CMFCApplication2Dlg::OnBnClickedButton2()
{
	String path = CStringA(gReadFilePathName);
	Mat origin = imread(path);

	CreateNoise cn;
	cn.AddGaussianNoise(origin);
	
	gReadFilePathName_NOICE = gReadFilePathName_PART + CString("_noice.bmp");
	path = CStringA(gReadFilePathName_NOICE);

	imwrite(path, origin);


	HBITMAP hBitmap = (HBITMAP)::LoadImage(
		NULL,
		gReadFilePathName_NOICE,
		IMAGE_BITMAP,
		400, 400,
		LR_DEFAULTCOLOR | LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	m_jzmPicture2.SetBitmap(hBitmap);

}


void CMFCApplication2Dlg::OnBnClickedButton3()
{
	String path = CStringA(gReadFilePathName_NOICE);
	Mat origin = imread(path);
	GaussianBlur(origin, origin, Size(3, 3), 0, 0);

	gReadFilePathName_BLUR = gReadFilePathName_PART + CString("_blur.bmp");
	path = CStringA(gReadFilePathName_BLUR);
	imwrite(path, origin);


	HBITMAP hBitmap = (HBITMAP)::LoadImage(
		NULL,
		gReadFilePathName_BLUR,
		IMAGE_BITMAP,
		400, 400,
		LR_DEFAULTCOLOR | LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	m_jzmPicture3.SetBitmap(hBitmap);
}


void CMFCApplication2Dlg::OnBnClickedButton4()
{
	String path = CStringA(gReadFilePathName_BLUR);

	// TODO: 在此添加控件通知处理程序代码
	Mat origin = imread(path);

	cvtColor(origin, origin, COLOR_BGR2GRAY);
	Canny(origin, origin, 40, 228);

	gReadFilePathName_EDGE = gReadFilePathName_PART + CString("_edge.bmp");
	path = CStringA(gReadFilePathName_EDGE);

	imwrite(path, origin);


	HBITMAP hBitmap = (HBITMAP)::LoadImage(
		NULL,
		gReadFilePathName_EDGE,
		IMAGE_BITMAP,
		400, 400,
		LR_DEFAULTCOLOR | LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	m_jzmPicture4.SetBitmap(hBitmap);

}


void CMFCApplication2Dlg::OnStnClickedJizhuomiStatic3()
{
	// TODO: 在此添加控件通知处理程序代码



}


void CMFCApplication2Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString gReadFilePathName;
	CFileDialog fileDlg(true, _T("bmp"), _T("*.bmp"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("bmp Files (*.bmp)|*.bmp|All File (*.*)|*.*||"), NULL);
	if (fileDlg.DoModal() == IDOK)    //弹出对话框  
	{
		gReadFilePathName = fileDlg.GetPathName();//得到完整的文件名和目录名拓展名  
		gReadFilePathName_PART = gReadFilePathName.Left(gReadFilePathName.ReverseFind('.'));

		GetDlgItem(IDC_EDIT1)->SetWindowText(gReadFilePathName_PART);//将路径显示  
		CString filename = fileDlg.GetFileName();
	}

	// TODO: 在此添加控件通知处理程序代码
	HBITMAP hBitmap = (HBITMAP)::LoadImage(
		NULL,
		gReadFilePathName,
		IMAGE_BITMAP,
		400, 400,
		LR_DEFAULTCOLOR | LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	m_jzmPicture.SetBitmap(hBitmap);
}

void CMFCApplication2Dlg::OnCbnSelchangeWebCombo()
{

	// TODO: 在此添加控件通知处理程序代码
	String path = CStringA(gReadFilePathName);
	Mat origin = imread(path);

	int nSel = m_comboWeb.GetCurSel();

	int thresholdValue1 = 270;//滞后性阈值1
	int MaxThresholdValue1 = 300;
	CreateNoise cn;
	if (nSel == 2) {
		//createTrackbar("阈值一：", "Canny算子边缘检测效果预览：", &thresholdValue1, MaxThresholdValue1, );

		cn.AddPepperNoise(origin,100);
	}
	else if (nSel == 3) {
		cn.AddSaltNoise(origin, 100);
	}
	else {
		cn.AddGaussianNoise(origin);
	}

	//cn.AddGaussianNoise(origin);

	gReadFilePathName_NOICE = gReadFilePathName_PART + CString("_noice.bmp");
	path = CStringA(gReadFilePathName_NOICE);

	imwrite(path, origin);


	HBITMAP hBitmap = (HBITMAP)::LoadImage(
		NULL,
		gReadFilePathName_NOICE,
		IMAGE_BITMAP,
		400, 400,
		LR_DEFAULTCOLOR | LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	m_jzmPicture2.SetBitmap(hBitmap);
}


void CMFCApplication2Dlg::OnCbnSelchangeWebCombo7()
{
	// TODO: 在此添加控件通知处理程序代码
	String path = CStringA(gReadFilePathName_NOICE);
	Mat origin = imread(path);
	int nSel = m_comboWeb7.GetCurSel();

	int kenelValue = 10;
	int MaxkenelValue = 100;


	if (nSel == 2) {//方框滤波
		int pos = m_horiScrollbar.GetScrollPos();
		

		boxFilter(origin, origin, -1, Size(pos + 1, pos + 1));
	}
	else if (nSel == 3) {
		blur(origin, origin, Size(7, 7));
	}
	else if (nSel == 4) {
		medianBlur(origin, origin, 7);
	}
	else if (nSel == 5) {
		Mat bilateral;
		bilateralFilter(origin, bilateral, 25 * 2, 25 * 2 * 2, 25 / 2 * 2);
		origin = bilateral;
	}
	else {
		GaussianBlur(origin, origin, Size(3, 3), 0, 0);
	}


	
	gReadFilePathName_BLUR = gReadFilePathName_PART + CString("_blur.bmp");
	path = CStringA(gReadFilePathName_BLUR);
	imwrite(path, origin);


	HBITMAP hBitmap = (HBITMAP)::LoadImage(
		NULL,
		gReadFilePathName_BLUR,
		IMAGE_BITMAP,
		400, 400,
		LR_DEFAULTCOLOR | LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	m_jzmPicture3.SetBitmap(hBitmap);

}

Mat roberts(Mat srcImage)
{
	Mat dstImage = srcImage.clone();
	int nRows = dstImage.rows;
	int nCols = dstImage.cols;
	for (int i = 0; i < nRows - 1; i++) {
		for (int j = 0; j < nCols - 1; j++) {
			int t1 = (srcImage.at<uchar>(i, j) - srcImage.at<uchar>(i + 1, j + 1)) * (srcImage.at<uchar>(i, j) - srcImage.at<uchar>(i + 1, j + 1));
			int t2 = (srcImage.at<uchar>(i + 1, j) - srcImage.at<uchar>(i, j + 1)) * (srcImage.at<uchar>(i + 1, j) - srcImage.at<uchar>(i, j + 1));
			dstImage.at<uchar>(i, j) = (uchar)sqrt(t1 + t2);
		}
	}
	return dstImage;
}


void CMFCApplication2Dlg::OnCbnSelchangeWebCombo9()
{
	String path = CStringA(gReadFilePathName_BLUR);

	// TODO: 在此添加控件通知处理程序代码
	Mat origin = imread(path);

	int nSel = m_comboWeb9.GetCurSel();
	cvtColor(origin, origin, COLOR_BGR2GRAY);

	int kenelValue = 10;
	Mat grad_x, grad_y, abs_grad_x, abs_grad_y;

	if (nSel == 2) {//canny
		//int canny = m_horiScrollbar2.GetScrollPos();
		/*int value = m_horiScrollbar3.GetScrollPos();
		Canny(origin, origin, value, value * 2 / 3, 3);*/

		int canny = m_horiScrollbar2.GetScrollPos();
		int value = m_horiScrollbar3.GetScrollPos();
		Canny(origin, origin, canny, value, 3);

	}
	else if (nSel == 3) {//laplace
		Laplacian(origin, origin, -1, 3);
	}
	else if (nSel == 4) {
		origin = roberts(origin);
	}
	else {//默认做1
		Sobel(origin, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
		convertScaleAbs(grad_x, abs_grad_x);
		Sobel(origin, grad_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
		convertScaleAbs(grad_y, abs_grad_y);
		addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, origin);
	}

	gReadFilePathName_EDGE = gReadFilePathName_PART + CString("_edge.bmp");
	path = CStringA(gReadFilePathName_EDGE);

	imwrite(path, origin);


	HBITMAP hBitmap = (HBITMAP)::LoadImage(
		NULL,
		gReadFilePathName_EDGE,
		IMAGE_BITMAP,
		400, 400,
		LR_DEFAULTCOLOR | LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	m_jzmPicture4.SetBitmap(hBitmap);
}



void CMFCApplication2Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	int nID = pScrollBar->GetDlgCtrlID();
	int pos;
	if (nID == IDC_SCROLLBAR1) {
		pos = m_horiScrollbar.GetScrollPos();    // 获取水平滚动条当前位置 
	}
	else if (nID == IDC_SCROLLBAR2) {
		pos = m_horiScrollbar2.GetScrollPos();
	}
	else if (nID == IDC_SCROLLBAR3) {
		pos = m_horiScrollbar3.GetScrollPos();
	}


	switch (nSBCode)
	{
		// 如果向左滚动一列，则pos减1  
	case SB_LINELEFT:
		pos -= 1;
		break;
		// 如果向右滚动一列，则pos加1  
	case SB_LINERIGHT:
		pos += 1;
		break;
		// 如果向左滚动一页，则pos减10  
	case SB_PAGELEFT:
		pos -= 10;
		break;
		// 如果向右滚动一页，则pos加10  
	case SB_PAGERIGHT:
		pos += 10;
		break;
		// 如果滚动到最左端，则pos为1  
	case SB_LEFT:
		pos = 1;
		break;
		// 如果滚动到最右端，则pos为100  
	case SB_RIGHT:
		if (nID == IDC_SCROLLBAR1) {
			pos = 20;
		}
		else if (nID == IDC_SCROLLBAR2) {
			pos = 200;
		}
		else if (nID == IDC_SCROLLBAR3) {
			pos = 500;
		}
		break;
		// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值  
	case SB_THUMBPOSITION:
		pos = nPos;
		break;
		// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值  
	default:
		if (nID == IDC_SCROLLBAR1) {
			SetDlgItemInt(IDC_HSCROLL_EDIT, pos);
		}
		else if (nID == IDC_SCROLLBAR2) {
			SetDlgItemInt(IDC_HSCROLL_EDIT1, pos);
		}
		else if (nID == IDC_SCROLLBAR3) {
			SetDlgItemInt(IDC_HSCROLL_EDIT2, pos);
		}
		return;
	}

	if (nID == IDC_SCROLLBAR1) {
		m_horiScrollbar.SetScrollPos(pos);
		OnCbnSelchangeWebCombo7();
	}
	else if (nID == IDC_SCROLLBAR2) {
		m_horiScrollbar2.SetScrollPos(pos);
		OnCbnSelchangeWebCombo9();
	}
	else if (nID == IDC_SCROLLBAR3) {
		m_horiScrollbar3.SetScrollPos(pos);
		OnCbnSelchangeWebCombo9();
	}

	// 设置滚动块位置  
	//m_horiScrollbar.SetScrollPos(pos);


	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	
}


void CMFCApplication2Dlg::OnEnChangeHscrollEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication2Dlg::OnStnClickedJizhuomiStatic4()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication2Dlg::OnNMThemeChangedScrollbar3(NMHDR* pNMHDR, LRESULT* pResult)
{
	// 该功能要求使用 Windows XP 或更高版本。
	// 符号 _WIN32_WINNT 必须 >= 0x0501。
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
