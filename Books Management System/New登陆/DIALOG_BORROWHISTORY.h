#pragma once
#include "Resource.h"

// CDIALOG_BORROWHISTORY �Ի���

class CDIALOG_BORROWHISTORY : public CDialog
{
	DECLARE_DYNAMIC(CDIALOG_BORROWHISTORY)

public:
	CDIALOG_BORROWHISTORY(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDIALOG_BORROWHISTORY();

// �Ի�������
	enum { IDD = IDD_DIALOG_BORROWHISTORY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
