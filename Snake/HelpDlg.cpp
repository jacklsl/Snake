// HelpDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Snake.h"
#include "HelpDlg.h"
#include "afxdialogex.h"


// HelpDlg �Ի���

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


// HelpDlg ��Ϣ�������


void CHelpDlg::OnClickedOkButton()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnOK();
}
