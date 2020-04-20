// PropertyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "teachwage.h"
#include "PropertyDlg.h"
#include "afxdialogex.h"


// PropertyDlg 对话框

IMPLEMENT_DYNAMIC(PropertyDlg, CDialogEx)

PropertyDlg::PropertyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(PropertyDlg::IDD, pParent)
{

}

PropertyDlg::~PropertyDlg()
{
}

void PropertyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PropertyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &PropertyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// PropertyDlg 消息处理程序


void PropertyDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT1, name);
	GetDlgItemText(IDC_EDIT2, num);
	GetDlgItemText(IDC_EDIT3, sex);
	GetDlgItemText(IDC_EDIT4, age);
	GetDlgItemText(IDC_EDIT5, tel);
	GetDlgItemText(IDC_EDIT6, wage);
	EndDialog(0);
}
