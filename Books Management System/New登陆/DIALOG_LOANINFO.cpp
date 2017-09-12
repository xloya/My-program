// DIALOG_LOANINFO.cpp : 实现文件
//

#include "stdafx.h"
#include "DIALOG_LOANINFO.h"
#include "MySqlApi.h"
#include <iostream>

// CDIALOG_LOANINFO 对话框

IMPLEMENT_DYNAMIC(CDIALOG_LOANINFO, CDialog)

CDIALOG_LOANINFO::CDIALOG_LOANINFO(CWnd* pParent /*=NULL*/)
	: CDialog(CDIALOG_LOANINFO::IDD, pParent)
{

}

CDIALOG_LOANINFO::~CDIALOG_LOANINFO()
{
}

void CDIALOG_LOANINFO::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, m_Combo);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_COMBO3, m_Combo3);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CDIALOG_LOANINFO, CDialog)
	ON_BN_CLICKED(IDC_BUTTON7, &CDIALOG_LOANINFO::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON1, &CDIALOG_LOANINFO::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &CDIALOG_LOANINFO::OnBnClickedButton6)
END_MESSAGE_MAP()


// CDIALOG_LOANINFO 消息处理程序

void CDIALOG_LOANINFO::OnBnClickedButton7()
{

	UpdateData(true);
	m_list.DeleteAllItems();//清空
	std::string Table = "studentTable";
	std::string UserName = "root";
	std::string Password = "";
	std::string Database = "library";
	std::string KeyWord ;
	std::string KeyWordField;
	std::string Type;
	int type = m_Combo.GetCurSel();
	CString keyword;

	GetDlgItemText(IDC_EDIT1,keyword);
	KeyWord = CT2A(keyword.GetBuffer());


	if(type == -1)
	{
		CString message;
		message = "请选择查找类型";
		MessageBox(message,"提示");

	}
	else
	{			
		switch(type)
		{
				case 0:  KeyWordField = "StudentName" ;break;
				case 1: KeyWordField = "StudentID"; break;
				case 2: KeyWordField = "UserName";  break;

				default: CString message;
					message = "查找类型错误";
					MessageBox(message,"提示");break;
		}
			MySqlApi Api;
			std::string data[20][10];
			int n = Api.fuzzyQuery(UserName,Password,Database,Table,data,KeyWordField,KeyWord);
			if(n!= 0)
			{
				int row=0;
				for(int r = 0;data[r][0].compare("");r++)
				{
					std::string result[20][10];
					if(Api.selectTable(UserName,Password,Database,"loantable",result,"UserName",data[r][0]) != 0)
					{
						for(int ROW = 0;result[ROW][1].compare("");ROW++){
						std::string book[10];
						Api.selectRowExists(UserName,Password,Database,"booktable",book,"BookID",result[ROW][1]);
						m_list.InsertItem(row,"");
						m_list.SetItemText(row,0,book[0].c_str());
						for(int i =1;i<5;i++)
						{
							m_list.SetItemText(row,i,result[ROW][i-1].c_str());
						}
						row++;
					}
					}
				}
			}
			else
			{
				CString message;
				message = "未找到查询内容";
				MessageBox(message,"提示");
			}
	}
	// TODO: 在此添加控件通知处理程序代码
}

void CDIALOG_LOANINFO::OnBnClickedButton1()
{

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
	GetDlgItemText(IDC_EDIT2,keyword);
	KeyWord = CT2A(keyword.GetBuffer());
	if(type == -1)
	{
		CString message;
		message = "请选择查找类型";
		MessageBox(message,"提示");
	}
	else
	{			
		switch(type)
		{
			case 2:  KeyWordField = "BookName" ;break;
			case 0: KeyWordField = "BookISBN"; break;
			case 3: KeyWordField = "BookID";  break;
			case 1:  KeyWordField = "BookKind";break;
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
					std::string result[4];
					if(Api.selectRowExists(UserName,Password,Database,"loantable",result,"BookId",data[r][1]) != 0)
					{
						m_list.InsertItem(r,"");
						m_list.SetItemText(r,0,data[r][0].c_str());
						for(int i =1;i<5;i++)
						{
							m_list.SetItemText(r,i,result[i-1].c_str());
						}
					}				
				}
		}
		else
		{
			CString message;
			message = "未找到查询内容";
			MessageBox(message,"提示");
		}
	}
	// TODO: 在此添加控件通知处理程序代码
}

void CDIALOG_LOANINFO::OnBnClickedButton6()
{

	UpdateData(true);
	m_list.DeleteAllItems();//清空
	std::string Table = "loanTable";
	std::string UserName = "root";
	std::string Password = "";
	std::string Database = "library";
	std::string KeyWord ;
	std::string KeyWordField;
	std::string Type;
	int type = m_Combo3.GetCurSel();
	CString keyword;
	GetDlgItemText(IDC_EDIT3,keyword);
	KeyWord = CT2A(keyword.GetBuffer());
	if(type == -1)
	{
		CString message;
		message = "请选择查找类型";
		MessageBox(message,"提示");
	}
	else
	{			
		switch(type)
		{
				case 1: KeyWordField = "loanTime"; break;
				case 0:  KeyWordField = "returnTime";break;
				default: CString message;
				message = "查找类型错误";
				MessageBox(message,"提示");break;
		}
			MySqlApi Api;
			std::string data[20][10];
			int n = Api.fuzzyQuery(UserName,Password,Database,Table,data,KeyWordField,KeyWord);
			if(data[0][0].compare("") == 0)
			{
				CString message;
				message = CT2A(data[0][0].c_str());
				MessageBox(message);
			}
			else{
				int ROW = 0;
				for(int r = 0;data[r][0].compare("");r++){


						m_list.InsertItem(ROW,"");
						std::string book[7];
						Api.selectRowExists(UserName,Password,Database,"BookTable",book,"BookID",data[r][1]);
						m_list.SetItemText(ROW,0,book[0].c_str());	


					for(int i =1;i<5;i++){
																		
						m_list.SetItemText(ROW,i,data[r][i-1].c_str());
					}
					ROW++;

				}

			}
	}

	// TODO: 在此添加控件通知处理程序代码
}
