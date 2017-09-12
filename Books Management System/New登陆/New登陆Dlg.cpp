// New登陆Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "New登陆.h"
#include "New登陆Dlg.h"
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
int power=2;
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CNew登陆Dlg 对话框




CNew登陆Dlg::CNew登陆Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNew登陆Dlg::IDD, pParent)
	, m_password(_T(""))
	, m_Username(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNew登陆Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDX_Text(pDX, IDC_USERNAME, m_Username);
}

BEGIN_MESSAGE_MAP(CNew登陆Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CNew登陆Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CNew登陆Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO1, &CNew登陆Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CNew登陆Dlg::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CNew登陆Dlg 消息处理程序

BOOL CNew登陆Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CNew登陆Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CNew登陆Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CNew登陆Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CNew登陆Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Cfind dlg;
	dlg.DoModal();
}

void CNew登陆Dlg::OnBnClickedOk()
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
		message = "请输入用户名";
		MessageBox(message,"提示");
	}
	else
	{
		key_UserName = CT2A(m_Username.GetBuffer());
	}
	if(m_password.IsEmpty())
	{
		CString message;
		message = "请输入密码";
		MessageBox(message,"提示");
	}
	else
	{
		key_Password = CT2A(m_password.GetBuffer());
	}
	if(power == 2)
	{
		CString message;
		message = "请选择用户类型";
		MessageBox(message,"提示");
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
			MessageBox("用户不存在","提示");
		}
		else 
		{
			if(row[1].compare(key_Password.c_str()) == 0)
		{
			MessageBox("登录成功","提示");
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
			MessageBox("密码错误");
		}
	}
}
}
void CNew登陆Dlg::OnBnClickedRadio1()
{
	power =0;
	// TODO: 在此添加控件通知处理程序代码
}

void CNew登陆Dlg::OnBnClickedRadio2()
{
	power =1;
	// TODO: 在此添加控件通知处理程序代码
}
