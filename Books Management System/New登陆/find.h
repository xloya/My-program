#pragma once


// Cfind �Ի���

class Cfind : public CDialog
{
	DECLARE_DYNAMIC(Cfind)

public:
	Cfind(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cfind();

// �Ի�������
	enum { IDD = IDD_FIND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_Username;
	CString m_StdName;
	CString m_StdID;
};
