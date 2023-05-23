
// AccessTest4Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "AccessTest4.h"
#include "AccessTest4Dlg.h"

#include "AccountDao.h"
#include "afxdialogex.h"
#include "DBManager.h"
#include "DebugUtil.h"
#include "MailDao.h"
#include "stdafx.h"
#include "strfunction.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
TAccount* nowacc;
TMail* nowmail;
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


// CAccessTest4Dlg 对话框



CAccessTest4Dlg::CAccessTest4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ACCESSTEST4_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAccessTest4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_LIST2, n_list);
}

BEGIN_MESSAGE_MAP(CAccessTest4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAccessTest4Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &CAccessTest4Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON2, &CAccessTest4Dlg::OnBnClickedButton2)
	ON_LBN_SELCHANGE(IDC_LIST1, &CAccessTest4Dlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON6, &CAccessTest4Dlg::OnBnClickedButton6)
	ON_EN_CHANGE(IDC_EDIT4, &CAccessTest4Dlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CAccessTest4Dlg::OnEnChangeEdit5)
	ON_BN_CLICKED(IDC_BUTTON7, &CAccessTest4Dlg::OnBnClickedButton7)
	ON_LBN_DBLCLK(IDC_LIST1, &CAccessTest4Dlg::OnDblclkList1)
	ON_BN_CLICKED(IDC_BUTTON4, &CAccessTest4Dlg::OnBnClickedButton4)
	ON_LBN_DBLCLK(IDC_LIST2, &CAccessTest4Dlg::OnDblclkList2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAccessTest4Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CAccessTest4Dlg 消息处理程序

BOOL CAccessTest4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

void CAccessTest4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAccessTest4Dlg::OnPaint()
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
HCURSOR CAccessTest4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




//修改内容
void CAccessTest4Dlg::OnBnClickedButton5()
{
	CString str, s0;
	CString name, password;
	std::string NAME, PASSWORD;
	if (nowacc != nullptr)
	{
		GetDlgItem(IDC_EDIT5)->GetWindowTextW(password);
		GetDlgItem(IDC_EDIT4)->GetWindowTextW(name);
		std::string NAME, PASSWORD;
		NAME = CT2CA(name.GetBuffer(0));
		PASSWORD = CT2CA(password.GetBuffer(0));
		nowacc->password = PASSWORD;
		nowacc->mailName = NAME;
		AccountDao::updateByPrimaryKey(*nowacc);
		MessageBox(_T("修改成功"), _T("结果"), MB_OK);
		CAccessTest4Dlg::OnBnClickedButton7();
	}
	else 
	{
		MessageBox(_T("未找到账号，无法修改"), _T("结果"), MB_OK);
	}
	// TODO: 在此添加控件通知处理程序代码
}

//添加按钮
void CAccessTest4Dlg::OnBnClickedButton2()
{
	CString name,password ;
	GetDlgItem(IDC_EDIT4)->GetWindowTextW(name);
	GetDlgItem(IDC_EDIT5)->GetWindowTextW(password);
	std::string NAME, PASSWORD;
	NAME = CT2CA(name.GetBuffer(0));
	TAccount* acc = AccountDao::selectByMailName(NAME);
	if (acc == nullptr)
	{
		PASSWORD = CT2CA(password.GetBuffer(0));
		AccountDao::insert(NAME, PASSWORD);
		MessageBox(_T("添加成功"), _T("结果"), MB_OK);
		CAccessTest4Dlg::OnBnClickedButton7();
	}
	else {
		MessageBox(_T("添加失败，该用户名已被占用"), _T("结果"), MB_OK);
	}

}
//添加邮件
void CAccessTest4Dlg::OnBnClickedButton1()
{
	if (nowacc != nullptr)
	{
		CString title, form, content;
		GetDlgItem(IDC_EDIT1)->GetWindowTextW(title);
		GetDlgItem(IDC_EDIT3)->GetWindowTextW(form);
		GetDlgItem(IDC_EDIT2)->GetWindowTextW(content);
		std::string TITLE, FORM, CONTENT;
		TITLE = CT2CA(title.GetBuffer(0));
		FORM = CT2CA(form.GetBuffer(0));
		CONTENT = CT2CA(content.GetBuffer(0));
		
		if (IsValidEmail(FORM))
		{
			MailDao::insert(nowacc->id, TITLE, CONTENT, FORM);
			MessageBox(_T("添加邮件成功！"), _T("结果"), MB_OK);
			//刷新显示
			int Count = m_list.GetCount();
			for (int j = Count; j >= 0; j--)
				n_list.DeleteString(j);
			_variant_t var;
			LPCTSTR  Id;
			CString strName;
			auto mail = MailDao::selectByMailId(nowacc->id);
			list<TMail*>::iterator it;
			int i = 0;
			for (it = mail->begin(); it != mail->end(); it++)
			{
				var = (*it)->id;
				Id = (LPCTSTR)_bstr_t(var);
				strName = (*it)->title.c_str();
				n_list.InsertString(i, Id + (CString)' ' + strName);
				i++;
			}
		}
		else {
			MessageBox(_T("添加邮件失败！form必须要邮箱格式"), _T("结果"), MB_OK);
		}
	}
	else {
		MessageBox(_T("添加邮件失败！请先双击选择账号"), _T("结果"), MB_OK);
	}
}

void CAccessTest4Dlg::OnLbnSelchangeList1()
{

	// TODO: 在此添加控件通知处理程序代码
}

//查询按钮
void CAccessTest4Dlg::OnBnClickedButton6()
{
	CString str,s0;
	GetDlgItem(IDC_EDIT4)->GetWindowTextW(str);
	std::string s = CT2CA(str.GetBuffer(0));
	TAccount* acc = AccountDao::selectByMailName(s);
	if (acc != nullptr)
	{
		MessageBox(_T("查找成功"), _T("结果"), MB_OK);
		s0 = acc->password.c_str();
		GetDlgItem(IDC_EDIT5)->SetWindowTextW(s0);
	}
	else
	{
		MessageBox(_T("查找失败，无对应账号"), _T("结果"), MB_OK);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CAccessTest4Dlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CAccessTest4Dlg::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

//显示按钮,用来显示账号列表
void CAccessTest4Dlg::OnBnClickedButton7()
{
	_variant_t var;
	LPCTSTR  Id;
	CString strName, strPassword;
	int i = 1;
	int Count = m_list.GetCount();
	for (int j = Count; j >= 0; j--)
		m_list.DeleteString(j);
	m_list.InsertString(0, (CString)"Id NAME PASSWORD");
	//清空列表框

	auto accounts = AccountDao::selectAll();       //声明一个list
	list<TAccount*>::iterator it;
	for(it = accounts->begin(); it != accounts->end();it++)
	{
		var = (*it)->id;
		Id = (LPCTSTR)_bstr_t(var);		
		strName= (*it)->mailName.c_str();
		strPassword = (*it)->password.c_str();
		m_list.InsertString(i, Id +(CString)' ' + strName + ' ' + strPassword + ' ');
		i++;
	
	}

	// TODO: 在此添加控件通知处理程序代码
}


//将选择的list显示在文本框上
void CAccessTest4Dlg::OnDblclkList1()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int nSel;
	nSel = m_list.GetCurSel();
	CString s,b[3];
	m_list.GetText(nSel, s);
	if (nSel > 0) 
	{
		//显示账号和密码在list
		UpdateData(TRUE);
		CStringArray array;
		int n = Div(s, ' ', array);
		GetDlgItem(IDC_EDIT4)->SetWindowTextW(array[1]);
		GetDlgItem(IDC_EDIT5)->SetWindowTextW(array[2]);
		std::string s0 = CT2CA(array[1].GetBuffer(0));
		nowacc = AccountDao::selectByMailName(s0);

		//将邮件的title按顺序显示在右边
		int Count = m_list.GetCount();
		for (int j = Count; j >= 0; j--)
			n_list.DeleteString(j);
		_variant_t var;
		LPCTSTR  Id;
		CString strName;
		auto mail = MailDao::selectByMailId(nowacc->id);
		list<TMail*>::iterator it;
		int i = 0;
		for (it = mail->begin(); it != mail->end(); it++) 
		{
			var = (*it)->id;
			Id = (LPCTSTR)_bstr_t(var);
			strName = (*it)->title.c_str();
			n_list.InsertString(i, Id + (CString)' ' + strName );
			i++;
		}
	}

	// TODO: 在此添加控件通知处理程序代码
}

//删除按钮
void CAccessTest4Dlg::OnBnClickedButton4()
{
	if (nowacc != nullptr)
	{
		AccountDao::deleteByPrimaryKey(nowacc->id);
		MessageBox(_T("删除成功"), _T("结果"), MB_OK);
		CAccessTest4Dlg::OnBnClickedButton7();
	}
	// TODO: 在此添加控件通知处理程序代码
}

//对邮件进行操作
void CAccessTest4Dlg::OnDblclkList2()
{
	int nSel;
	nSel = n_list.GetCurSel();
	CString s, b[2];
	n_list.GetText(nSel, s);
	CStringArray array;
	int n = Div(s, ' ', array);
	int Id = _ttoi(array[0]);
	auto mail = MailDao::selectByMailId(nowacc->id);
	list<TMail*>::iterator it;
	for (it = mail->begin(); it != mail->end(); it++)
	{
		if ((*it)->id == Id)
			break;
	}
	nowmail = *it;
	CString s0;
	s0 = (*it)->title.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(s0);
	s0 = (*it)->from.c_str();
	GetDlgItem(IDC_EDIT3)->SetWindowTextW(s0);
	s0 = (*it)->content.c_str();
	GetDlgItem(IDC_EDIT2)->SetWindowTextW(s0);
	// TODO: 在此添加控件通知处理程序代码
}

//删除邮件
void CAccessTest4Dlg::OnBnClickedButton3()
{
	if (nowmail != nullptr) {
		MailDao::deleteByPrimaryKey(nowmail->id);
		MessageBox(_T("删除邮件成功"), _T("结果"), MB_OK);
		//刷新显示
		int Count = m_list.GetCount();
		for (int j = Count; j >= 0; j--)
			n_list.DeleteString(j);
		_variant_t var;
		LPCTSTR  Id;
		CString strName;
		auto mail = MailDao::selectByMailId(nowacc->id);
		list<TMail*>::iterator it;
		int i = 0;
		for (it = mail->begin(); it != mail->end(); it++)
		{
			var = (*it)->id;
			Id = (LPCTSTR)_bstr_t(var);
			strName = (*it)->title.c_str();
			n_list.InsertString(i, Id + (CString)' ' + strName);
			i++;
		}
	}
	// TODO: 在此添加控件通知处理程序代码
}
