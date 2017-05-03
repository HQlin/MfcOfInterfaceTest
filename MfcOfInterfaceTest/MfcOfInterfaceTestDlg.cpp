
// MfcOfInterfaceTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MfcOfInterfaceTest.h"
#include "MfcOfInterfaceTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMfcOfInterfaceTestDlg 对话框

CMfcOfInterfaceTestDlg::CMfcOfInterfaceTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMfcOfInterfaceTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m = n = 32;
}

void CMfcOfInterfaceTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMfcOfInterfaceTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CMfcOfInterfaceTestDlg 消息处理程序

BOOL CMfcOfInterfaceTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//全屏
	this->ShowWindow(SW_MAXIMIZE);
	//显示出任务栏
	CRect rcWorkArea; 
	SystemParametersInfo(SPI_GETWORKAREA,0,&rcWorkArea,0); 
	MoveWindow(&rcWorkArea); 


	//字体大小
	LOGFONT m_zoomFont;
	m_zoomFont.lfHeight	= rectDlg.Height()/70;
	m_zoomFont.lfWidth	= 0;
	m_zoomFont.lfEscapement	= 0;
	m_zoomFont.lfOrientation	= 0;
	m_zoomFont.lfWeight	= 400;
	m_zoomFont.lfItalic	= FALSE;
	m_zoomFont.lfUnderline	= FALSE;
	m_zoomFont.lfStrikeOut	= FALSE;
	m_zoomFont.lfCharSet	= ANSI_CHARSET;
	m_zoomFont.lfOutPrecision	= OUT_DEFAULT_PRECIS;
	m_zoomFont.lfClipPrecision	= CLIP_DEFAULT_PRECIS;
	m_zoomFont.lfQuality	= PROOF_QUALITY;
	m_zoomFont.lfPitchAndFamily	= DEFAULT_PITCH;
	wcscpy_s(m_zoomFont.lfFaceName, L"宋体");
	m_font.CreateFontIndirectW(&m_zoomFont);

	//小矩形
	btn = new CButton[m*n];  
	DWORD dwStyle = WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON;  
	int a = 0;
	for(int i = 0; i < m; i++){  
		for(int j=0; j<n; j++){
			CString str;
			str.Format(L"%d , %d", i, j);
			CRect r = myRect.GetCRect(i, j);
			btn[a].Create(str, dwStyle, r, this, 10000+a); 
			itemResize.AddItemRect(10000+a, this);
			btn[a].SetFont(&m_font);
			a++;
		} 
	}
	//释放控件数组内存
	//delete [] btn;

	//试用控件
	//GetDlgItem(IDC_BUTTON1)->MoveWindow(myRect.GetCRect(19, 0, 19, 3),TRUE);
	//itemResize.AddItemRect(IDC_BUTTON1, this);
	//GetDlgItem(IDC_BUTTON2)->MoveWindow(myRect.GetCRect(4, 4, 9, 9),TRUE);
	//itemResize.AddItemRect(IDC_BUTTON2, this);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMfcOfInterfaceTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialogEx::OnSysCommand(nID, lParam);
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMfcOfInterfaceTestDlg::OnPaint()
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
HCURSOR CMfcOfInterfaceTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMfcOfInterfaceTestDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	//控件大小适应窗口大小
	itemResize.ResizeItem();
	//获得窗体的大小
	GetClientRect(&rectDlg);
	//控件布局数据更新
	myRect.ScreenInit(m, n, rectDlg, 2, 1);
}
