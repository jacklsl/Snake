// HeroDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Snake.h"
#include "HeroDlg.h"
#include "afxdialogex.h"


// CHeroDlg 对话框

IMPLEMENT_DYNAMIC(CHeroDlg, CDialogEx)

CHeroDlg::CHeroDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHeroDlg::IDD, pParent)
{
	m_bWriteflg = FALSE;//初始化写标志为FALSE
}

CHeroDlg::~CHeroDlg()
{
}

void CHeroDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);//变量与资源映射
	DDX_Text(pDX, IDC_LEVEL_EDIT, m_level);
	DDX_Text(pDX, IDC_NAME_EDIT, m_name);
	DDX_Text(pDX, IDC_SCORE_EDIT, m_score);
	DDV_MinMaxInt(pDX, m_score, 0, 10000);
}


BEGIN_MESSAGE_MAP(CHeroDlg, CDialogEx)
	ON_BN_CLICKED(IDC_HERO_BUTTON, &CHeroDlg::OnClickedHeroButton)
END_MESSAGE_MAP()


// CHeroDlg 消息处理程序
void CHeroDlg::SetWriteFlg(BOOL bflg)
{
	m_bWriteflg = bflg;
}
int CHeroDlg::DoModel()//弹出英雄榜对话框
{
	char pszTmp[128] = { 0 };
	GetPrivateProfileStringA("HERO", "name", "0", pszTmp, 127, ".\\hero.ini");//读取姓名
	m_name = CString(pszTmp);
	if (!m_bWriteflg)
	{
		GetPrivateProfileStringA("HERO", "score", "0", pszTmp, 127, ".\\hero.ini");//读取分数
		m_score = atoi(pszTmp);

		GetPrivateProfileStringA("HERO", "level", "0", pszTmp, 127, ".\\hero.ini");//读取等级
		m_level = atoi(pszTmp);

	}

	return CDialog::DoModal();
}
void CHeroDlg::OnClickedHeroButton()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);//更新显示数值到变量
	if (m_bWriteflg)
	{
		CString tmp;
		tmp.Format("%d", m_score);
		WritePrivateProfileString(_T("HERO"), _T("name"), m_name, _T("'.\\hero.ini"));
		WritePrivateProfileString("HERO", "score", tmp,".\\hero,ini");
		tmp.Format("%d", m_level);
		WritePrivateProfileString("HERO", "level", tmp, ".\\hero.ini");
	}
	m_bWriteflg = FALSE;
	CDialog::OnOK();

}
void CHeroDlg::OnOK()
{

}
BOOL CHeroDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	if (m_bWriteflg)
	{
		SetDlgItemText(IDC_HERO_BUTTON, "记录");//当为写入时，改变按钮名称
	}
	return TRUE;
}
