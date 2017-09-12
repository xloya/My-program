#pragma once
#include "Resource.h"
#include "afxcmn.h"
#include "afxwin.h"

// CDIALOG_RETURN 对话框

class CDIALOG_RETURN : public CDialog
{
	DECLARE_DYNAMIC(CDIALOG_RETURN)

public:
	CDIALOG_RETURN(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDIALOG_RETURN();

// 对话框数据
	enum { IDD = IDD_DIALOG_RETURN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton7();
	CListCtrl m_list;
	CComboBox m_Combo1;
	CString UserName;
};
