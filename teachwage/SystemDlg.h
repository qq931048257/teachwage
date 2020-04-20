#pragma once
#include "afxcmn.h"

// SystemDlg 对话框

class SystemDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SystemDlg)

public:
	SystemDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SystemDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	// 显示数据列表
	CListCtrl m_list;
	CString name, haoma, xb, nl, tel, wage;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
};
