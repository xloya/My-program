// New��½.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
typedef char CUserInfo;
// CNew��½App:
// �йش����ʵ�֣������ New��½.cpp
//

class CNew��½App : public CWinApp
{
public:
	CNew��½App();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CNew��½App theApp;
