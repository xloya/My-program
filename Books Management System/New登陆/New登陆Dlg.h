// New登陆Dlg.h : 头文件
//
#include "string.h"
#pragma once



// CNew登陆Dlg 对话框
class CNew登陆Dlg : public CDialog
{
// 构造
public:
	CNew登陆Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_NEW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	CString m_password;
	afx_msg void OnBnClickedOk();
	CString m_Username;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();

};
