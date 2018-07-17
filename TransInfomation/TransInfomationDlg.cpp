
// TransInfomationDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TransInfomation.h"
#include "TransInfomationDlg.h"
#include "afxdialogex.h"
#include "AddRoad.h"
#include <iostream>
#include "CityGraph.h"
string int2string(int i);
int string2int(string s);
CString int2Cstring(int i);
CString StringToCString(const string &st);
CString getstring(const int i);
extern CityGraph enviroment;
using namespace std;
//CityGraph citygraph;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTransInfomationDlg 对话框



CTransInfomationDlg::CTransInfomationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTransInfomationDlg::IDD, pParent)
	, begincity(_T(""))
	, endcity(_T(""))
	, trantool(0)
	, way(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTransInfomationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, begincity);
	DDX_Text(pDX, IDC_EDIT2, endcity);
	DDX_Radio(pDX, IDC_RADIO1, trantool);
	DDV_MinMaxInt(pDX, trantool, 0, 1);
	DDX_Radio(pDX, IDC_RADIO3, way);
	DDV_MinMaxInt(pDX, way, 0, 1);
	DDX_Control(pDX, IDC_BUTTON1, Add);
	DDX_Control(pDX, IDOK, Search);
}

BEGIN_MESSAGE_MAP(CTransInfomationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTransInfomationDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDOK, &CTransInfomationDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTransInfomationDlg 消息处理程序

BOOL CTransInfomationDlg::OnInitDialog()
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

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTransInfomationDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTransInfomationDlg::OnPaint()
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
HCURSOR CTransInfomationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTransInfomationDlg::OnBnClickedAdd()
{
	// TODO:  在此添加控件通知处理程序代码
	AddRoad ad;
	int nRent = ad.DoModal();
	// TODO:  在此添加控件通知处理程序代码
}


void CTransInfomationDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	USES_CONVERSION;
	char* b = W2A(begincity);
	char* e = W2A(endcity);
	string be = b;
	string en = e;
	int first = enviroment.HeadIndex(be);
	//AfxMessageBox(TEXT("begin=" + int2Cstring(first)));
	int d[20] = { 0 };
	int p[20] = { 0 };
	string all[20];
	int al = 0;
	if (way == 0)
		enviroment.ShortestPathtime(first, trantool, d, p);
	else
		enviroment.ShortestPathcost(first, trantool, d, p);
	int last = enviroment.HeadIndex(en);
	//(TEXT("last=" + int2Cstring(last)));
	int i = last;
	//绘图
	//获取设备
	CDC *pDC = GetDC();
	//绘图区域
	CRect rect(410, 70, 550, 210);
	CRect rect2(415, 50, 550, 210);
	CRect rect3(375, 50, 410, 210);
	//CRect rect3(410, 50, 750, 310);
	//清除原有文字
	COLORREF bkColor = GetSysColor(COLOR_3DFACE);
	pDC->FillSolidRect(rect2, bkColor);
	pDC->FillSolidRect(rect3, bkColor);
	pDC->FillSolidRect(rect, bkColor);
	//设置字体为系统字体
	HGDIOBJ hFont = GetStockObject(DEFAULT_GUI_FONT);
	CFont font;
	font.Attach(hFont);
	pDC->SelectObject(&font);
	//设置背景
	pDC->SetBkMode(TRANSPARENT);
	//绘图
	string s = enviroment.GetName(i,1);
	all[al] = s;
	al++;
	if (!way)
	pDC->DrawText(StringToCString("用时："), &rect3, DT_LEFT);
	else
	pDC->DrawText(StringToCString("花费："), &rect3, DT_LEFT);
	
	pDC->DrawText(getstring(d[last]), &rect2, DT_LEFT);



	
	while (i != 0 &&p[i] != first)
	{
		i = p[i];
		
		//CRect rect(u, v, 550, 210);
		
		s = enviroment.GetName(i, 1);
		//pDC->DrawText(StringToCString(s), &rect, DT_LEFT);
		all[al] = s;
		al++;
	
	}
	//v = v + 20;
	//CRect rect3(u, v, 550, 210);
	s = enviroment.GetName(p[i], 1);
	all[al] = s;
	//al++;
	int v = 70;
	for (int i = al; i >= 0; i--)
	{
		v = v + 20;
		CRect rect(410, v, 550, 210);
		pDC->DrawText(StringToCString(all[i]), &rect, DT_LEFT);
	}
	//pDC->DrawText(StringToCString(s), &rect3, DT_LEFT);
	ReleaseDC(pDC);

}
CString getstring(const int i)

{

	CString str;
	str.Format(_T("%d"), i);
	return str;
}
CString StringToCString( const string &st)
{
	  
	CString cstr(st.c_str());
	  return cstr;
}