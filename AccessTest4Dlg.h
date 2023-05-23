
// AccessTest4Dlg.h: 头文件
//

#pragma once

// CAccessTest4Dlg 对话框
class CAccessTest4Dlg : public CDialogEx
{
// 构造
public:
	CAccessTest4Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ACCESSTEST4_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedButton7();
	CListBox m_list;
	afx_msg void OnDblclkList1();
	afx_msg void OnBnClickedButton4();
	CListBox n_list;
	afx_msg void OnDblclkList2();
	afx_msg void OnBnClickedButton3();
};
