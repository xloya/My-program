#pragma once
#include "Resource.h"

// CBORROW 对话框

class CBORROW : public CDialog
{
	DECLARE_DYNAMIC(CBORROW)

public:
	CBORROW(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBORROW();

// 对话框数据
	enum { IDD = IDD_BORROW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_BookID;
	afx_msg void OnBnClickedButton1();
	CString UserName;
};
