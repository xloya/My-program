#pragma once
#include "Resource.h"
#include "afxcmn.h"
#include "afxwin.h"

// CDIALOG_BOOKINFO 对话框

class CDIALOG_BOOKINFO : public CDialog
{
	DECLARE_DYNAMIC(CDIALOG_BOOKINFO)

public:
	CDIALOG_BOOKINFO(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDIALOG_BOOKINFO();
	CToolTipCtrl m_Mytip;

// 对话框数据
	enum { IDD = IDD_DIALOG_BOOKINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CListCtrl m_list;
	CComboBox m_Combo1;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
