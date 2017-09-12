// StdDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "New登陆.h"
#include "StdDlg.h"


// CStdDlg 对话框

IMPLEMENT_DYNAMIC(CStdDlg, CDialog)

CStdDlg::CStdDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStdDlg::IDD, pParent)
{

}

CStdDlg::~CStdDlg()
{
}

void CStdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}


BEGIN_MESSAGE_MAP(CStdDlg, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CStdDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CStdDlg 消息处理程序

BOOL CStdDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//----------设置TAB的标题-----------
	m_tab.InsertItem(0,"书籍查询");
	m_tab.InsertItem(1,"借阅查询");
	m_tab.InsertItem(2,"个人账户");
          
 

	//-------创建页面窗口-----------------------
	m_mm1.Create(IDD_DIALOG_SEARCH,GetDlgItem(IDC_TAB1));
	m_mm2.Create(IDD_DIALOG_RETURN,GetDlgItem(IDC_TAB1));
	m_mm4.Create(IDD_DIALOG_ACCOUNTINFO1,GetDlgItem(IDC_TAB1));



	//--------置父窗口-------------------------
	m_mm1.SetParent(GetDlgItem(IDC_TAB1));
	m_mm2.SetParent(GetDlgItem(IDC_TAB1));
	m_mm4.SetParent(GetDlgItem(IDC_TAB1));



	//-----定义窗口大小------------------
	RECT r1;
	r1.left=1;
	r1.top=22;
	r1.bottom=800;
	r1.right=1000;

	//-----设置窗口位置------------------------
	m_mm1.MoveWindow(&r1);
	m_mm2.MoveWindow(&r1);
	m_mm4.MoveWindow(&r1);
                      //---------默认显示page1                     	
	m_mm1.ShowWindow(TRUE);



	//-----初始化个人信息------------------------
	m_mm4.Name = Name;
	m_mm4.ID = ID;
	m_mm4.UserName = UserName;
	m_mm4.UpdateData(false);
	m_mm1.m_UserName = UserName;
	m_mm2.UserName = UserName;

//-----添加表格字段------------------------

	m_mm1.m_list.InsertColumn(0,_T("书籍名称"),200);
	m_mm1.m_list.InsertColumn(1,_T("图书编号"),200);
	m_mm1.m_list.InsertColumn(2,_T("书籍状态"),200);
	m_mm1.m_list.InsertColumn(3,_T("图书位置"),200);	
	m_mm1.m_list.InsertColumn(4,_T("ISBN"),200);
	m_mm1.m_list.InsertColumn(5,_T("作者"),200);
	m_mm1.m_list.InsertColumn(6,_T("类型"),200);
	m_mm1.m_list.SetColumnWidth(0, 100);
	m_mm1.m_list.SetColumnWidth(1, 100);
	m_mm1.m_list.SetColumnWidth(2, 100);
	m_mm1.m_list.SetColumnWidth(3, 100);
	m_mm1.m_list.SetColumnWidth(4, 100);
	m_mm1.m_list.SetColumnWidth(5, 100);
	m_mm1.m_list.SetColumnWidth(6, 100);

	m_mm2.m_list.InsertColumn(0,_T("书籍名称"),200);
	m_mm2.m_list.InsertColumn(1,_T("图书编号"),200);
	m_mm2.m_list.InsertColumn(2,_T("借书时间"),200);
	m_mm2.m_list.InsertColumn(3,_T("还书时间"),200);		
	m_mm2.m_list.SetColumnWidth(0, 100);
	m_mm2.m_list.SetColumnWidth(1, 100);
	m_mm2.m_list.SetColumnWidth(2, 100);
	m_mm2.m_list.SetColumnWidth(3, 100);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CStdDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	CRect r;
	m_tab.GetClientRect (&r);
	switch(m_tab.GetCurSel())//获取鼠标单击的选项卡.
	{
	case 0:
		{
			m_mm1.ShowWindow(TRUE);//显示鼠标单击的选项卡对应窗口.
			m_mm2.ShowWindow(FALSE);
			m_mm4.ShowWindow(FALSE);
			break;
		}
	case 1:
		{
			m_mm1.ShowWindow(FALSE);
			m_mm2.ShowWindow(TRUE);
			m_mm4.ShowWindow(FALSE);
			break;
		}
	case 2:
		{
			m_mm1.ShowWindow(FALSE);
			m_mm2.ShowWindow(FALSE);
			m_mm4.ShowWindow(TRUE);
			break;
		}

	}
	*pResult = 0;
}
