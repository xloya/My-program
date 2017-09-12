// DIALOG_ACCOUNTINFO1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DIALOG_ACCOUNTINFO1.h"
#include "MySqlApi.h"
#include <iostream>
#include "string.h"
#include "New��½Dlg.h"
// CDIALOG_ACCOUNTINFO1 �Ի���

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


// CDIALOG_ACCOUNTINFO1 ��Ϣ�������

void CDIALOG_ACCOUNTINFO1::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	std::string TempPwd = CT2A(m_EXPwd.GetBuffer());
	std::string NewPwd = CT2A(m_Pwd.GetBuffer());

	if(m_EXPwd.IsEmpty() == 1||  m_Pwd.IsEmpty() ==1)
	{
		MessageBox("��������Ϣ");
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
				MessageBox("�޸ĳɹ���");
				GetDlgItem(IDD_DIALOG_ACCOUNT_PWD1)->SetWindowText(_T(""));
				GetDlgItem(IDD_DIALOG_ACCOUNT_PWD2)->SetWindowText(_T(""));
			}
			else{

				MessageBox("ԭ�������");
			}	
			
			
		}
		else{
				MessageBox("��δ֪����");
			
		}

	
	}
}

void CDIALOG_ACCOUNTINFO1::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CNew��½Dlg Logout;
	GetParent()->GetParent()->SendMessage(WM_CLOSE);
	Logout.DoModal();
}
