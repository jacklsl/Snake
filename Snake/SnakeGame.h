#pragma once


// CSnakeGame
#include"Afxtempl.h"//插入模板头文件
#define GAME_LEVEL_LOW 2//定义各种宏
#define GAME_LEVEL_NOR 4
#define GAME_LEVEL_HIGH 8

#define DIREC_UP 1//向上的标志
#define DIREC_DOWN 2//向下的标志
#define DIREC_RIGHT 3//向右的标志
#define DIREC_LEFT 4//向左的标志

#define LOW_LEVEL_SLEEP 100
#define NOR_LEVEL_SLEEP 50
#define HIGH_LEVEL_SLEEP 30

class CSnakeGame : public CWnd
{
	DECLARE_DYNAMIC(CSnakeGame)


public:
	void HeroWrite();//弹出英雄榜并写入
	void ReDrawBody(CPoint pt);//重绘一个点
	void InitGame();//初始化游戏


	CSnakeGame();//构造函数
	virtual ~CSnakeGame();//析构函数
	BOOL GameStart();//游戏开始函数
	void InitFoods();//初始化果实函数
	void SetGameLevel(int level);//设置游戏等级
private:
	CPoint m_psFood;//当前食物坐标
	int m_nDirect;//当前蛇前进方向
	int m_nScore;//当前游戏分数
	int m_nLevel;//当前游戏等级
	int m_nHighScore;//当前游戏最高分
	CArray<CPoint, CPoint>m_Body;//蛇身向量
protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};


