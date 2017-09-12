// New��½Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "New��½.h"
#include "New��½Dlg.h"
#include "find.h"
#include "windows.h"
#include "string.h"
#include<iostream>
#include "MySqlApi.h"
#include "StdDlg.h"
#include "AdmDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
int power=2;
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CNew��½Dlg �Ի���




CNew��½Dlg::CNew��½Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNew��½Dlg::IDD, pParent)
	, m_password(_T(""))
	, m_Username(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNew��½Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDX_Text(pDX, IDC_USERNAME, m_Username);
}

BEGIN_MESSAGE_MAP(CNew��½Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CNew��½Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CNew��½Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO1, &CNew��½Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CNew��½Dlg::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CNew��½Dlg ��Ϣ�������

BOOL CNew��½Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CNew��½Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CNew��½Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CNew��½Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CNew��½Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Cfind dlg;
	dlg.DoModal();
}

void CNew��½Dlg::OnBnClickedOk()
{	
	MySqlApi MySql;
	std::string Table;
	std::string UserName = "root";
	std::string password = "";
	std::string database = "library";
	std::string key_UserName;
	std::string key_Password;
	UpdateData(true);
	if(m_Username.IsEmpty())
	{
		CString message;
		message = "�������û���";
		MessageBox(message,"��ʾ");
	}
	else
	{
		key_UserName = CT2A(m_Username.GetBuffer());
	}
	if(m_password.IsEmpty())
	{
		CString message;
		message = "����������";
		MessageBox(message,"��ʾ");
	}
	else
	{
		key_Password = CT2A(m_password.GetBuffer());
	}
	if(power == 2)
	{
		CString message;
		message = "��ѡ���û�����";
		MessageBox(message,"��ʾ");
	}
	else
	{
		if(power == 0)
		{
			Table = "StudentTable";
		}
		else if(power ==1)
		{
			Table = "AdminTable";
		}
		std::string row[4];
		if(MySql.selectRowExists(UserName,password,database,Table,row,"UserName",key_UserName)==0)
		{
			MessageBox("�û�������","��ʾ");
		}
		else 
		{
			if(row[1].compare(key_Password.c_str()) == 0)
		{
			MessageBox("��¼�ɹ�","��ʾ");
			if(Table == "StudentTable")
			{
				CStdDlg dlg;
				dlg.Name = CT2A(row[2].c_str());
				dlg.UserName = CT2A(row[0].c_str());
				dlg.ID = CT2A(row[3].c_str());
				OnOK();

				dlg.DoModal();
			}
			if(Table == "AdminTable")
			{
				
				
				CAdmDlg dlg;
				dlg.Name = CT2A(row[2].c_str());
				dlg.UserName = CT2A(row[0].c_str());
				dlg.ID = CT2A(row[3].c_str());

				OnOK();
				dlg.DoModal();
				
			}
		}
		else
		{
			MessageBox("�������");
		}
	}
}
}
void CNew��½Dlg::OnBnClickedRadio1()
{
	power =0;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CNew��½Dlg::OnBnClickedRadio2()
{
	power =1;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
