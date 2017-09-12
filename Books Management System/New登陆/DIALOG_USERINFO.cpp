// DIALOG_USERINFO.cpp : ʵ���ļ�
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



// CDIALOG_USERINFO �Ի���

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


// CDIALOG_USERINFO ��Ϣ�������

void CDIALOG_USERINFO::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_list.DeleteAllItems();//���
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
		message = "��ѡ���������";
		MessageBox(message,"��ʾ");

	}
	else{			
		switch(type){
				case 0: KeyWordField = "StudentName" ;break;
				case 1: KeyWordField = "StudentID"; break;
				case 2: KeyWordField = "UserName";  break;


				default: CString message;
					message = "�������ʹ���";
					MessageBox(message,"��ʾ");break;
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
				message = "δ�ҵ���ѯ����";
				MessageBox(message,"��ʾ");

			}

		}



	

}

void CDIALOG_USERINFO::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MYSQL mysql; //Mysql����  
	if(mysql_init(&mysql)) 
	{ 
	if(mysql_real_connect(&mysql, "localhost","root" , "", "library", 3306, NULL, 0))  
	{ 
		CString   sTemp;
		sTemp= "���ӳɹ�!";
		MessageBox(sTemp,"��ʾ");  
	 } 
	 else 
	{ 
	mysql_close(&mysql); 
		CString   sTemp;
		sTemp= "����ʧ��!";
		MessageBox(sTemp,"��ʾ");  
	 } 
	} 
	else 
	{ 
			CString   sTemp;
		sTemp= "��ʼ��ʧ��!";
		MessageBox(sTemp,"��ʾ");  
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
		sTemp= "��ӳɹ�!";
		MessageBox(sTemp,"��ʾ");
		GetDlgItem(IDD_DIALOG_USER_NAME)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_USER_USER)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_USER_ID)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_USER_PWD)->SetWindowText(_T(""));
 } 
 else 
 { 
		CString   sTemp;
		sTemp= "���ʧ��!";
		MessageBox(sTemp,"��ʾ");  
 }
}

void CDIALOG_USERINFO::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MYSQL mysql; //Mysql����  
	if(mysql_init(&mysql)) 
	{ 
	if(mysql_real_connect(&mysql, "localhost","root" , "", "library", 3306, NULL, 0))  
	{ 
		CString   sTemp;
		sTemp= "���ӳɹ�!";
		MessageBox(sTemp,"��ʾ");  
	 } 
	 else 
	{ 
	mysql_close(&mysql); 
		CString   sTemp;
		sTemp= "����ʧ��!";
		MessageBox(sTemp,"��ʾ");  
	 } 
	} 
	else 
	{ 
			CString   sTemp;
		sTemp= "��ʼ��ʧ��!";
		MessageBox(sTemp,"��ʾ");  
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
			message = "����������";
			MessageBox(message,"��ʾ");}
	else if(studentid.IsEmpty())
		{
			CString message;
			message = "������ѧ��";
			MessageBox(message,"��ʾ");}
	else if(username.IsEmpty())
		{
			CString message;
			message = "�������û���";
			MessageBox(message,"��ʾ");}
	else if(password.IsEmpty())
		{
			CString message;
			message = "����������";
			MessageBox(message,"��ʾ");}
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
		sTemp= "�޸ĳɹ�!";
		MessageBox(sTemp,"��ʾ");
		GetDlgItem(IDD_DIALOG_USER_NAME)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_USER_USER)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_USER_ID)->SetWindowText(_T(""));
		GetDlgItem(IDD_DIALOG_USER_PWD)->SetWindowText(_T(""));
 } 
 else 
 { 
		
	 	CString   sTemp;
		sTemp= "�޸�ʧ��!";
		MessageBox(sTemp,"��ʾ");  
 }
	}
}

void CDIALOG_USERINFO::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MYSQL mysql; //Mysql����  
	if(mysql_init(&mysql)) 
	{ 
	if(mysql_real_connect(&mysql, "localhost","root" , "", "library", 3306, NULL, 0))  
	{ 
		CString   sTemp;
		sTemp= "���ӳɹ�!";
		MessageBox(sTemp,"��ʾ");  
	 } 
	 else 
	{ 
		mysql_close(&mysql); 
		CString   sTemp;
		sTemp= "����ʧ��!";
		MessageBox(sTemp,"��ʾ");  
	 } 
	} 
	else 
	{ 
		CString   sTemp;
		sTemp= "��ʼ��ʧ��!";
		MessageBox(sTemp,"��ʾ");  
	}
	CString username;

	GetDlgItemText(IDD_DIALOG_USER_USER,username);
	char *buf = new char[200]; 
	sprintf(buf,"DELETE FROM studenttable WHERE UserName='%s'", username); 
  
	if(!mysql_query(&mysql, buf)) 
	{ 
		CString   sTemp;
		sTemp= "ɾ���ɹ�!";
		MessageBox(sTemp,"��ʾ");  
	
	} 
	else 
	{ 
		CString   sTemp;
		sTemp= "ɾ��ʧ��!";
		MessageBox(sTemp,"��ʾ");  
	}
}

BOOL CDIALOG_USERINFO::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_Mytip.Create(this);  
	m_Mytip.AddTool(GetDlgItem(IDC_BUTTON3), "�޸Ĳ����޸��û���" ); //IDC_BUTTONΪ��Ҫ�����ʾ��Ϣ�İ�ť��ID
	m_Mytip.AddTool(GetDlgItem(IDC_BUTTON4), "ɾ���������û�����" );
	m_Mytip.SetDelayTime(200); //�����ӳ�
	m_Mytip.SetTipTextColor( RGB(255,0,0) ); //������ʾ�ı�����ɫ
	m_Mytip.SetTipBkColor( RGB(255,255,255)); //������ʾ��ı�����ɫ
	m_Mytip.Activate(TRUE); //�����Ƿ�������ʾ
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

BOOL CDIALOG_USERINFO::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_MOUSEMOVE)
	m_Mytip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}
