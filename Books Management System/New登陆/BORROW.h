#pragma once
#include "Resource.h"

// CBORROW �Ի���

class CBORROW : public CDialog
{
	DECLARE_DYNAMIC(CBORROW)

public:
	CBORROW(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBORROW();

// �Ի�������
	enum { IDD = IDD_BORROW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_BookID;
	afx_msg void OnBnClickedButton1();
	CString UserName;
};
