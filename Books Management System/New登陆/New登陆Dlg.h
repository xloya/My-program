// New��½Dlg.h : ͷ�ļ�
//
#include "string.h"
#pragma once



// CNew��½Dlg �Ի���
class CNew��½Dlg : public CDialog
{
// ����
public:
	CNew��½Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_NEW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
