#pragma once
#include "Resource.h"


// CDIALOG_ACCOUNTINFO 对话框

class CDIALOG_ACCOUNTINFO : public CDialog
{
	DECLARE_DYNAMIC(CDIALOG_ACCOUNTINFO)

public:
	CDIALOG_ACCOUNTINFO(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDIALOG_ACCOUNTINFO();

// 对话框数据
	enum { IDD = IDD_DIALOG_ACCOUNTINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString Name;
	CString ID;
	CString UserName;
	CString m_EXPwd;
	CString m_Pwd;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
