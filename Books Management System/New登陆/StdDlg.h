#pragma once
#include "afxcmn.h"
#include "DIALOG_SEARCH.h"
#include "DIALOG_RETURN.h"
#include "DIALOG_BORROWHISTORY.h"
#include "DIALOG_ACCOUNTINFO1.h"

// CStdDlg �Ի���

class CStdDlg : public CDialog
{
	DECLARE_DYNAMIC(CStdDlg)

public:
	CStdDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStdDlg();
	
// �Ի�������
	enum { IDD = IDD_Std };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	CDIALOG_SEARCH m_mm1;
	CDIALOG_RETURN m_mm2;
	CDIALOG_BORROWHISTORY m_mm3;
	CDIALOG_ACCOUNTINFO1 m_mm4;

	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
public:
	CString Name;
	CString ID;
	CString UserName;

};
