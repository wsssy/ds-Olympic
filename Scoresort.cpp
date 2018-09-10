// Scoresort.cpp : 实现文件
//

#include "stdafx.h"
#include "OlympicsScore.h"
#include "Scoresort.h"
#include "afxdialogex.h"
#include "OlympicsScoreDlg.h"
#include"ScorefindDlg.h"

// CScoresort 对话框

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


// CScoresort 消息处理程序


BOOL CScoresort::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_print_num = str_n.c_str();
	m_print_all = str_z.c_str();
	m_print_men = str_m.c_str();
	m_print_women = str_w.c_str();
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CScoresort::OnBnClickedFindButton()
{
	// TODO: 在此添加控件通知处理程序代码
	INT_PTR nRes;             // 用于保存DoModal函数的返回值   

	CScorefindDlg scorefindDlg;           // 构造对话框类CTipDlg的实例   
	nRes = scorefindDlg.DoModal();  // 弹出对话框   
	if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
		return;
}
