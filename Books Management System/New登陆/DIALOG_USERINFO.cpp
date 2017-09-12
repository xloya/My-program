// DIALOG_USERINFO.cpp : 实现文件
//

#include "stdafx.h"
#include "DIALOG_USERINFO.h"
#include "MySqlApi.h"
#include <WinSock.h>
#include "mysql.h"
#include <stdio.h>
#include <iostream>
#pragma comment(lib,"wsock32.lib")
#pragma comment(lib,"libmysql.lib")



// CDIALOG_USERINFO 对话框

IMPLEMENT_DYNAMIC(CDIALOG_USERINFO, CDialog)

CDIALOG_USERINFO::CDIALOG_USERINFO(CWnd* pParent /*=NULL*/)
	: CDialog(CDIALOG_USERINFO::IDD, pParent)
{

}

CDIALOG_USERINFO::~CDIALOG_USERINFO()
{
}

void CDIALOG_USERINFO::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CDIALOG_USERINFO, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDIALOG_USERINFO::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDIALOG_USERINFO::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDIALOG_USERINFO::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDIALOG_USERINFO::OnBnClickedButton4)
END_MESSAGE_MAP()


// CDIALOG_USERINFO 消息处理程序

void CDIALOG_USERINFO::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_list.DeleteAllItems();//清空
	std::string Table = "studenttable";
	std::string UserName = "root";
	std::string Password = "";
	std::string Database = "library";
	std::string KeyWord ;
	std::string KeyWordField;
	std::string Type;
	int type = m_Combo1.GetCurSel();
	CString keyword;

	GetDlgItemText(IDC_EDIT1,keyword);
	KeyWord = CT2A(keyword.GetBuffer());


	if(type == -1){
		CString message;
		message = "请选择查找类型";
		MessageBox(message,"提示");

	}
	else{			
		switch(type){
				case 0: KeyWordField = "StudentName" ;break;
				case 1: KeyWordField = "StudentID"; break;
				case 2: KeyWordField = "UserName";  break;


				default: CString message;
					message = "查找类型错误";
					MessageBox(message,"提示");break;
		}
			MySqlApi Api;
			std::string data[20][10];
			int n = Api.fuzzyQuery(UserName,Password,Database,Table,data,KeyWordField,KeyWord);




			if(n!= 0){

				
				for(int r = 0;data[r][0].compare("");r++){
					
					

						m_list.InsertItem(r,"");
						for(int i =0;i<4;i++){

							m_list.SetItemText(r,i,data[r][i].c_str());
								
							

					}




				}
			}
			else{
				CString message;
				message = "未找到查询内容";
				MessageBox(message,"提示");

			}

		}



	

}

void CDIALOG_USERINFO::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	MYSQL mysql; //Mysql对象  
	if(mysql_init(&mysql)) 
	{ 
	if(mysql_real_connect(&mysql, "localhost","root" , "", "library", 3306, NULL, 0))  
	{ 
		CString   sTemp;
		sTemp= "连接成功!";
		MessageBox(sTemp,"提示");  
	 } 
	 else 
	{ 
	mysql_close(&mysql); 
		CString   sTemp;
		sTemp= "连接失败!";
		MessageBox(sTemp,"提示");  
	 } 
	} 
	else 
	{ 
			CString   sTemp;
		sTemp= "初始化失败!";
		MessageBox(sTemp,"提示");  
	}

	CString username;

	GetDlgItemText(IDD_DIALOG_USER_NAME,username);
	CString studentid;

	GetDlgItemText(IDD_DIALOG_USER_ID,studentid);
	CString studentname;

	GetDlgItemText(IDD_DIALOG_USER_USER,studentname);
	CString password;

	GetDlgItemText(IDD_DIALOG_USER_PWD,password);




	char *buf = new char[200]; 
	sprintf(buf,"INSERT INTO studenttable(username,password,studentname,studentid) VALUES('%s', '%s', '%s', '%s')",username,password,studentname,studentid);  
  
	if(!mysql_query(&mysql, buf)) 
 { 
		CString   sTemp;
		sTemp= "添加成功!";
		MessageBox(sTemp,"提示");
		GetDlgItem(IDD_DIALOG_USER_NAME)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_USER_USER)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_USER_ID)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_USER_PWD)->SetWindowText(_T(""));
 } 
 else 
 { 
		CString   sTemp;
		sTemp= "添加失败!";
		MessageBox(sTemp,"提示");  
 }
}

void CDIALOG_USERINFO::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	MYSQL mysql; //Mysql对象  
	if(mysql_init(&mysql)) 
	{ 
	if(mysql_real_connect(&mysql, "localhost","root" , "", "library", 3306, NULL, 0))  
	{ 
		CString   sTemp;
		sTemp= "连接成功!";
		MessageBox(sTemp,"提示");  
	 } 
	 else 
	{ 
	mysql_close(&mysql); 
		CString   sTemp;
		sTemp= "连接失败!";
		MessageBox(sTemp,"提示");  
	 } 
	} 
	else 
	{ 
			CString   sTemp;
		sTemp= "初始化失败!";
		MessageBox(sTemp,"提示");  
	}
	CString studentname;

	GetDlgItemText(IDD_DIALOG_USER_NAME,studentname);
	CString studentid;

	GetDlgItemText(IDD_DIALOG_USER_ID,studentid);
	CString username;

	GetDlgItemText(IDD_DIALOG_USER_USER,username);
	CString password;

	GetDlgItemText(IDD_DIALOG_USER_PWD,password);

	if(studentname.IsEmpty()){
			CString message;
			message = "请输入姓名";
			MessageBox(message,"提示");}
	else if(studentid.IsEmpty())
		{
			CString message;
			message = "请输入学号";
			MessageBox(message,"提示");}
	else if(username.IsEmpty())
		{
			CString message;
			message = "请输入用户名";
			MessageBox(message,"提示");}
	else if(password.IsEmpty())
		{
			CString message;
			message = "请输入密码";
			MessageBox(message,"提示");}
	else 
	{
	
	char *def = new char[200]; 
	sprintf(def,"DELETE FROM studenttable WHERE UserName='%s'", username); 
  
	if(!mysql_query(&mysql, def)) 
	{ 
		
	} 
	else 
	{ 
		
	}
	char *buf = new char[200]; 
	sprintf(buf,"INSERT INTO studenttable(username,password,studentname,studentid) VALUES('%s', '%s','%s', '%s')",username,password,studentname,studentid);  
  
	if(!mysql_query(&mysql, buf)) 
 { 
		CString   sTemp;
		sTemp= "修改成功!";
		MessageBox(sTemp,"提示");
		GetDlgItem(IDD_DIALOG_USER_NAME)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_USER_USER)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_USER_ID)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_USER_PWD)->SetWindowText(_T(""));
 } 
 else 
 { 
		
	 	CString   sTemp;
		sTemp= "修改失败!";
		MessageBox(sTemp,"提示");  
 }
	}
}

void CDIALOG_USERINFO::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	MYSQL mysql; //Mysql对象  
	if(mysql_init(&mysql)) 
	{ 
	if(mysql_real_connect(&mysql, "localhost","root" , "", "library", 3306, NULL, 0))  
	{ 
		CString   sTemp;
		sTemp= "连接成功!";
		MessageBox(sTemp,"提示");  
	 } 
	 else 
	{ 
		mysql_close(&mysql); 
		CString   sTemp;
		sTemp= "连接失败!";
		MessageBox(sTemp,"提示");  
	 } 
	} 
	else 
	{ 
		CString   sTemp;
		sTemp= "初始化失败!";
		MessageBox(sTemp,"提示");  
	}
	CString username;

	GetDlgItemText(IDD_DIALOG_USER_USER,username);
	char *buf = new char[200]; 
	sprintf(buf,"DELETE FROM studenttable WHERE UserName='%s'", username); 
  
	if(!mysql_query(&mysql, buf)) 
	{ 
		CString   sTemp;
		sTemp= "删除成功!";
		MessageBox(sTemp,"提示");  
	
	} 
	else 
	{ 
		CString   sTemp;
		sTemp= "删除失败!";
		MessageBox(sTemp,"提示");  
	}
}

BOOL CDIALOG_USERINFO::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_Mytip.Create(this);  
	m_Mytip.AddTool(GetDlgItem(IDC_BUTTON3), "修改不可修改用户名" ); //IDC_BUTTON为你要添加提示信息的按钮的ID
	m_Mytip.AddTool(GetDlgItem(IDC_BUTTON4), "删除请输入用户名！" );
	m_Mytip.SetDelayTime(200); //设置延迟
	m_Mytip.SetTipTextColor( RGB(255,0,0) ); //设置提示文本的颜色
	m_Mytip.SetTipBkColor( RGB(255,255,255)); //设置提示框的背景颜色
	m_Mytip.Activate(TRUE); //设置是否启用提示
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

BOOL CDIALOG_USERINFO::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_MOUSEMOVE)
	m_Mytip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}
