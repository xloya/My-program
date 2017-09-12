// DIALOG_RETURN.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DIALOG_RETURN.h"
#include "RETURN.h"
#include "MySqlApi.h"
#include <WinSock.h>
#include "mysql.h"
#include <stdio.h>
#include <iostream>
#pragma comment(lib,"wsock32.lib")
#pragma comment(lib,"libmysql.lib")

// CDIALOG_RETURN �Ի���

IMPLEMENT_DYNAMIC(CDIALOG_RETURN, CDialog)

CDIALOG_RETURN::CDIALOG_RETURN(CWnd* pParent /*=NULL*/)
	: CDialog(CDIALOG_RETURN::IDD, pParent)
{

}

CDIALOG_RETURN::~CDIALOG_RETURN()
{
}

void CDIALOG_RETURN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO2, m_Combo1);
}


BEGIN_MESSAGE_MAP(CDIALOG_RETURN, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDIALOG_RETURN::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON7, &CDIALOG_RETURN::OnBnClickedButton7)
END_MESSAGE_MAP()


// CDIALOG_RETURN ��Ϣ�������

void CDIALOG_RETURN::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CRETURN Dlg;
	Dlg.UserName = UserName;
	Dlg.DoModal();
}

void CDIALOG_RETURN::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_list.DeleteAllItems();//���
	std::string Table = "loantable";
	std::string Username = "root";
	std::string Password = "";
	std::string Database = "library";
	std::string KeyWord ;
	std::string KeyWordField;
	std::string Type;
	int type = m_Combo1.GetCurSel();
	CString keyword;
	std::string username;
	GetDlgItemText(IDC_EDIT1,keyword);
	KeyWord = CT2A(keyword.GetBuffer());
	username = CT2A(UserName.GetBuffer());


	if(type == -1){
		CString message;
		message = "��ѡ���������";
		MessageBox(message);

	}
	else{			
		switch(type){
				case 0: KeyWordField = "returnTime"; break;
				case 1: KeyWordField = "loanTime";  break;
				case 2: KeyWordField = "bookID"; break;
				
				default:break;

				
		}
	


			MySqlApi Api;
			std::string data[20][10];
			int n = Api.fuzzyQuery(Username,Password,Database,Table,data,KeyWordField,KeyWord);
			if(n!= 0){
				int ROW = 0;
				
				for(int r = 0;data[r][0].compare("");r++){
				
					if(data[r][0].compare(username)==0){
						m_list.InsertItem(ROW,"");
						std::string book[7];
						Api.selectRowExists("root",Password,Database,"BookTable",book,"BookID",data[r][1]);
						m_list.SetItemText(ROW,0,book[0].c_str());	
						
						for(int i =1;i<4;i++){

							m_list.SetItemText(ROW,i,data[r][i].c_str());
							
					}
						ROW++;
					}
				}
				MessageBox("��ѯ�ɹ�");
			}
			else{
				CString message;
				message = "δ�ҵ���ѯ����";
				MessageBox(message);

			}

		



	}
}
