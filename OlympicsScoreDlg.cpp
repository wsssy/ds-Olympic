
// OlympicsScoreDlg.cpp : ʵ���ļ�
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

#define  LIST_INIT_SIZE   100//���Ա�洢�ռ�ĳ�ʼ������
#define  LISTINCREMENT    10//���Ա�洢�ռ�ķ�������
#define  Status           int
#define  OK               1    


int m, w, n;//���ӡ�Ů����Ŀ�����ܵĹ�����
string str_input,str_z,str_w,str_m,str_n;
SqList Lz, Lw, Lm;
country c[20];//��¼�������ҵı����ɼ�



Status InitList_SqList(SqList &L);//�������Ա�
Status DeOrderInsert_Sq(SqList &L, ElemType e);//����������塢���š�Ů�ŷ���
int Print_sort(SqList &L, string &str);//�������������str�ַ���
int Inputnum(country *c);//����������ݴ洢��country�ṹ����
void Inputscore(int cnum, country *c, int item, int rank);//��ͬ����Ŀ�����мӷ�
void CreateRank(country *c, SqList &Lz, SqList &Lm, SqList &Lw);//���ɼ������ܷ֡����š�Ů�����򣬷ֱ����Lz��Lm��Lw��
Status Delete_Sq(SqList &L);//ɾ���ڵ�L
void Print_num(country *c, string &str);//�����ұ������ɼ�
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// COlympicsScoreDlg �Ի���



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


// COlympicsScoreDlg ��Ϣ�������

BOOL COlympicsScoreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void COlympicsScoreDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
{//���ɼ�����������Ա���
	int i, j;
	ElemType *newbase;
	if (L.length >= L.listsize) // ��ǰ�洢�ռ�����,���ӷ���
	{
		if (!(newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType))))
			exit(-1); // �洢����ʧ��
		L.elem = newbase; // �»�ַ
		L.listsize += LISTINCREMENT; // ���Ӵ洢����
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
	str = "����   ���ұ��   ����\r\n";
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
	
	str_n = str_input.length();///�������Ŀ��ַ���
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

	if (item <= m)//������Ŀ
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
	else //Ů����Ŀ
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
	str = "���ұ��    ����\r\n";
	for (i = 0; i < n; i++) {
		j = i + 1;
		str += "       " + to_string(j);
		str += "         " + to_string(c[j].mscore + c[j].wscore);
		str += "  \r\n";
	}
}

void COlympicsScoreDlg::OnBnClickedInputButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	Inputnum(c);
	CreateRank(c, Lz, Lm, Lw);
	Print_sort(Lz, str_z);
	Print_sort(Lm, str_m);
	Print_sort(Lw, str_w);
	Print_num(c, str_n);
	INT_PTR nRes;             // ���ڱ���DoModal�����ķ���ֵ   

	CScoresort sortsocre;           // ����Ի�����CTipDlg��ʵ��   
	nRes = sortsocre.DoModal();  // �����Ի���   
	if (IDCANCEL == nRes)     // �ж϶Ի����˳��󷵻�ֵ�Ƿ�ΪIDCANCEL���������return�������������ִ��   
		return;
	Delete_Sq(Lz);
	Delete_Sq(Lm);
	Delete_Sq(Lw);
	//UpdateData(FALSE);
}


void COlympicsScoreDlg::OnStnClickedInstrzongStatic()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

}


void COlympicsScoreDlg::OnBnClickedInsGuizeButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CInstructionDlg instructionDlg;
	INT_PTR nRes;
	nRes = instructionDlg.DoModal();  // �����Ի���   
	if (IDCANCEL == nRes)     // �ж϶Ի����˳��󷵻�ֵ�Ƿ�ΪIDCANCEL���������return�������������ִ��   
		return;
}


void COlympicsScoreDlg::OnBnClickedResetButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_country = 0;
	m_man = 0; m_women = 0;
	m_inputscore = '\0';
	UpdateData(FALSE);
}
