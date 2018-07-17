// AddRoad.cpp : 实现文件
//

#include "stdafx.h"
#include "TransInfomation.h"
#include "AddRoad.h"
#include "afxdialogex.h"
#include <iostream>
#include "CityGraph.h"
CityGraph enviroment;
using namespace std;
//CityGraph citygraph;
// AddRoad 对话框

IMPLEMENT_DYNAMIC(AddRoad, CDialogEx)

AddRoad::AddRoad(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddRoad::IDD, pParent)
	, begincity(_T(""))
	, endcity(_T(""))
	, traintime(0)
	, flytime(0)
	, traincost(0)
	, flycost(0)
{

}

AddRoad::~AddRoad()
{
}

void AddRoad::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, begincity);
	DDX_Text(pDX, IDC_EDIT2, endcity);
	DDX_Text(pDX, IDC_EDIT3, traintime);
	DDV_MinMaxDouble(pDX, traintime, 0, 10000);
	DDX_Text(pDX, IDC_EDIT4, flytime);
	DDV_MinMaxDouble(pDX, flytime, 0, 10000);
	DDX_Text(pDX, IDC_EDIT5, traincost);
	DDV_MinMaxDouble(pDX, traincost, 0, 10000);
	DDX_Text(pDX, IDC_EDIT6, flycost);
	DDV_MinMaxDouble(pDX, flycost, 0, 10000);
	DDX_Control(pDX, IDOK, Addnow);
}


BEGIN_MESSAGE_MAP(AddRoad, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddRoad::OnBnClickedOk)
END_MESSAGE_MAP()


// AddRoad 消息处理程序


void AddRoad::OnBnClickedOk()
{
	
	UpdateData(true);
	int t[2] = { traintime, flytime };
	int co[2] = { traincost, flycost };

	USES_CONVERSION;
	char* b = W2A(begincity);
	char* e = W2A(endcity);
	string be = b;
	string en = e;
	enviroment.AddCity(be, en, t, co);
		MessageBox(_T("添加成功！"));
	CDialogEx::OnOK();
}
