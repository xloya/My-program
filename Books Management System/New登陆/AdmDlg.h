#pragma once
#include "afxcmn.h"
#include "DIALOG_BOOKINFO.h"
#include "DIALOG_LOANINFO.h"
#include "DIALOG_USERINFO.h"
#include "DIALOG_ACCOUNTINFO.h"


// CAdmDlg �Ի���

class CAdmDlg : public CDialog
{
	DECLARE_DYNAMIC(CAdmDlg)

public:
	CAdmDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAdmDlg();

// �Ի�������
	enum { IDD = IDD_Admin };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl m_tabctrl;
	CDIALOG_BOOKINFO m_mm1;
	CDIALOG_LOANINFO m_mm2;
	CDIALOG_USERINFO m_mm3;
	CDIALOG_ACCOUNTINFO m_mm4;
	virtual BOOL OnInitDialog();
public:
	CString Name;
	CString ID;
	CString UserName;
};
