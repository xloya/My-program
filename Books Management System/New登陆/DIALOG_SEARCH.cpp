// DIALOG_SEARCH.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DIALOG_SEARCH.h"
#include "BORROW.h"
#include "string.h"
#include <iostream>
#include "MySqlApi.h"

// CDIALOG_SEARCH �Ի���

IMPLEMENT_DYNAMIC(CDIALOG_SEARCH, CDialog)

CDIALOG_SEARCH::CDIALOG_SEARCH(CWnd* pParent /*=NULL*/)
	: CDialog(CDIALOG_SEARCH::IDD, pParent)
{

}

CDIALOG_SEARCH::~CDIALOG_SEARCH()
{
}

void CDIALOG_SEARCH::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
}


BEGIN_MESSAGE_MAP(CDIALOG_SEARCH, CDialog)
	ON_BN_CLICKED(IDC_BUTTON4, &CDIALOG_SEARCH::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &CDIALOG_SEARCH::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDIALOG_SEARCH ��Ϣ�������

void CDIALOG_SEARCH::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������



	CBORROW Dlg;
	Dlg.UserName = m_UserName;
	Dlg.DoModal();
}

void CDIALOG_SEARCH::OnBnClickedButton1()

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
		MessageBox(message);

	}
	else{			
		switch(type){
				case 2: KeyWordField = "BookName" ;break;
				case 0: KeyWordField = "BookISBN"; break;
				case 3: KeyWordField = "BookID";  break;
				case 1: KeyWordField = "BookKind";break;
				case 5: KeyWordField = "BookLocation" ;break;
				case 4: KeyWordField = "BookState";break;
				case 6: KeyWordField = "BookAuthor";break;
				default: CString message;
					message = "�������ʹ���";
					MessageBox(message);break;

		}
		/*if(keyword.IsEmpty()){
			CString message;
			message = "��������ҹؼ���";
			MessageBox(message);


		}else{*/
			MySqlApi Api;
			std::string data[20][10];
			int n = Api.fuzzyQuery(UserName,Password,Database,Table,data,KeyWordField,KeyWord);




			if(n!= 0){

				int ROW=0;
				for(int r = 0;data[r][0].compare("");r++){
					std::string result[20][10];
					
					
					if(Api.selectTable(UserName,Password,Database,"booktable",result,"BookID",data[r][1]) != 0){
						m_list.InsertItem(ROW,"");
						for(int i =0;i<7;i++){

							m_list.SetItemText(ROW,i,result[0][i].c_str());
								
								
								
						}
						ROW++;
					}
					else{
						break;
						
					}


				}



			}
			else{
				CString message;
				message = "δ�ҵ���ѯ����";
				MessageBox(message);

			}

		



	}
}
