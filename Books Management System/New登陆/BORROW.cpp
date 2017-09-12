// BORROW.cpp : 实现文件
//

#include "stdafx.h"
#include "BORROW.h"
#include <string>
#include "mysql.h"
#include <iostream>

// CBORROW 对话框

IMPLEMENT_DYNAMIC(CBORROW, CDialog)

CBORROW::CBORROW(CWnd* pParent /*=NULL*/)
	: CDialog(CBORROW::IDD, pParent)
	, m_BookID(_T(""))
{

}

CBORROW::~CBORROW()
{
}

void CBORROW::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, 1011, m_BookID);
}


BEGIN_MESSAGE_MAP(CBORROW, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CBORROW::OnBnClickedButton1)
END_MESSAGE_MAP()


// CBORROW 消息处理程序

void CBORROW::OnBnClickedButton1()
{
	UpdateData(true);
	std::string name =  CT2A(UserName.GetBuffer());
	std::string BookID = CT2A(m_BookID.GetBuffer());
	std::string Row[10];
	MYSQL mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root","", "library", 3306, NULL, 0);
	std::string sql = "select * from BookTable  where BookID =  \"" + BookID +"\"";
	//std::string sql = "select * from " +Table;
	mysql_query(&mysql, sql.c_str());
	result = mysql_store_result(&mysql);
	int fieldcount = mysql_num_fields(result);
	int rowcount = mysql_num_rows(result);
	row = mysql_fetch_row(result);
	
	if(rowcount==0){

		MessageBox("该书不存在");

	}
	

	else{
	for(int i=0; i<fieldcount; i++)
		{	
			
			Row[i] =  row[i] ;
		}
	if(Row[2].compare("out")==0){
			MessageBox("该书已借出");


	}
	else{	
		sql = "insert into loantable values(\"" +name+"\",\""+BookID +"\",\"" + "2017.7.26"+"\",\"" +"2018.4.26"+"\")" ;
		mysql_query(&mysql, sql.c_str());
		sql = "UPDATE BookTable set BookState = \"out\" where BookID = \"" + BookID + "\"";
		mysql_query(&mysql, sql.c_str());
		MessageBox("借书成功");
	}



	}



	// TODO: 在此添加控件通知处理程序代码
}
