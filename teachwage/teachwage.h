
// teachwage.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CteachwageApp: 
// �йش����ʵ�֣������ teachwage.cpp
//

class CteachwageApp : public CWinApp
{
public:
	CteachwageApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CteachwageApp theApp;