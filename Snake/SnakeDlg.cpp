
// SnakeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Snake.h"
#include "SnakeDlg.h"
#include "afxdialogex.h"
#include "HelpDlg.h"
#include "HeroDlg.h"
#include <mmsystem.h>
#pragma comment( lib, "Winmm.lib" )
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()

public:
//	afx_msg void OnPaint();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

//	ON_WM_PAINT()
END_MESSAGE_MAP()


// CSnakeDlg �Ի���



CSnakeDlg::CSnakeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSnakeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSnakeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSnakeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_UPDATE_COMMAND_UI(IDR_ABOUT, &CSnakeDlg::OnUpdateIdrAbout)
	ON_UPDATE_COMMAND_UI(IDR_EXIT_GAME, &CSnakeDlg::OnUpdateIdrExitGame)
	ON_UPDATE_COMMAND_UI(IDR_HELP, &CSnakeDlg::OnUpdateIdrHelp)
	ON_UPDATE_COMMAND_UI(IDR_HERO_LIST, &CSnakeDlg::OnUpdateIdrHeroList)
	ON_UPDATE_COMMAND_UI(IDR_LEVEL_HIGH, &CSnakeDlg::OnUpdateIdrLevelHigh)
	ON_UPDATE_COMMAND_UI(IDR_LEVEL_LOW, &CSnakeDlg::OnUpdateIdrLevelLow)
	ON_UPDATE_COMMAND_UI(IDR_LEVEL_NOR, &CSnakeDlg::OnUpdateIdrLevelNor)
	ON_UPDATE_COMMAND_UI(IDR_PLAY_MUSIC, &CSnakeDlg::OnUpdateIdrPlayMusic)
	ON_UPDATE_COMMAND_UI(IDR_START_GAME, &CSnakeDlg::OnUpdateIdrStartGame)
END_MESSAGE_MAP()


// CSnakeDlg ��Ϣ�������

BOOL CSnakeDlg::OnInitDialog()
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	m_main_menu.LoadMenu(IDR_MAIN_MENU);//�������˵�

	SetMenu(&m_main_menu);//�������˵�
	InitMenu();//��ʼ�����˵�

	m_snake.CreateEx(WS_EX_CLIENTEDGE, _T("SNAKEMAP"), NULL, WS_VISIBLE | WS_BORDER | WS_CHILD,
		CRect(0, 0, 325, 425), this, SNAKEMAP);

	GetDlgItem(SNAKEMAP)->SetFocus();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CSnakeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSnakeDlg::OnPaint()
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
HCURSOR CSnakeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSnakeDlg::InitMenu()
{
	m_main_menu.CheckMenuItem(IDR_LEVEL_LOW, MF_BYCOMMAND | MF_CHECKED);
	m_main_menu.CheckMenuItem(IDR_LEVEL_HIGH, MF_BYCOMMAND | MF_UNCHECKED);
	m_main_menu.CheckMenuItem(IDR_LEVEL_NOR, MF_BYCOMMAND | MF_UNCHECKED);
	m_main_menu.CheckMenuItem(IDR_PLAY_MUSIC, MF_BYCOMMAND | MF_UNCHECKED);
	m_bStart = TRUE;
	m_snake.SetGameLevel(GAME_LEVEL_LOW);
}
void CSnakeDlg::Help()
{
	CHelpDlg dlg;
	dlg.DoModal();
}

void CSnakeDlg::HeroList()
{
	CHeroDlg dlg;
	dlg.DoModel();
}

void CSnakeDlg::PlayBackMusic(BOOL bflg)
{
	if (bflg)
	{
		sndPlaySound("music.wav", SND_ASYNC);
		//sndPlaySound(".\\music.wav", SND_LOOP);
	}
	else
	{
		sndPlaySound("NULL", SND_PURGE);
	}
}
void CSnakeDlg::OnUpdateIdrAbout(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();//�����Ի���

}


void CSnakeDlg::OnUpdateIdrExitGame(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	CDialog::OnCancel();
}


void CSnakeDlg::OnUpdateIdrHelp(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	Help();
}


void CSnakeDlg::OnUpdateIdrHeroList(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	HeroList();
}


void CSnakeDlg::OnUpdateIdrLevelHigh(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	BOOL bCheck = (BOOL)m_main_menu.GetMenuState(IDR_LEVEL_HIGH, MF_CHECKED);
	if (!bCheck)
	{
		m_main_menu.CheckMenuItem(IDR_LEVEL_LOW, MF_BYCOMMAND | MF_UNCHECKED);
		m_main_menu.CheckMenuItem(IDR_LEVEL_HIGH, MF_BYCOMMAND | MF_CHECKED);
		m_main_menu.CheckMenuItem(IDR_LEVEL_NOR, MF_BYCOMMAND | MF_UNCHECKED);
	}
}


void CSnakeDlg::OnUpdateIdrLevelLow(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	BOOL bCheck = (BOOL)m_main_menu.GetMenuState(IDR_LEVEL_LOW, MF_CHECKED);
	if (!bCheck)
	{
		m_main_menu.CheckMenuItem(IDR_LEVEL_LOW, MF_BYCOMMAND | MF_CHECKED);
		m_main_menu.CheckMenuItem(IDR_LEVEL_HIGH, MF_BYCOMMAND | MF_UNCHECKED);
		m_main_menu.CheckMenuItem(IDR_LEVEL_NOR, MF_BYCOMMAND | MF_UNCHECKED);
	}
}


void CSnakeDlg::OnUpdateIdrLevelNor(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	BOOL bCheck = (BOOL)m_main_menu.GetMenuState(IDR_LEVEL_NOR, MF_CHECKED);
	if (!bCheck)
	{
		m_main_menu.CheckMenuItem(IDR_LEVEL_LOW, MF_BYCOMMAND | MF_UNCHECKED);
		m_main_menu.CheckMenuItem(IDR_LEVEL_HIGH, MF_BYCOMMAND | MF_UNCHECKED);
		m_main_menu.CheckMenuItem(IDR_LEVEL_NOR, MF_BYCOMMAND | MF_CHECKED);
	}
}


void CSnakeDlg::OnUpdateIdrPlayMusic(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	BOOL bCheck = (BOOL)m_main_menu.GetMenuState(IDR_PLAY_MUSIC, MF_CHECKED);
	if (bCheck)
	{
		m_main_menu.CheckMenuItem(IDR_PLAY_MUSIC, TBIF_COMMAND | MF_UNCHECKED);
	}
	else
	{
		m_main_menu.CheckMenuItem(IDR_PLAY_MUSIC, TBIF_COMMAND | MF_CHECKED);
	}
	PlayBackMusic(!bCheck);
}


void CSnakeDlg::OnUpdateIdrStartGame(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	m_snake.GameStart();
}


