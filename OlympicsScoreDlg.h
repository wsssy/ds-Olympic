
// OlympicsScoreDlg.h : ͷ�ļ�
//
#include <string>
#include<iostream>
using namespace std;
#pragma once
extern int m, w, n;//���ӡ�Ů����Ŀ�����ܵĹ�����

typedef struct ElemType // ��¼����
{
	int score; // �÷����
	int cnum; //���ұ��
};
typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;//��¼�ܷ֣����š�Ů�ŵ÷�
typedef  struct
{
	int cnum;//ѧУ�ı��
	int mrank[20];//ѧУ�ڸ���������Ŀ������
	int wrank[20];//ѧУ�ڸ���Ů����Ŀ������
	int mscore;
	int wscore;
}country;//ѧУ��¼����

extern string str_input, str_z, str_w, str_m, str_n;
extern SqList Lz, Lw, Lm;
extern country c[20];

// COlympicsScoreDlg �Ի���
class COlympicsScoreDlg : public CDialogEx
{
// ����
public:
	COlympicsScoreDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OLYMPICSSCORE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_country;
	int m_man;
	int m_women;
	CString m_inputscore;
	afx_msg void OnBnClickedInputButton();
	afx_msg void OnStnClickedInstrzongStatic();
	afx_msg void OnBnClickedInsGuizeButton();
	afx_msg void OnBnClickedResetButton();
};
