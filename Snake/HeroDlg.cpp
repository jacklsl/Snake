// HeroDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Snake.h"
#include "HeroDlg.h"
#include "afxdialogex.h"


// CHeroDlg �Ի���

IMPLEMENT_DYNAMIC(CHeroDlg, CDialogEx)

CHeroDlg::CHeroDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHeroDlg::IDD, pParent)
{
	m_bWriteflg = FALSE;//��ʼ��д��־ΪFALSE
}

CHeroDlg::~CHeroDlg()
{
}

void CHeroDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);//��������Դӳ��
	DDX_Text(pDX, IDC_LEVEL_EDIT, m_level);
	DDX_Text(pDX, IDC_NAME_EDIT, m_name);
	DDX_Text(pDX, IDC_SCORE_EDIT, m_score);
	DDV_MinMaxInt(pDX, m_score, 0, 10000);
}


BEGIN_MESSAGE_MAP(CHeroDlg, CDialogEx)
	ON_BN_CLICKED(IDC_HERO_BUTTON, &CHeroDlg::OnClickedHeroButton)
END_MESSAGE_MAP()


// CHeroDlg ��Ϣ�������
void CHeroDlg::SetWriteFlg(BOOL bflg)
{
	m_bWriteflg = bflg;
}
int CHeroDlg::DoModel()//����Ӣ�۰�Ի���
{
	char pszTmp[128] = { 0 };
	GetPrivateProfileStringA("HERO", "name", "0", pszTmp, 127, ".\\hero.ini");//��ȡ����
	m_name = CString(pszTmp);
	if (!m_bWriteflg)
	{
		GetPrivateProfileStringA("HERO", "score", "0", pszTmp, 127, ".\\hero.ini");//��ȡ����
		m_score = atoi(pszTmp);

		GetPrivateProfileStringA("HERO", "level", "0", pszTmp, 127, ".\\hero.ini");//��ȡ�ȼ�
		m_level = atoi(pszTmp);

	}

	return CDialog::DoModal();
}
void CHeroDlg::OnClickedHeroButton()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);//������ʾ��ֵ������
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
		SetDlgItemText(IDC_HERO_BUTTON, "��¼");//��Ϊд��ʱ���ı䰴ť����
	}
	return TRUE;
}
