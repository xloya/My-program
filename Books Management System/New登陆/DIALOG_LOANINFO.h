#pragma once
#include "Resource.h"
#include "afxwin.h"
#include "afxcmn.h"

// CDIALOG_LOANINFO �Ի���

class CDIALOG_LOANINFO : public CDialog
{
	DECLARE_DYNAMIC(CDIALOG_LOANINFO)

public:
	CDIALOG_LOANINFO(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDIALOG_LOANINFO();

// �Ի�������
	enum { IDD = IDD_DIALOG_LOANINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_Combo;
	CComboBox m_Combo1;
	CComboBox m_Combo3;
	CListCtrl m_list;
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton6();
};
