#pragma once
#include "Resource.h"
#include "afxwin.h"
#include "afxcmn.h"

// CDIALOG_USERINFO �Ի���

class CDIALOG_USERINFO : public CDialog
{
	DECLARE_DYNAMIC(CDIALOG_USERINFO)

public:
	CDIALOG_USERINFO(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDIALOG_USERINFO();
	CToolTipCtrl m_Mytip;

// �Ի�������
	enum { IDD = IDD_DIALOG_USERINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CComboBox m_Combo1;
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
