#pragma once
#include "Resource.h"

// CRETURN 对话框

class CRETURN : public CDialog
{
	DECLARE_DYNAMIC(CRETURN)

public:
	CRETURN(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRETURN();

// 对话框数据
	enum { IDD = IDD_RETURN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString UserName;
};
