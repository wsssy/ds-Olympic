#pragma once


// CInstructionDlg 对话框

class CInstructionDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInstructionDlg)

public:
	CInstructionDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInstructionDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INS_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
