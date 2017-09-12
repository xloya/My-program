// DIALOG_BOOKINFO.cpp : 实现文件
//

#include "stdafx.h"
#include "DIALOG_BOOKINFO.h"
#include "MySqlApi.h"
#include <WinSock.h>
#include "mysql.h"
#include <stdio.h>
#include <iostream>
#pragma comment(lib,"wsock32.lib")
#pragma comment(lib,"libmysql.lib")



// CDIALOG_BOOKINFO 对话框

IMPLEMENT_DYNAMIC(CDIALOG_BOOKINFO, CDialog)

CDIALOG_BOOKINFO::CDIALOG_BOOKINFO(CWnd* pParent /*=NULL*/)
	: CDialog(CDIALOG_BOOKINFO::IDD, pParent)
{

}

CDIALOG_BOOKINFO::~CDIALOG_BOOKINFO()
{
}

void CDIALOG_BOOKINFO::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
}


BEGIN_MESSAGE_MAP(CDIALOG_BOOKINFO, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDIALOG_BOOKINFO::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &CDIALOG_BOOKINFO::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON3, &CDIALOG_BOOKINFO::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDIALOG_BOOKINFO::OnBnClickedButton4)
END_MESSAGE_MAP()


// CDIALOG_BOOKINFO 消息处理程序

void CDIALOG_BOOKINFO::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_list.DeleteAllItems();//清空
	std::string Table = "booktable";
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
	else
	{			
		switch(type)
		{
				case 2: KeyWordField = "BookName" ;break;
				case 0: KeyWordField = "BookISBN"; break;
				case 4: KeyWordField = "BookID";  break;
				case 1: KeyWordField = "BookKind";break;
				case 5: KeyWordField = "BookLocation" ;break;
				case 3: KeyWordField = "BookState";break;
				case 6: KeyWordField = "BookAuthor";break;
				default: CString message;
					message = "查找类型错误";
					MessageBox(message,"提示");break;

		}
		MySqlApi Api;
		std::string data[20][10];
		int n = Api.fuzzyQuery(UserName,Password,Database,Table,data,KeyWordField,KeyWord);
		if(n!= 0)
		{
			for(int r = 0;data[r][0].compare("");r++)
			{
				std::string result[20][10];
				if(Api.selectTable(UserName,Password,Database,"booktable",result,"BookID",data[r][1]) != 0)
				{
					m_list.InsertItem(r,"");
					for(int i =0;i<7;i++){
					m_list.SetItemText(r,i,result[0][i].c_str());			
				}
			}
			else
			{
				break;	
			}
		}
	}
	else
	{
			CString message;
			message = "未找到查询内容";
			MessageBox(message,"错误");
	}
	}
}

void CDIALOG_BOOKINFO::OnBnClickedButton5()
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

	CString bookname;

	GetDlgItemText(IDD_DIALOG_BOOK_NAME,bookname);
	CString bookisbn;

	GetDlgItemText(IDD_DIALOG_BOOK_ISBN,bookisbn);
	CString bookkind;

	GetDlgItemText(IDD_DIALOG_BOOK_TYPE,bookkind);
	CString bookauthor;

	GetDlgItemText(IDD_DIALOG_BOOK_AUTHOR,bookauthor);
	CString bookid;

	GetDlgItemText(IDD_DIALOG_BOOK_NUMBER,bookid);
	CString booklocation;

	GetDlgItemText(IDD_DIALOG_BOOK_PLACE,booklocation);


	char *buf = new char[200]; 
	sprintf(buf,"INSERT INTO booktable(bookname,bookid,bookstate,booklocation,bookisbn,bookauthor,bookkind) VALUES('%s', '%s',\"in\", '%s', '%s', '%s', '%s')",bookname,bookid,booklocation,bookisbn,bookauthor,bookkind);  
  
	if(!mysql_query(&mysql, buf)) 
 { 
		CString   sTemp;
		sTemp= "插入成功!";
		MessageBox(sTemp,"提示");
		GetDlgItem(IDD_DIALOG_BOOK_NAME)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_BOOK_ISBN)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_BOOK_TYPE)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_BOOK_AUTHOR)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_BOOK_NUMBER)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_BOOK_PLACE)->SetWindowText(_T(""));
 } 
 else 
 { 
		CString   sTemp;
		sTemp= "插入失败!";
		MessageBox(sTemp,"提示");  
 }
}

void CDIALOG_BOOKINFO::OnBnClickedButton3()
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
	CString bookname;

	GetDlgItemText(IDD_DIALOG_BOOK_NAME,bookname);
	CString bookisbn;

	GetDlgItemText(IDD_DIALOG_BOOK_ISBN,bookisbn);
	CString bookkind;

	GetDlgItemText(IDD_DIALOG_BOOK_TYPE,bookkind);
	CString bookauthor;

	GetDlgItemText(IDD_DIALOG_BOOK_AUTHOR,bookauthor);
	CString bookid;

	GetDlgItemText(IDD_DIALOG_BOOK_NUMBER,bookid);
	CString booklocation;

	GetDlgItemText(IDD_DIALOG_BOOK_PLACE,booklocation);
	if(bookname.IsEmpty()){
			CString message;
			message = "请输入书籍名称";
			MessageBox(message,"提示");}
	else if(bookisbn.IsEmpty())
		{
			CString message;
			message = "请输入ISBN";
			MessageBox(message,"提示");}
	else if(bookkind.IsEmpty())
		{
			CString message;
			message = "请输入书籍种类";
			MessageBox(message,"提示");}
	else if(bookauthor.IsEmpty())
		{
			CString message;
			message = "请输入书籍作者";
			MessageBox(message,"提示");}
	else if(booklocation.IsEmpty())
		{
			CString message;
			message = "请输入书籍位置";
			MessageBox(message,"提示");}
	else if(bookid.IsEmpty())
		{
			CString message;
			message = "请输入书籍唯一编号";
			MessageBox(message,"提示");}
	else 
	{
	
	char *def = new char[200]; 
	sprintf(def,"DELETE FROM booktable WHERE BookID='%s'", bookid); 
  
	if(!mysql_query(&mysql, def)) 
	{ 
		
	} 
	else 
	{ 
		
	}
	char *buf = new char[200]; 
	sprintf(buf,"INSERT INTO booktable(bookname,bookid,bookstate,booklocation,bookisbn,bookauthor,bookkind) VALUES('%s', '%s',\"in\", '%s', '%s', '%s', '%s')",bookname,bookid,booklocation,bookisbn,bookauthor,bookkind);  
  
	if(!mysql_query(&mysql, buf)) 
 { 
			CString   sTemp;
		sTemp= "修改成功!";
		MessageBox(sTemp,"提示");
		GetDlgItem(IDD_DIALOG_BOOK_NAME)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_BOOK_ISBN)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_BOOK_TYPE)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_BOOK_AUTHOR)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_BOOK_NUMBER)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_BOOK_PLACE)->SetWindowText(_T(""));
 } 
 else 
 { 
		
	 	CString   sTemp;
		sTemp= "修改失败!";
		MessageBox(sTemp,"提示");  
 }
	}
}

void CDIALOG_BOOKINFO::OnBnClickedButton4()
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
	CString bookid;

	GetDlgItemText(IDD_DIALOG_BOOK_NUMBER,bookid);
	char *buf = new char[200]; 
	sprintf(buf,"DELETE FROM booktable WHERE BookID='%s'", bookid); 
  
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

BOOL CDIALOG_BOOKINFO::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_Mytip.Create(this);  
	m_Mytip.AddTool(GetDlgItem(IDC_BUTTON3), "修改不可修改唯一编号！" ); //IDC_BUTTON为你要添加提示信息的按钮的ID
	m_Mytip.AddTool(GetDlgItem(IDC_BUTTON4), "删除请输入唯一编号！" );
	m_Mytip.SetDelayTime(200); //设置延迟
	m_Mytip.SetTipTextColor( RGB(255,0,0) ); //设置提示文本的颜色
	m_Mytip.SetTipBkColor( RGB(255,255,255)); //设置提示框的背景颜色
	m_Mytip.Activate(TRUE); //设置是否启用提示
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

BOOL CDIALOG_BOOKINFO::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_MOUSEMOVE)
	m_Mytip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}
