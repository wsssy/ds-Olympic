#pragma once


// CScoresort 对话框

class CScoresort : public CDialogEx
{
	DECLARE_DYNAMIC(CScoresort)

public:
	CScoresort(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CScoresort();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SOCRESORT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_print_num;
	CString m_print_all;
	CString m_print_men;
	CString m_print_women;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedFindButton();
};
