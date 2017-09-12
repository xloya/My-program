// AdmDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "New��½.h"
#include "AdmDlg.h"


// CAdmDlg �Ի���

IMPLEMENT_DYNAMIC(CAdmDlg, CDialog)

CAdmDlg::CAdmDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdmDlg::IDD, pParent)
{

}

CAdmDlg::~CAdmDlg()
{
}

void CAdmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tabctrl);
}


BEGIN_MESSAGE_MAP(CAdmDlg, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CAdmDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CAdmDlg ��Ϣ�������

void CAdmDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CRect r;
	m_tabctrl.GetClientRect (&r);
	switch(m_tabctrl.GetCurSel())//��ȡ��굥����ѡ�.
	{
	case 0:
		{
			m_mm1.ShowWindow(TRUE);//��ʾ��굥����ѡ���Ӧ����.
			m_mm2.ShowWindow(FALSE);
			m_mm3.ShowWindow(FALSE);
			m_mm4.ShowWindow(FALSE);
			break;
		}
	case 1:
		{
			m_mm1.ShowWindow(FALSE);
			m_mm2.ShowWindow(TRUE);
			m_mm3.ShowWindow(FALSE);
			m_mm4.ShowWindow(FALSE);
			break;
		}
	case 2:
		{
			m_mm1.ShowWindow(FALSE);
			m_mm2.ShowWindow(FALSE);
			m_mm3.ShowWindow(TRUE);
			m_mm4.ShowWindow(FALSE);
			break;
		}
	case 3:
		{
			m_mm1.ShowWindow(FALSE);
			m_mm2.ShowWindow(FALSE);
			m_mm3.ShowWindow(FALSE);
			m_mm4.ShowWindow(TRUE);
			break;
		}

	}
	*pResult = 0;
}

BOOL CAdmDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_tabctrl.InsertItem(0,"�鼮����");
	m_tabctrl.InsertItem(1,"���Ĺ���");
	m_tabctrl.InsertItem(2,"�û�����");
	m_tabctrl.InsertItem(3,"�����˻�");



              
	//-------����ҳ�洰��-----------------------
	m_mm1.Create(IDD_DIALOG_BOOKINFO,GetDlgItem(IDC_TAB1));
	m_mm2.Create(IDD_DIALOG_LOANINFO,GetDlgItem(IDC_TAB1));
	m_mm3.Create(IDD_DIALOG_USERINFO,GetDlgItem(IDC_TAB1));
	m_mm4.Create(IDD_DIALOG_ACCOUNTINFO,GetDlgItem(IDC_TAB1));

                   

	//--------�ø�����-------------------------
	m_mm1.SetParent(GetDlgItem(IDC_TAB1));
	m_mm2.SetParent(GetDlgItem(IDC_TAB1));
	m_mm3.SetParent(GetDlgItem(IDC_TAB1));
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
	m_mm3.MoveWindow(&r1);
	m_mm4.MoveWindow(&r1);
                      //---------Ĭ����ʾpage1                     	
	m_mm1.ShowWindow(TRUE);
	

//-----��ӱ���ֶ�------------------------
	m_mm2.m_list.InsertColumn(0,_T("ͼ������"),200);
	m_mm2.m_list.InsertColumn(1,_T("�����û���"),200);
	m_mm2.m_list.InsertColumn(2,_T("ͼ����"),200);
	m_mm2.m_list.InsertColumn(3,_T("����ʱ��"),200);
	m_mm2.m_list.InsertColumn(4,_T("����ʱ��"),200);			
	m_mm2.m_list.SetColumnWidth(0, 100);
	m_mm2.m_list.SetColumnWidth(1, 100);
	m_mm2.m_list.SetColumnWidth(2, 100);
	m_mm2.m_list.SetColumnWidth(3, 100);
	m_mm2.m_list.SetColumnWidth(4, 100);   

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

	m_mm3.m_list.InsertColumn(0,_T("�û���"),200);
	m_mm3.m_list.InsertColumn(1,_T("����"),200);
	m_mm3.m_list.InsertColumn(2,_T("����"),200);
	m_mm3.m_list.InsertColumn(3,_T("ѧ��"),200);	
	m_mm3.m_list.SetColumnWidth(0, 100);
	m_mm3.m_list.SetColumnWidth(1, 100);
	m_mm3.m_list.SetColumnWidth(2, 100);
	m_mm3.m_list.SetColumnWidth(3, 100);

	
//-----��ʼ��������Ϣ------------------------
	m_mm4.Name = Name;
	m_mm4.ID = ID;
	m_mm4.UserName = UserName;
	
	m_mm4.UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
