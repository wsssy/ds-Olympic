// ScorefindDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OlympicsScore.h"
#include "ScorefindDlg.h"
#include "afxdialogex.h"
#include "OlympicsScoreDlg.h"
#include<iostream>
#include<string>
using namespace std;

#define  LIST_INIT_SIZE   100//���Ա�洢�ռ�ĳ�ʼ������
#define  LISTINCREMENT    10//���Ա�洢�ռ�ķ�������
#define  Status           int
#define  OK               1    






void Search_con(country *c, int cnum, int item, string &str);//�����ұ�Ų���Ŀ����������str
int Search_item(country *c, int item, string &str);//����Ŀ��Ų������������str
// CScorefindDlg �Ի���

IMPLEMENT_DYNAMIC(CScorefindDlg, CDialogEx)

CScorefindDlg::CScorefindDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FIND_DIALOG, pParent)
	, m_country(0)
	, m_item_c(0)
	, m_print_c(_T(""))
	, m_item(0)
	, m_print_i(_T(""))
{

}

CScorefindDlg::~CScorefindDlg()
{
}

void CScorefindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDICOUNTRY_EDIT, m_country);
	DDX_Text(pDX, IDC_ITEM_C_EDIT, m_item_c);
	DDX_Text(pDX, IDC_PRINT_XM_EDIT, m_print_c);
	DDX_Text(pDX, IDC_ITEM_EDIT, m_item);
	DDX_Text(pDX, IDC_PRINT_Item_EDIT, m_print_i);
}


BEGIN_MESSAGE_MAP(CScorefindDlg, CDialogEx)
	ON_BN_CLICKED(IDC_FIND_C_BUTTON, &CScorefindDlg::OnBnClickedFindCButton)
	ON_BN_CLICKED(IDC_FIND_I_BUTTON, &CScorefindDlg::OnBnClickedFindIButton)
END_MESSAGE_MAP()


// CScorefindDlg ��Ϣ�������

void Search_con(country *c, int cnum, int item, string &str) {
	int rank;
	str = "������";
	if (item <= m) {
		str += to_string(c[cnum].mrank[item]) + "   �÷֣�";
		rank = c[cnum].mrank[item];
	}
	else {
		str += to_string(c[cnum].wrank[item]) + "   �÷֣�";
		rank = c[cnum].wrank[item];
	}
	if (item <= 2 || (item > m&&item <= m + 2)) {
		switch (rank)
		{
		case 1:
			str += to_string(7); break;
		case 2:
			str += to_string(5); break;
		case 3:
			str += to_string(3); break;
		case 4:
			str += to_string(2); break;
		case 5:
			str += to_string(1); break;
		default:
			str += to_string(0); break;
		}
	}
	else switch (rank)
	{
	case 1:
		str += '5'; break;
	case 2:
		str += '3'; break;
	case 3:
		str += '2'; break;
	default:
		str += '0'; break;
	}
}

int Search_item(country *c, int item, string &str) {
	int i;
	str = " ";
	for (i = 1; i <= n; i++) {
		if (item <= m) {
			if (c[i].mrank[item] == 1)str += to_string(i) + ",";
		}
		else if (c[i].wrank[item] == 1)str += to_string(i) + ",";
	}
	for (i = 1; i <= n; i++) {
		if (item <= m) {
			if (c[i].mrank[item] == 2)str += to_string(i) + ",";
		}
		else if (c[i].wrank[item] == 2)str += to_string(i) + ",";
	}
	for (i = 1; i <= n; i++) {
		if (item <= m) {
			if (c[i].mrank[item] == 3)str += to_string(i) ;
		}
		else if (c[i].wrank[item] == 3)str += to_string(i) ;
	}
	if ((item > 2 && item < m) || item > m + 2)return OK;
	for (i = 1; i <= n; i++) {
		if (item <= m) {
			if (c[i].mrank[item] == 4)str += ","+to_string(i) ;
		}
		else if (c[i].wrank[item] == 4)str += ","+ to_string(i) ;
	}
	for (i = 1; i <= n; i++) {
		if (item <= m) {
			if (c[i].mrank[item] == 5)str += ","+to_string(i);
		}
		else if (c[i].wrank[item] == 5)str += ","+to_string(i);
	}
	return OK;

}

void CScorefindDlg::OnBnClickedFindCButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	string str_c;
	Search_con(c, m_country,m_item_c, str_c);
	m_print_c = str_c.c_str();
	UpdateData(FALSE);

}


void CScorefindDlg::OnBnClickedFindIButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	string str_i;
	Search_item(c, m_item, str_i);
	m_print_i = str_i.c_str();
	UpdateData(FALSE);
}
