// RETURN.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RETURN.h"
#include "MySqlApi.h"
#include <WinSock.h>
#include "mysql.h"
#include <stdio.h>
#include <iostream>

#pragma comment(lib,"wsock32.lib")
#pragma comment(lib,"libmysql.lib")


// CRETURN �Ի���

IMPLEMENT_DYNAMIC(CRETURN, CDialog)

CRETURN::CRETURN(CWnd* pParent /*=NULL*/)
	: CDialog(CRETURN::IDD, pParent)
{

}

CRETURN::~CRETURN()
{
}

void CRETURN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRETURN, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CRETURN::OnBnClickedButton1)
END_MESSAGE_MAP()


// CRETURN ��Ϣ�������

void CRETURN::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MYSQL mysql; //Mysql����  
	if(mysql_init(&mysql)) 
	{ 
	if(mysql_real_connect(&mysql, "localhost","root" , "", "library", 3306, NULL, 0))  
	{ 
		CString   sTemp;
		sTemp= "���ӳɹ�!";
		AfxMessageBox(sTemp);  
	 } 
	 else 
	{ 
	mysql_close(&mysql); 
		CString   sTemp;
		sTemp= "����ʧ��!";
		AfxMessageBox(sTemp);  
	 } 
	} 
	else 
	{ 
			CString   sTemp;
		sTemp= "��ʼ��ʧ��!";
		AfxMessageBox(sTemp);  
	}
	CString bookid;

	GetDlgItemText(IDC_EDIT1,bookid);
	
	char *buf = new char[200]; 
	


	
	
	//CString bookstate = _T("in");
	//std::string  CT2CA(bookstate.GetBuffer(0));

	std::string information[4];
	MySqlApi Api;
	std::string k_bookid = CT2A(bookid.GetBuffer());
	Api.selectRowExists("root","","library","loantable",information,"Bookid",k_bookid);
	if(information[0].compare(CT2A(UserName.GetBuffer())) == 0){
	sprintf(buf,"DELETE FROM loantable WHERE BookID='%s'", bookid); 
  	
	if(!mysql_query(&mysql, buf)) 
	{ 
		
	} 
	else 
	{ 
		
	}
	char *def = new char[200]; 
	sprintf(def,"UPDATE booktable SET BookState  = \"in\" WHERE BookID='%s'",bookid ); 
  
	 if(!mysql_query(&mysql, def)) 
	{ 
		CString   sTemp;
		sTemp= "����ɹ�!";
		AfxMessageBox(sTemp);  
	 } 
	else 
	{ 
		CString   sTemp;
		sTemp= "����ʧ��!";
		AfxMessageBox(sTemp);   
	 }
	
	}
	else{
		MessageBox("�㲢û�н��Ȿ��");
	}

	
}
