#pragma once


// CScorefindDlg 对话框

class CScorefindDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CScorefindDlg)

public:
	CScorefindDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CScorefindDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIND_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_country;
	int m_item_c;
	CString m_print_c;
	int m_item;
	CString m_print_i;
	afx_msg void OnBnClickedFindCButton();
	afx_msg void OnBnClickedFindIButton();
};
