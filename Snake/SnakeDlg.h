
// SnakeDlg.h : ͷ�ļ�
//

#pragma once

#include "SnakeGame.h"
// CSnakeDlg �Ի���
class CSnakeDlg : public CDialogEx
{
// ����
public:
	void Help();//�������ܺ���
	void HeroList();//Ӣ�۰��ܺ���
	void StartGame();//��ʼ��Ϸ���ܺ���
	void PlayBackMusic(BOOL bflg);//���ű������ֹ��ܺ���
	void InitMenu();//��ʼ���˵�
	CSnakeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SNAKE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;//��ͼ��
	CMenu m_main_menu;//���˵�����
	BOOL  m_bStart;//��Ϸ��ʼ��־
	CSnakeGame m_snake;//����Ϸ����
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnUpdateIdrAbout(CCmdUI *pCmdUI);
	afx_msg void OnUpdateIdrExitGame(CCmdUI *pCmdUI);
	afx_msg void OnUpdateIdrHelp(CCmdUI *pCmdUI);
	afx_msg void OnUpdateIdrHeroList(CCmdUI *pCmdUI);
	afx_msg void OnUpdateIdrLevelHigh(CCmdUI *pCmdUI);
	afx_msg void OnUpdateIdrLevelLow(CCmdUI *pCmdUI);
	afx_msg void OnUpdateIdrLevelNor(CCmdUI *pCmdUI);
	afx_msg void OnUpdateIdrPlayMusic(CCmdUI *pCmdUI);
	afx_msg void OnUpdateIdrStartGame(CCmdUI *pCmdUI);
	DECLARE_MESSAGE_MAP()

public:
	
	
	
};
