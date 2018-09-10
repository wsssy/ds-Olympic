
// OlympicsScoreDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "OlympicsScore.h"
#include "OlympicsScoreDlg.h"
#include "afxdialogex.h"
#include"Scoresort.h"
#include"InstructionDlg.h"

//#include"windows.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include<iostream>
#include<string>
using namespace std;

#define  LIST_INIT_SIZE   100//线性表存储空间的初始分配量
#define  LISTINCREMENT    10//线性表存储空间的分配增量
#define  Status           int
#define  OK               1    


int m, w, n;//男子、女子项目数和总的国家数
string str_input,str_z,str_w,str_m,str_n;
SqList Lz, Lw, Lm;
country c[20];//记录各个国家的比赛成绩



Status InitList_SqList(SqList &L);//建立线性表
Status DeOrderInsert_Sq(SqList &L, ElemType e);//降序插入团体、男团、女团分数
int Print_sort(SqList &L, string &str);//将排序结果输出到str字符串
int Inputnum(country *c);//将输入的数据存储到country结构体里
void Inputscore(int cnum, country *c, int item, int rank);//不同的项目排名有加分
void CreateRank(country *c, SqList &Lz, SqList &Lm, SqList &Lw);//给成绩按照总分、男团、女团排序，分别存入Lz、Lm、Lw中
Status Delete_Sq(SqList &L);//删除节点L
void Print_num(country *c, string &str);//按国家编号输出成绩
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COlympicsScoreDlg 对话框



COlympicsScoreDlg::COlympicsScoreDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_OLYMPICSSCORE_DIALOG, pParent)
	, m_country(0)
	, m_man(0)
	, m_women(0)
	, m_inputscore(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COlympicsScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_COUNTRY_EDIT, m_country);
	DDX_Text(pDX, IDC_MEN_EDIT, m_man);
	DDX_Text(pDX, IDCWOMEN_EDIT, m_women);
	DDX_Text(pDX, IDC_EDIT6, m_inputscore);
	n = m_country;
	w = m_women;
	m = m_man;
	str_input = (CW2A(m_inputscore.GetString()));
}

BEGIN_MESSAGE_MAP(COlympicsScoreDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INPUT_BUTTON, &COlympicsScoreDlg::OnBnClickedInputButton)
	ON_STN_CLICKED(IDC_INSTR_zong_STATIC, &COlympicsScoreDlg::OnStnClickedInstrzongStatic)
	ON_BN_CLICKED(IDC_INS_GUIZE_BUTTON, &COlympicsScoreDlg::OnBnClickedInsGuizeButton)
	ON_BN_CLICKED(IDC_RESET_BUTTON, &COlympicsScoreDlg::OnBnClickedResetButton)
END_MESSAGE_MAP()


// COlympicsScoreDlg 消息处理程序

BOOL COlympicsScoreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void COlympicsScoreDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void COlympicsScoreDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR COlympicsScoreDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


Status InitList_SqList(SqList &L)
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}
Status Delete_Sq(SqList &L) {
	free(L.elem);
	L.length = 0;
	L.listsize = 0;
	return OK;
 }
Status DeOrderInsert_Sq(SqList &L, ElemType e)
{//将成绩降序插入线性表中
	int i, j;
	ElemType *newbase;
	if (L.length >= L.listsize) // 当前存储空间已满,增加分配
	{
		if (!(newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType))))
			exit(-1); // 存储分配失败
		L.elem = newbase; // 新基址
		L.listsize += LISTINCREMENT; // 增加存储容量
	}
	if (L.length == 0)L.elem[0] = e;
	else {
		i = L.length - 1;
		while (i >= 0 && L.elem[i].score < e.score) i--;
		for (j = L.length - 1; j > i; j--)
			L.elem[j + 1] = L.elem[j];
		L.elem[i + 1] = e;
	}
	L.length++;
	return OK;
}
int Print_sort(SqList &L, string &str) {
	int i, j;
	str = "排名   国家编号   分数\r\n";
	for (i = 0; i < n; i++) {
		j = i + 1;
		str += " " + to_string(j);
		str += "            " + to_string(L.elem[i].cnum);
		str += "          " + to_string(L.elem[i].score);
		str += "  \r\n";
	}
	return OK;
}
int Inputnum(country *c) {
	
	int node[100];
	int i, str_n, item, rank;
	item = 1; rank = 1;
	
	str_n = str_input.length();///不加最后的空字符串
	const char *shu = new char[str_n + 1];
	shu = str_input.c_str();

	for (i = 1; i <= n; i++) {
		c[i].cnum = i; c[i].mscore = 0; c[i].wscore = 0;
	}

	int m = 0;
	for (i = 0; i <= str_n; i++) {
		if (shu[i] >= '0' && shu[i] <= '9') {
			if (i == 0)node[m] = shu[i] - '0';
			else if (shu[i - 1] >= '0' && shu[i - 1] <= '9') {
				node[m] = node[m] * 10 + (shu[i] - '0');
			}
			else node[m] = shu[i] - '0';
		}
		else {
			if (shu[i - 1] >= '0' && shu[i - 1] <= '9') {
				Inputscore(node[m], c, item, rank);
				m++; rank++;
				if (shu[i] == ';') {
					item++; rank = 1;
				}
			}
			else m = m;
		}
	}
	return OK;
}
void Inputscore(int cnum, country *c, int item, int rank) {

	if (item <= m)//男子项目
	{
		c[cnum].mrank[item] = rank;
		if (item <= 2) {
			switch (rank)
			{
			case 1:
				c[cnum].mscore += 7; break;
			case 2:
				c[cnum].mscore += 5; break;
			case 3:
				c[cnum].mscore += 3; break;
			case 4:
				c[cnum].mscore += 2; break;
			case 5:
				c[cnum].mscore += 1; break;
			default:
				break;
			}
		}
		else switch (rank)
		{
		case 1:
			c[cnum].mscore += 5; break;
		case 2:
			c[cnum].mscore += 3; break;
		case 3:
			c[cnum].mscore += 2; break;
		default:
			break;
		}
	}
	else //女子项目
	{
		c[cnum].wrank[item] = rank;
		if (item <= m + 2) {
			switch (rank)
			{
			case 1:
				c[cnum].wscore += 7; break;
			case 2:
				c[cnum].wscore += 5; break;
			case 3:
				c[cnum].wscore += 3; break;
			case 4:
				c[cnum].wscore += 2; break;
			case 5:
				c[cnum].wscore += 1; break;
			default:
				break;
			}
		}
		else switch (rank)
		{
		case 1:
			c[cnum].wscore += 5; break;
		case 2:
			c[cnum].wscore += 3; break;
		case 3:
			c[cnum].wscore += 2; break;
		default:
			break;
		}
	}
}
void CreateRank(country *c, SqList &Lz, SqList &Lm, SqList &Lw) {

	ElemType ez, ew, em;
	InitList_SqList(Lz);
	InitList_SqList(Lm);
	InitList_SqList(Lw);
	for (int i = 1; i <= n; i++) {
		ez.cnum = i;
		ez.score = c[i].mscore + c[i].wscore;
		em.cnum = i;
		em.score = c[i].mscore;
		ew.cnum = i;
		ew.score = c[i].wscore;
		DeOrderInsert_Sq(Lz, ez);
		DeOrderInsert_Sq(Lm, em);
		DeOrderInsert_Sq(Lw, ew);
	}
}
void Print_num(country *c, string &str) {
	int i, j;
	str = "国家编号    分数\r\n";
	for (i = 0; i < n; i++) {
		j = i + 1;
		str += "       " + to_string(j);
		str += "         " + to_string(c[j].mscore + c[j].wscore);
		str += "  \r\n";
	}
}

void COlympicsScoreDlg::OnBnClickedInputButton()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	Inputnum(c);
	CreateRank(c, Lz, Lm, Lw);
	Print_sort(Lz, str_z);
	Print_sort(Lm, str_m);
	Print_sort(Lw, str_w);
	Print_num(c, str_n);
	INT_PTR nRes;             // 用于保存DoModal函数的返回值   

	CScoresort sortsocre;           // 构造对话框类CTipDlg的实例   
	nRes = sortsocre.DoModal();  // 弹出对话框   
	if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
		return;
	Delete_Sq(Lz);
	Delete_Sq(Lm);
	Delete_Sq(Lw);
	//UpdateData(FALSE);
}


void COlympicsScoreDlg::OnStnClickedInstrzongStatic()
{
	// TODO: 在此添加控件通知处理程序代码

}


void COlympicsScoreDlg::OnBnClickedInsGuizeButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CInstructionDlg instructionDlg;
	INT_PTR nRes;
	nRes = instructionDlg.DoModal();  // 弹出对话框   
	if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
		return;
}


void COlympicsScoreDlg::OnBnClickedResetButton()
{
	// TODO: 在此添加控件通知处理程序代码
	m_country = 0;
	m_man = 0; m_women = 0;
	m_inputscore = '\0';
	UpdateData(FALSE);
}
