// DIALOG_ACCOUNTINFO1.cpp : 实现文件
//

#include "stdafx.h"
#include "DIALOG_ACCOUNTINFO1.h"
#include "MySqlApi.h"
#include <iostream>
#include "string.h"
#include "New登陆Dlg.h"
// CDIALOG_ACCOUNTINFO1 对话框

IMPLEMENT_DYNAMIC(CDIALOG_ACCOUNTINFO1, CDialog)

CDIALOG_ACCOUNTINFO1::CDIALOG_ACCOUNTINFO1(CWnd* pParent /*=NULL*/)
	: CDialog(CDIALOG_ACCOUNTINFO1::IDD, pParent)
	, Name(_T(""))
	, ID(_T(""))
	, UserName(_T(""))
	, m_EXPwd(_T(""))
	, m_Pwd(_T(""))
{

}

CDIALOG_ACCOUNTINFO1::~CDIALOG_ACCOUNTINFO1()
{
}

void CDIALOG_ACCOUNTINFO1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDD_DIALOG_ACCOUNT_NAME, Name);
	DDX_Text(pDX, IDD_DIALOG_ACCOUNT_ID, ID);
	DDX_Text(pDX, IDD_DIALOG_ACCOUNT_USER, UserName);
	DDX_Control(pDX, IDD_DIALOG_ACCOUNT_NAME, IDD_Name);
	DDX_Text(pDX, IDD_DIALOG_ACCOUNT_PWD1, m_EXPwd);
	DDX_Text(pDX, IDD_DIALOG_ACCOUNT_PWD2, m_Pwd);
}


BEGIN_MESSAGE_MAP(CDIALOG_ACCOUNTINFO1, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDIALOG_ACCOUNTINFO1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDIALOG_ACCOUNTINFO1::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDIALOG_ACCOUNTINFO1 消息处理程序

void CDIALOG_ACCOUNTINFO1::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	std::string TempPwd = CT2A(m_EXPwd.GetBuffer());
	std::string NewPwd = CT2A(m_Pwd.GetBuffer());

	if(m_EXPwd.IsEmpty() == 1||  m_Pwd.IsEmpty() ==1)
	{
		MessageBox("请输入信息");
	}
	else 
	{

		std::string Table = "StudentTable";
	std::string Username = "root";
	std::string Password = "";
	std::string Database = "library";
	std::string KeyWord =  CT2A(UserName.GetBuffer());
	std::string KeyWordField = "UserName";
		MySqlApi Api;

		std::string row[4];
		if(Api.selectRowExists(Username,Password,Database,Table,row,KeyWordField,KeyWord) !=0){
			if(row[1].compare(TempPwd) == 0){
						
				Api.deletetRow(Username,Password,Database,Table,KeyWordField,KeyWord);
				std::string value = " (\"" + row[0] + "\",\""+ NewPwd + "\",\"" + row[2] + "\",\"" + row[3] +"\")  ";
				Api.insertRow(Username,Password,Database,Table,value);
				MessageBox("修改成功！");
				GetDlgItem(IDD_DIALOG_ACCOUNT_PWD1)->SetWindowText(_T(""));
				GetDlgItem(IDD_DIALOG_ACCOUNT_PWD2)->SetWindowText(_T(""));
			}
			else{

				MessageBox("原密码错误！");
			}	
			
			
		}
		else{
				MessageBox("？未知错误");
			
		}

	
	}
}

void CDIALOG_ACCOUNTINFO1::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CNew登陆Dlg Logout;
	GetParent()->GetParent()->SendMessage(WM_CLOSE);
	Logout.DoModal();
}
