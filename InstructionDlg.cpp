// InstructionDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "OlympicsScore.h"
#include "InstructionDlg.h"
#include "afxdialogex.h"


// CInstructionDlg 对话框

IMPLEMENT_DYNAMIC(CInstructionDlg, CDialogEx)

CInstructionDlg::CInstructionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INS_DIALOG, pParent)
{

}

CInstructionDlg::~CInstructionDlg()
{
}

void CInstructionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInstructionDlg, CDialogEx)
END_MESSAGE_MAP()


// CInstructionDlg 消息处理程序
