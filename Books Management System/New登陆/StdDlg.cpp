// StdDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "New��½.h"
#include "StdDlg.h"


// CStdDlg �Ի���

IMPLEMENT_DYNAMIC(CStdDlg, CDialog)

CStdDlg::CStdDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStdDlg::IDD, pParent)
{

}

CStdDlg::~CStdDlg()
{
}

void CStdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}


BEGIN_MESSAGE_MAP(CStdDlg, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CStdDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CStdDlg ��Ϣ�������

BOOL CStdDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//----------����TAB�ı���-----------
	m_tab.InsertItem(0,"�鼮��ѯ");
	m_tab.InsertItem(1,"���Ĳ�ѯ");
	m_tab.InsertItem(2,"�����˻�");
          
 

	//-------����ҳ�洰��-----------------------
	m_mm1.Create(IDD_DIALOG_SEARCH,GetDlgItem(IDC_TAB1));
	m_mm2.Create(IDD_DIALOG_RETURN,GetDlgItem(IDC_TAB1));
	m_mm4.Create(IDD_DIALOG_ACCOUNTINFO1,GetDlgItem(IDC_TAB1));



	//--------�ø�����-------------------------
	m_mm1.SetParent(GetDlgItem(IDC_TAB1));
	m_mm2.SetParent(GetDlgItem(IDC_TAB1));
	m_mm4.SetParent(GetDlgItem(IDC_TAB1));



	//-----���崰�ڴ�С------------------
	RECT r1;
	r1.left=1;
	r1.top=22;
	r1.bottom=800;
	r1.right=1000;

	//-----���ô���λ��------------------------
	m_mm1.MoveWindow(&r1);
	m_mm2.MoveWindow(&r1);
	m_mm4.MoveWindow(&r1);
                      //---------Ĭ����ʾpage1                     	
	m_mm1.ShowWindow(TRUE);



	//-----��ʼ��������Ϣ------------------------
	m_mm4.Name = Name;
	m_mm4.ID = ID;
	m_mm4.UserName = UserName;
	m_mm4.UpdateData(false);
	m_mm1.m_UserName = UserName;
	m_mm2.UserName = UserName;

//-----��ӱ���ֶ�------------------------

	m_mm1.m_list.InsertColumn(0,_T("�鼮����"),200);
	m_mm1.m_list.InsertColumn(1,_T("ͼ����"),200);
	m_mm1.m_list.InsertColumn(2,_T("�鼮״̬"),200);
	m_mm1.m_list.InsertColumn(3,_T("ͼ��λ��"),200);	
	m_mm1.m_list.InsertColumn(4,_T("ISBN"),200);
	m_mm1.m_list.InsertColumn(5,_T("����"),200);
	m_mm1.m_list.InsertColumn(6,_T("����"),200);
	m_mm1.m_list.SetColumnWidth(0, 100);
	m_mm1.m_list.SetColumnWidth(1, 100);
	m_mm1.m_list.SetColumnWidth(2, 100);
	m_mm1.m_list.SetColumnWidth(3, 100);
	m_mm1.m_list.SetColumnWidth(4, 100);
	m_mm1.m_list.SetColumnWidth(5, 100);
	m_mm1.m_list.SetColumnWidth(6, 100);

	m_mm2.m_list.InsertColumn(0,_T("�鼮����"),200);
	m_mm2.m_list.InsertColumn(1,_T("ͼ����"),200);
	m_mm2.m_list.InsertColumn(2,_T("����ʱ��"),200);
	m_mm2.m_list.InsertColumn(3,_T("����ʱ��"),200);		
	m_mm2.m_list.SetColumnWidth(0, 100);
	m_mm2.m_list.SetColumnWidth(1, 100);
	m_mm2.m_list.SetColumnWidth(2, 100);
	m_mm2.m_list.SetColumnWidth(3, 100);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CStdDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CRect r;
	m_tab.GetClientRect (&r);
	switch(m_tab.GetCurSel())//��ȡ��굥����ѡ�.
	{
	case 0:
		{
			m_mm1.ShowWindow(TRUE);//��ʾ��굥����ѡ���Ӧ����.
			m_mm2.ShowWindow(FALSE);
			m_mm4.ShowWindow(FALSE);
			break;
		}
	case 1:
		{
			m_mm1.ShowWindow(FALSE);
			m_mm2.ShowWindow(TRUE);
			m_mm4.ShowWindow(FALSE);
			break;
		}
	case 2:
		{
			m_mm1.ShowWindow(FALSE);
			m_mm2.ShowWindow(FALSE);
			m_mm4.ShowWindow(TRUE);
			break;
		}

	}
	*pResult = 0;
}
