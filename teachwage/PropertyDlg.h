#pragma once


// PropertyDlg �Ի���

class PropertyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PropertyDlg)

public:
	PropertyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PropertyDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString num;
	CString age;
	CString tel;
	CString wage;
	CString sex;
	afx_msg void OnBnClickedButton1();
};
