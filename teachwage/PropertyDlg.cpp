// PropertyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "teachwage.h"
#include "PropertyDlg.h"
#include "afxdialogex.h"


// PropertyDlg �Ի���

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


// PropertyDlg ��Ϣ�������


void PropertyDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(IDC_EDIT1, name);
	GetDlgItemText(IDC_EDIT2, num);
	GetDlgItemText(IDC_EDIT3, sex);
	GetDlgItemText(IDC_EDIT4, age);
	GetDlgItemText(IDC_EDIT5, tel);
	GetDlgItemText(IDC_EDIT6, wage);
	EndDialog(0);
}
