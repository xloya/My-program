#pragma once


// Cfind 对话框

class Cfind : public CDialog
{
	DECLARE_DYNAMIC(Cfind)

public:
	Cfind(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cfind();

// 对话框数据
	enum { IDD = IDD_FIND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_Username;
	CString m_StdName;
	CString m_StdID;
};
