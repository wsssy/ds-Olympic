#pragma once


// CInstructionDlg �Ի���

class CInstructionDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInstructionDlg)

public:
	CInstructionDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInstructionDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INS_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
