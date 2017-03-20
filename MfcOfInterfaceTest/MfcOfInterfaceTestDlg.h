
// MfcOfInterfaceTestDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "ItemResize.h"  
#include "ScreenRect.h"

// CMfcOfInterfaceTestDlg �Ի���
class CMfcOfInterfaceTestDlg : public CDialogEx
{
// ����
public:
	CMfcOfInterfaceTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCOFINTERFACETEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	CButton* btn;

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);

	//�ؼ���Ӧ���ڴ�С
	CItemResize itemResize;

	//�ؼ���̬����
	ScreenRect myRect;

	//�Ի������С���䴰�����꣨�������Ͻ�Ϊԭ�㣩
	CRect rectDlg;

	//����С���� x����y�����
	int m;
	int n;
	
	//����
	CFont m_font;	 
};
