#pragma once
#include "Resource.h"
#include "afxwin.h"


// CDIALOG_ACCOUNTINFO1 对话框

class CDIALOG_ACCOUNTINFO1 : public CDialog
{
	DECLARE_DYNAMIC(CDIALOG_ACCOUNTINFO1)

public:
	CDIALOG_ACCOUNTINFO1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDIALOG_ACCOUNTINFO1();

// 对话框数据
	enum { IDD = IDD_DIALOG_ACCOUNTINFO1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString Name;
	CString ID;
	CString UserName;
	CEdit IDD_Name;
	afx_msg void OnBnClickedButton1();
	CString m_EXPwd;
	CString m_Pwd;
	afx_msg void OnBnClickedButton2();
};
