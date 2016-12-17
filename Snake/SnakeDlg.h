
// SnakeDlg.h : 头文件
//

#pragma once

#include "SnakeGame.h"
// CSnakeDlg 对话框
class CSnakeDlg : public CDialogEx
{
// 构造
public:
	void Help();//帮助功能函数
	void HeroList();//英雄榜功能函数
	void StartGame();//开始游戏功能函数
	void PlayBackMusic(BOOL bflg);//播放背景音乐功能函数
	void InitMenu();//初始化菜单
	CSnakeDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SNAKE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;//主图标
	CMenu m_main_menu;//主菜单对象
	BOOL  m_bStart;//游戏开始标志
	CSnakeGame m_snake;//主游戏对象
	// 生成的消息映射函数
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
