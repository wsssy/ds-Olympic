
// OlympicsScoreDlg.h : 头文件
//
#include <string>
#include<iostream>
using namespace std;
#pragma once
extern int m, w, n;//男子、女子项目数和总的国家数

typedef struct ElemType // 记录类型
{
	int score; // 得分情况
	int cnum; //国家编号
};
typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;//记录总分，男团、女团得分
typedef  struct
{
	int cnum;//学校的编号
	int mrank[20];//学校在各个男生项目的排名
	int wrank[20];//学校在各个女生项目的排名
	int mscore;
	int wscore;
}country;//学校记录类型

extern string str_input, str_z, str_w, str_m, str_n;
extern SqList Lz, Lw, Lm;
extern country c[20];

// COlympicsScoreDlg 对话框
class COlympicsScoreDlg : public CDialogEx
{
// 构造
public:
	COlympicsScoreDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OLYMPICSSCORE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
