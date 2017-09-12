// DIALOG_SEARCH.cpp : 实现文件
//

#include "stdafx.h"
#include "DIALOG_SEARCH.h"
#include "BORROW.h"
#include "string.h"
#include <iostream>
#include "MySqlApi.h"

// CDIALOG_SEARCH 对话框

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


// CDIALOG_SEARCH 消息处理程序

void CDIALOG_SEARCH::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码



	CBORROW Dlg;
	Dlg.UserName = m_UserName;
	Dlg.DoModal();
}

void CDIALOG_SEARCH::OnBnClickedButton1()

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
					message = "查找类型错误";
					MessageBox(message);break;

		}
		/*if(keyword.IsEmpty()){
			CString message;
			message = "请输入查找关键字";
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
				message = "未找到查询内容";
				MessageBox(message);

			}

		



	}
}
