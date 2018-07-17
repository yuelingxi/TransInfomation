#pragma once
#include "afxwin.h"


// AddRoad 对话框

class AddRoad : public CDialogEx
{
	DECLARE_DYNAMIC(AddRoad)

public:
	AddRoad(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddRoad();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString begincity;
	CString endcity;
	int traintime;
	int flytime;
	int traincost;
	int flycost;
	CButton Addnow;
	afx_msg void OnBnClickedOk();
};
