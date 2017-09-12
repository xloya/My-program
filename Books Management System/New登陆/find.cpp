// find.cpp : 实现文件
//

#include "stdafx.h"
#include "New登陆.h"
#include "find.h"
#include "windows.h"
#include <string.h>
#include "MySqlApi.h"
#include<iostream>
// Cfind 对话框

IMPLEMENT_DYNAMIC(Cfind, CDialog)

Cfind::Cfind(CWnd* pParent /*=NULL*/)
	: CDialog(Cfind::IDD, pParent)
	, m_Username(_T(""))
	, m_StdName(_T(""))
	, m_StdID(_T(""))
{

}

Cfind::~Cfind()
{
}

void Cfind::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME, m_Username);
	DDX_Text(pDX, IDC_STDNAME, m_StdName);
	DDX_Text(pDX, IDC_STDID, m_StdID);
}


BEGIN_MESSAGE_MAP(Cfind, CDialog)
	ON_BN_CLICKED(IDOK, &Cfind::OnBnClickedOk)
END_MESSAGE_MAP()


// Cfind 消息处理程序

void Cfind::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	MySqlApi MySql;
	std::string Table = "Studenttable";
	std::string UserName = "root";
	std::string password = "";
	std::string database = "library";
	std::string key_UserName;
	std::string key_Name;
	std::string key_ID;
	UpdateData(true);
	if(m_Username.IsEmpty())
	{
		CString message;
		message = "请输入用户名";
		MessageBox(message);
	}
	else
	{
		key_UserName = CT2A(m_Username.GetBuffer());
	}
	if(m_StdName.IsEmpty())
	{
		CString message;
		message = "请输入姓名";
		MessageBox(message);
	}
	else
	{
		key_Name = CT2A(m_StdName.GetBuffer());
	}
	if(m_StdID.IsEmpty())
	{
		CString message;
		message = "请输入学号/ID";
		MessageBox(message);
	}
	else
	{
		key_ID = CT2A(m_StdID.GetBuffer());
	}
		std::string rowf[4];
		if(MySql.selectRowExists(UserName,password,database,"StudentTable",rowf,"UserName",key_UserName)==0
			&& MySql.selectRowExists(UserName,password,database,"AdminTable",rowf,"UserName",key_UserName)==0)
		{
			MessageBox("用户不存在");
		}
		else 
		{
			if(MySql.selectRowExists(UserName,password,database,"StudentTable",rowf,"UserName",key_UserName)==1)
			{
				if((rowf[2].compare(key_Name.c_str()) == 0)&&(rowf[3].compare(key_ID.c_str())==0))
				{
					CString t = "信息正确！你的密码是" ;
					MessageBox(t + rowf[1].c_str());
				}
				else MessageBox("信息错误！请重新输入！");
			}
			if(MySql.selectRowExists(UserName,password,database,"AdminTable",rowf,"UserName",key_UserName)==1)
			{
				if((rowf[2].compare(key_Name.c_str()) == 0)&&(rowf[3].compare(key_ID.c_str())==0))
				{
					CString t = "信息正确！你的密码是" ;
					MessageBox(t + rowf[1].c_str());
				}
				else MessageBox("信息错误！请重新输入！");
			}
	}
}