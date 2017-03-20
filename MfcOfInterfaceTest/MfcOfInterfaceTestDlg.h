
// MfcOfInterfaceTestDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "ItemResize.h"  
#include "ScreenRect.h"

// CMfcOfInterfaceTestDlg 对话框
class CMfcOfInterfaceTestDlg : public CDialogEx
{
// 构造
public:
	CMfcOfInterfaceTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCOFINTERFACETEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	CButton* btn;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);

	//控件适应窗口大小
	CItemResize itemResize;

	//控件动态布局
	ScreenRect myRect;

	//对话框窗体大小及其窗口坐标（窗口左上角为原点）
	CRect rectDlg;

	//布局小矩形 x轴与y轴个数
	int m;
	int n;
	
	//字体
	CFont m_font;	 
};
