#pragma once
#include "Resource.h"
#include "afxcmn.h"
#include "afxwin.h"

// CDIALOG_SEARCH 对话框

class CDIALOG_SEARCH : public CDialog
{
	DECLARE_DYNAMIC(CDIALOG_SEARCH)

public:
	CDIALOG_SEARCH(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDIALOG_SEARCH();

// 对话框数据
	enum { IDD = IDD_DIALOG_SEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton4();
	CListCtrl m_list;
	afx_msg void OnBnClickedButton1();
	CComboBox m_Combo1;
	afx_msg void OnEnChange1002();
	CString m_UserName;
};
