// Scoresort.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OlympicsScore.h"
#include "Scoresort.h"
#include "afxdialogex.h"
#include "OlympicsScoreDlg.h"
#include"ScorefindDlg.h"

// CScoresort �Ի���

IMPLEMENT_DYNAMIC(CScoresort, CDialogEx)

CScoresort::CScoresort(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SOCRESORT_DIALOG, pParent)
	, m_print_num(_T(""))
	, m_print_all(_T(""))
	, m_print_men(_T(""))
	, m_print_women(_T(""))
{

}

CScoresort::~CScoresort()
{
}

void CScoresort::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SORTNUM_EDIT, m_print_num);
	DDX_Text(pDX, IDC_SORTALL_EDIT, m_print_all);
	DDX_Text(pDX, IDC_SORTMEN_EDIT, m_print_men);
	DDX_Text(pDX, IDC_SORTWOMEN_EDIT, m_print_women);
}


BEGIN_MESSAGE_MAP(CScoresort, CDialogEx)
	ON_BN_CLICKED(IDC_FIND_BUTTON, &CScoresort::OnBnClickedFindButton)
END_MESSAGE_MAP()


// CScoresort ��Ϣ�������


BOOL CScoresort::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_print_num = str_n.c_str();
	m_print_all = str_z.c_str();
	m_print_men = str_m.c_str();
	m_print_women = str_w.c_str();
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CScoresort::OnBnClickedFindButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	INT_PTR nRes;             // ���ڱ���DoModal�����ķ���ֵ   

	CScorefindDlg scorefindDlg;           // ����Ի�����CTipDlg��ʵ��   
	nRes = scorefindDlg.DoModal();  // �����Ի���   
	if (IDCANCEL == nRes)     // �ж϶Ի����˳��󷵻�ֵ�Ƿ�ΪIDCANCEL���������return�������������ִ��   
		return;
}
