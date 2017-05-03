
// MfcOfInterfaceTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MfcOfInterfaceTest.h"
#include "MfcOfInterfaceTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMfcOfInterfaceTestDlg �Ի���

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


// CMfcOfInterfaceTestDlg ��Ϣ�������

BOOL CMfcOfInterfaceTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//ȫ��
	this->ShowWindow(SW_MAXIMIZE);
	//��ʾ��������
	CRect rcWorkArea; 
	SystemParametersInfo(SPI_GETWORKAREA,0,&rcWorkArea,0); 
	MoveWindow(&rcWorkArea); 


	//�����С
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
	wcscpy_s(m_zoomFont.lfFaceName, L"����");
	m_font.CreateFontIndirectW(&m_zoomFont);

	//С����
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
	//�ͷſؼ������ڴ�
	//delete [] btn;

	//���ÿؼ�
	//GetDlgItem(IDC_BUTTON1)->MoveWindow(myRect.GetCRect(19, 0, 19, 3),TRUE);
	//itemResize.AddItemRect(IDC_BUTTON1, this);
	//GetDlgItem(IDC_BUTTON2)->MoveWindow(myRect.GetCRect(4, 4, 9, 9),TRUE);
	//itemResize.AddItemRect(IDC_BUTTON2, this);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMfcOfInterfaceTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialogEx::OnSysCommand(nID, lParam);
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMfcOfInterfaceTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMfcOfInterfaceTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMfcOfInterfaceTestDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	//�ؼ���С��Ӧ���ڴ�С
	itemResize.ResizeItem();
	//��ô���Ĵ�С
	GetClientRect(&rectDlg);
	//�ؼ��������ݸ���
	myRect.ScreenInit(m, n, rectDlg, 2, 1);
}
