#pragma once


// CScoresort �Ի���

class CScoresort : public CDialogEx
{
	DECLARE_DYNAMIC(CScoresort)

public:
	CScoresort(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CScoresort();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SOCRESORT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_print_num;
	CString m_print_all;
	CString m_print_men;
	CString m_print_women;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedFindButton();
};
