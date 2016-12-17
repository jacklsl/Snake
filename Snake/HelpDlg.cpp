// HelpDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Snake.h"
#include "HelpDlg.h"
#include "afxdialogex.h"


// HelpDlg 对话框

IMPLEMENT_DYNAMIC(CHelpDlg, CDialogEx)

CHelpDlg::CHelpDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHelpDlg::IDD, pParent)
{

}

CHelpDlg::~CHelpDlg()
{
}

void CHelpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHelpDlg, CDialogEx)
	ON_BN_CLICKED(IDC_OK_BUTTON, &CHelpDlg::OnClickedOkButton)
END_MESSAGE_MAP()


// HelpDlg 消息处理程序


void CHelpDlg::OnClickedOkButton()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialog::OnOK();
}
