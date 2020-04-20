// SystemDlg.cpp : ʵ���ļ�
#include<stdlib.h>
#include "stdafx.h"
#include "teachwage.h"
#include "SystemDlg.h"
#include "afxdialogex.h"
#include"PropertyDlg.h"
// SystemDlg �Ի���

IMPLEMENT_DYNAMIC(SystemDlg, CDialogEx)
SystemDlg::SystemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SystemDlg::IDD, pParent)
{

}

SystemDlg::~SystemDlg()
{
}

void SystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(SystemDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &SystemDlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON1, &SystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &SystemDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &SystemDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &SystemDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &SystemDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &SystemDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &SystemDlg::OnBnClickedButton8)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON9, &SystemDlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// SystemDlg ��Ϣ�������

void SystemDlg::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDialog * pdlg = (CDialog*)AfxGetMainWnd();
	pdlg->DestroyWindow();
	CDialogEx::OnClose();
}
void SystemDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}

BOOL SystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_list.InsertColumn(0,_T("�̹�����"),0,100);
	m_list.InsertColumn(1, _T("�̹���"), 0, 100);
	m_list.InsertColumn(2, _T("�Ա�"), 0, 100);
	m_list.InsertColumn(3, _T("����"), 0, 100);
	m_list.InsertColumn(4, _T("�绰"), 0, 100);
	m_list.InsertColumn(5, _T("����"), 0, 100);
	for (int i = 0; i <500; i++)
	{
		name.Format(_T("����%d"), i);
		haoma.Format(_T("1500710%d"), i);
		xb.Format(_T("��%d"), i);
		nl.Format(_T("%d"), (rand() % (60 - 18 + 1)) + 18);
		tel.Format(_T("1330790%d"), (rand() % (10000 - 1000 + 1)) + 1000);
		wage.Format(_T("%d"), (rand() % (10000- 3000 + 1)) + 3000);

		m_list.InsertItem(i, name);
		m_list.SetItemText(i, 1, haoma);
		m_list.SetItemText(i, 2, xb);
		m_list.SetItemText(i, 3, nl);
		m_list.SetItemText(i, 4, tel);
		m_list.SetItemText(i, 5, wage);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void SystemDlg::OnBnClickedButton1()//ȫѡ��ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	for (int i = 0; i < m_list.GetItemCount(); i++)
	{
		m_list.SetCheck(i,TRUE);
	}
}


void SystemDlg::OnBnClickedButton2()//��ѡ��ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	for (int i = 0; i < m_list.GetItemCount(); i++)
	{
		m_list.SetCheck(i, !m_list.GetItemCount());
	}
}

void SystemDlg::OnBnClickedButton3()//���ݰ�ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog fDlg(FALSE,_T(".txt"),_T("save"),OFN_OVERWRITEPROMPT,_T("�ı��ĵ�(*.txt)|*.txt|��������(*.dat)|*.dat|�����ļ�(*.*)|*.*||"),NULL);
	
	if (fDlg.DoModal() == IDOK)
	{
		CStdioFile file(fDlg.GetPathName(), CFile::modeWrite | CFile::modeCreate);
		
		CString cs = _T("name num sex age tel wage\n");
		file.WriteString(cs);
		for (int i = 0; i < m_list.GetItemCount(); i++)
		{
			cs = m_list.GetItemText(i, 0) + _T(" ");
			cs += m_list.GetItemText(i, 1) + _T(" ");
			cs += m_list.GetItemText(i, 2) + _T(" ");
			cs += m_list.GetItemText(i, 3) + _T(" ");
			cs += m_list.GetItemText(i, 4) + _T(" ");
			cs += m_list.GetItemText(i, 5) + _T("\n");
			file.WriteString(cs);
		}
		file.Close();
		MessageBox(_T("д���ļ��ɹ���"), _T("����"));
	}
}


void SystemDlg::OnBnClickedButton4()//�޸İ�ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	for (int i = 0; i < m_list.GetItemCount(); i++)
	{
		BOOL state = m_list.GetCheck(i);
		if (state)
		{
			PropertyDlg dlg;
			dlg.DoModal();

			m_list.SetItemText(i,0,dlg.name);
			m_list.SetItemText(i, 1, dlg.num);
			m_list.SetItemText(i, 2, dlg.sex);
			m_list.SetItemText(i, 3, dlg.age);
			m_list.SetItemText(i, 4, dlg.tel);
			m_list.SetItemText(i, 5, dlg.wage);
		}
	}
}


void SystemDlg::OnBnClickedButton5()//ɾ����ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	for (int i = 0; i < m_list.GetItemCount(); i++)
	{
		BOOL state = m_list.GetCheck(i);
		if (state)
		{
			m_list.DeleteItem(i);
			i--;
		}
	}
	MessageBox(_T("ɾ����ɣ�"), _T("��ʾ"));
}


void SystemDlg::OnBnClickedButton6()//��Ӱ�ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	PropertyDlg dlg;
	dlg.DoModal();
	
	int cout=m_list.GetItemCount();
	m_list.InsertItem(cout, dlg.name);
	m_list.SetItemText(cout, 1, dlg.num);
	m_list.SetItemText(cout, 2, dlg.sex);
	m_list.SetItemText(cout, 3, dlg.age);
	m_list.SetItemText(cout, 4, dlg.tel);
	m_list.SetItemText(cout, 5, dlg.wage);
}

void temp(CString *a, CString *b)
{
	CString temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void SystemDlg::OnBnClickedButton8()//����ť
{
	double a[1000];
	CString a1[1000], a2[1000], a3[1000], a4[1000], a5[1000];
	CString cs, temp2, temp3, temp4, temp5;
	int n;
	double temp1;
	n = m_list.GetItemCount();
	for (int i = 0; i < n; i++)
	{

		a[i] = _ttof(m_list.GetItemText(i, 5));
		a1[i] = m_list.GetItemText(i, 3);
		a2[i] = m_list.GetItemText(i, 4);
		a3[i] = m_list.GetItemText(i, 1);
		a4[i] = m_list.GetItemText(i, 0);
		a5[i] = m_list.GetItemText(i, 2);
	}
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				temp1 = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp1;

				temp(a1 + j, a1 + j + 1);
				temp(a2 + j, a2 + j + 1);
				temp(a3 + j, a3 + j + 1);
				temp(a4 + j, a4 + j + 1);
				temp(a5 + j, a5 + j + 1);
			}
		}
	}
	for (int i = 0; i < m_list.GetItemCount(); i++)
	{
		cs.Format(_T("%0.4f"), a[i]);
		m_list.SetItemText(i, 5, cs);
		m_list.SetItemText(i, 4, a2[i]);
		m_list.SetItemText(i, 3, a1[i]);
		m_list.SetItemText(i, 1, a3[i]);
		m_list.SetItemText(i, 0, a4[i]);
		m_list.SetItemText(i, 2, a5[i]);
	}
	MessageBox(_T("������ɣ�"), _T("��ʾ"));
}

void SystemDlg::OnBnClickedButton9()//��
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog fDlg(TRUE, ".txt", _T("savedata"), OFN_OVERWRITEPROMPT, _T("�ı��ĵ�(*.txt)|*.txt|��������(*.dat)|*.dat|�����ļ�(*.*)|*.*||"), NULL);

	if (fDlg.DoModal() == IDOK)
	{
		CStdioFile file(fDlg.GetPathName(), CFile::modeRead);
		CString cs;
		int x = 0;
		int m, n, r, m1, n1, m2, n2, m3, n3;
		while (file.ReadString(cs))
		{
			int x1 = cs.Find(" ");
			int x2 = cs.Find(" ", x1 + 1);
			int x3 = cs.Find(" ", x2 + 1);
			int x4 = cs.Find(" ", x3 + 1);
			int x5 = cs.Find(" ", x4 + 1);
			m = x1 + 1;
			n = x2 - x1 - 1;
			r = cs.GetLength() - x5 - 1;
			m1 = x2 + 1;
			n1 = x3 - x2 - 1;
			m2 = x3 + 1;
			n2 = x4 - x3 - 1;
			m3 = x4 + 1;
			n3 = x5 - x4 - 1;
			m_list.InsertItem(x, cs.Left(x1));
			m_list.SetItemText(x, 1, cs.Mid(m, n));
			m_list.SetItemText(x, 2, cs.Mid(m1, n1));
			m_list.SetItemText(x, 3, cs.Mid(m2, n2));
			m_list.SetItemText(x, 4, cs.Mid(m3, n3));
			m_list.SetItemText(x, 5, cs.Right(r));
			x++;
		}
		MessageBox(_T("д����ϣ�"), _T("���ļ�"));
	}
}