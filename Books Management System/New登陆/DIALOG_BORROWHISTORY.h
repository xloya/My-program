#pragma once
#include "Resource.h"

// CDIALOG_BORROWHISTORY 对话框

class CDIALOG_BORROWHISTORY : public CDialog
{
	DECLARE_DYNAMIC(CDIALOG_BORROWHISTORY)

public:
	CDIALOG_BORROWHISTORY(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDIALOG_BORROWHISTORY();

// 对话框数据
	enum { IDD = IDD_DIALOG_BORROWHISTORY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
