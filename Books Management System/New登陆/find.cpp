// find.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "New��½.h"
#include "find.h"
#include "windows.h"
#include <string.h>
#include "MySqlApi.h"
#include<iostream>
// Cfind �Ի���

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


// Cfind ��Ϣ�������

void Cfind::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		message = "�������û���";
		MessageBox(message);
	}
	else
	{
		key_UserName = CT2A(m_Username.GetBuffer());
	}
	if(m_StdName.IsEmpty())
	{
		CString message;
		message = "����������";
		MessageBox(message);
	}
	else
	{
		key_Name = CT2A(m_StdName.GetBuffer());
	}
	if(m_StdID.IsEmpty())
	{
		CString message;
		message = "������ѧ��/ID";
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
			MessageBox("�û�������");
		}
		else 
		{
			if(MySql.selectRowExists(UserName,password,database,"StudentTable",rowf,"UserName",key_UserName)==1)
			{
				if((rowf[2].compare(key_Name.c_str()) == 0)&&(rowf[3].compare(key_ID.c_str())==0))
				{
					CString t = "��Ϣ��ȷ�����������" ;
					MessageBox(t + rowf[1].c_str());
				}
				else MessageBox("��Ϣ�������������룡");
			}
			if(MySql.selectRowExists(UserName,password,database,"AdminTable",rowf,"UserName",key_UserName)==1)
			{
				if((rowf[2].compare(key_Name.c_str()) == 0)&&(rowf[3].compare(key_ID.c_str())==0))
				{
					CString t = "��Ϣ��ȷ�����������" ;
					MessageBox(t + rowf[1].c_str());
				}
				else MessageBox("��Ϣ�������������룡");
			}
	}
}