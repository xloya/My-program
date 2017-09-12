// DIALOG_BOOKINFO.cpp : ʵ���ļ�
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



// CDIALOG_BOOKINFO �Ի���

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


// CDIALOG_BOOKINFO ��Ϣ�������

void CDIALOG_BOOKINFO::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_list.DeleteAllItems();//���
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
		message = "��ѡ���������";
		MessageBox(message,"��ʾ");

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
					message = "�������ʹ���";
					MessageBox(message,"��ʾ");break;

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
			message = "δ�ҵ���ѯ����";
			MessageBox(message,"����");
	}
	}
}

void CDIALOG_BOOKINFO::OnBnClickedButton5()
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
		sTemp= "����ɹ�!";
		MessageBox(sTemp,"��ʾ");
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
		sTemp= "����ʧ��!";
		MessageBox(sTemp,"��ʾ");  
 }
}

void CDIALOG_BOOKINFO::OnBnClickedButton3()
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
			message = "�������鼮����";
			MessageBox(message,"��ʾ");}
	else if(bookisbn.IsEmpty())
		{
			CString message;
			message = "������ISBN";
			MessageBox(message,"��ʾ");}
	else if(bookkind.IsEmpty())
		{
			CString message;
			message = "�������鼮����";
			MessageBox(message,"��ʾ");}
	else if(bookauthor.IsEmpty())
		{
			CString message;
			message = "�������鼮����";
			MessageBox(message,"��ʾ");}
	else if(booklocation.IsEmpty())
		{
			CString message;
			message = "�������鼮λ��";
			MessageBox(message,"��ʾ");}
	else if(bookid.IsEmpty())
		{
			CString message;
			message = "�������鼮Ψһ���";
			MessageBox(message,"��ʾ");}
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
		sTemp= "�޸ĳɹ�!";
		MessageBox(sTemp,"��ʾ");
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
		sTemp= "�޸�ʧ��!";
		MessageBox(sTemp,"��ʾ");  
 }
	}
}

void CDIALOG_BOOKINFO::OnBnClickedButton4()
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
	CString bookid;

	GetDlgItemText(IDD_DIALOG_BOOK_NUMBER,bookid);
	char *buf = new char[200]; 
	sprintf(buf,"DELETE FROM booktable WHERE BookID='%s'", bookid); 
  
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

BOOL CDIALOG_BOOKINFO::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_Mytip.Create(this);  
	m_Mytip.AddTool(GetDlgItem(IDC_BUTTON3), "�޸Ĳ����޸�Ψһ��ţ�" ); //IDC_BUTTONΪ��Ҫ�����ʾ��Ϣ�İ�ť��ID
	m_Mytip.AddTool(GetDlgItem(IDC_BUTTON4), "ɾ��������Ψһ��ţ�" );
	m_Mytip.SetDelayTime(200); //�����ӳ�
	m_Mytip.SetTipTextColor( RGB(255,0,0) ); //������ʾ�ı�����ɫ
	m_Mytip.SetTipBkColor( RGB(255,255,255)); //������ʾ��ı�����ɫ
	m_Mytip.Activate(TRUE); //�����Ƿ�������ʾ
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

BOOL CDIALOG_BOOKINFO::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_MOUSEMOVE)
	m_Mytip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}
