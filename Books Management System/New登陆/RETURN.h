#pragma once
#include "Resource.h"

// CRETURN �Ի���

class CRETURN : public CDialog
{
	DECLARE_DYNAMIC(CRETURN)

public:
	CRETURN(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRETURN();

// �Ի�������
	enum { IDD = IDD_RETURN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString UserName;
};
