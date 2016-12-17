// SnakeGame.cpp : 实现文件
//

#include "stdafx.h"
#include "Snake.h"
#include "SnakeGame.h"
#include "Rule.h"
#include "HeroDlg.h"
// CSnakeGame

IMPLEMENT_DYNAMIC(CSnakeGame, CWnd)

CSnakeGame::CSnakeGame()
{
	m_nScore = 0;
	m_psFood.x = 30;
	m_psFood.y = 30;
	m_nHighScore = 0;
}

CSnakeGame::~CSnakeGame()
{
}


BEGIN_MESSAGE_MAP(CSnakeGame, CWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_KEYUP()
END_MESSAGE_MAP()


// CSnakeGame 消息处理程序




void CSnakeGame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);//创建内存绘制DC对象
	CBitmap bmp;
	CPen pen;
	bmp.LoadBitmapA(IDB_BMP_BJ);
	pen.CreatePen(PS_SOLID, 1, 0xff);
	MemDC.SelectObject(&bmp);
	MemDC.SelectObject(&pen);
	MemDC.SetROP2(R2_NOTXORPEN);
	CString ysStr;//定义字符串用于显示游戏时间，得分，等级
	MemDC.SetBkMode(TRANSPARENT);//设置字体背景
	MemDC.SetTextColor(67);//设置字体颜色并初始化字符串
	ysStr.Format("当前得分:%d", m_nScore);
	MemDC.TextOut(30, 50, ysStr);
//——————————根据等级判断——————————//
	switch (m_nLevel)
	{
	case GAME_LEVEL_LOW:
		ysStr.Format("当前等级：初级");
		break;
	case GAME_LEVEL_NOR:
		ysStr.Format("当前等级：中级");
		break;
	case GAME_LEVEL_HIGH:
		ysStr.Format("当前等级：高级");
		break;

	default:
		ysStr.Format("当前等级显示出错！");
		break;
	}
	MemDC.TextOut(30, 30, ysStr);//输出字符
 //——————————绘制蛇的样式——————————//
	CPen yspen;//定义白色画笔绘制蛇的边框
	yspen.CreatePen(1, 1, RGB(255, 255, 255));
	MemDC.SelectObject(&yspen);

	CBrush ysbrush;
	int k = m_Body.GetUpperBound() + 2;//设置一个变量存储贪吃蛇的身体长度
	if (k < 10)
	{
		ysbrush.CreateSolidBrush(RGB(0, 255, 0));//如果k<10为真，那么贪吃蛇就为绿色
		MemDC.SelectObject(&ysbrush);
		//------绘制果实------//
		MemDC.Rectangle(
			CRect(10 + m_psFood.y * 10, 
			120 + m_psFood.x * 10, 
			10 + (m_psFood.y + 1) * 10, 
			120 + (m_psFood.x + 1) * 10)
			);

	}
	else if (k>10&&k<20)
	{
		ysbrush.CreateSolidBrush(RGB(0, 0, 255));//如果k>10且k<20为真，那么贪吃蛇就为蓝色
		MemDC.SelectObject(&ysbrush);
		//------绘制果实------//
		MemDC.Rectangle(
			CRect(10 + m_psFood.y * 10,
			120 + m_psFood.x * 10,
			10 + (m_psFood.y + 1) * 10,
			120 + (m_psFood.x + 1) * 10)
			);
	}
	else if (k>20&&k<30)
	{
		ysbrush.CreateSolidBrush(RGB(255, 255, 0));//如果k>20且k<30为真，那么贪吃蛇就为黄色
		MemDC.SelectObject(&ysbrush);
		//------绘制果实------//
		MemDC.Rectangle(
			CRect(10 + m_psFood.y * 10,
			120 + m_psFood.x * 10,
			10 + (m_psFood.y + 1) * 10,
			120 + (m_psFood.x + 1) * 10)
			);

	}
	else
	{
		ysbrush.CreateSolidBrush(RGB(255, 0, 0));
		MemDC.SelectObject(&ysbrush);
		//------绘制果实------//
		MemDC.Rectangle(
			CRect(10+m_psFood.y*10,
			120+m_psFood.x*10,
			10 + (m_psFood.y+1)*10,
			120 + (m_psFood.x+1)*10)
			);
	}
	//---------------初始化点数组---------------//
	for (int i = 0; i <= m_Body.GetUpperBound(); i++)
	{
		CPoint ysPoint = m_Body.GetAt(i);
		MemDC.Rectangle(
			CRect(10 + ysPoint.y * 10,
			120 + ysPoint.x * 10,
			10 + (ysPoint.y + 1) * 10,
			120 + (ysPoint.x + 1) * 10)
			);
	}
	dc.BitBlt(0, 0, 325, 425, &MemDC, 0, 0, SRCCOPY);
	// 不为绘图消息调用 CWnd::OnPaint()
}


void CSnakeGame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CPoint ysPoint = m_Body.GetAt(0);//get the first point of the snake
	BOOL bTag = FALSE;//set the dead's  variable
	CRule rule;//declare the class of rule
	switch (m_nDirect)
	{
	case DIREC_DOWN://the direct is down
		ysPoint.x++;//X-axis is add-self
		break;
	case DIREC_UP://the direct is up
		ysPoint.x--;//X-axis is  sub-self
		break;
	case DIREC_RIGHT://the direct is right
		ysPoint.y++;//Y-axis is add-self
		break;
	case DIREC_LEFT://the direct is left
		ysPoint.y--;//Y-axis is sub-self
		break;
	default:
		break;
	}

	if (rule.IsOver(ysPoint, m_Body))//if the game over is true
	{
		
		KillTimer(1);//shut down the timer
		if (m_nScore > m_nHighScore)//if you score is greater than the High score
		{
			HeroWrite();//write in to herolist
		}
		else
		{
			AfxMessageBox("游戏结束，您的分数太低没能进入英雄榜");
		}
		
		
	}
	else
	{
		m_Body.InsertAt(0, ysPoint);//insert new point to the snake's body
		ReDrawBody(ysPoint);//redraw the snake's body
		if (ysPoint.x == m_psFood.x&&ysPoint.y == m_psFood.y)//if the sanke's coordinate equal the food's  coordinate 
		{
			int nlen = m_Body.GetUpperBound();//get the length of sanke
			m_nScore = m_nLevel*(nlen - 3);//get the score what you get
			InitFoods();//init the next food
			Invalidate();// redraw window
		}
		else
		{
			CPoint pt = m_Body.GetAt(m_Body.GetUpperBound());//get the last point
			m_Body.RemoveAt(m_Body.GetUpperBound());//remove the last point 
			ReDrawBody(pt);//redraw a point
		}
	}
	CWnd::OnTimer(nIDEvent);
}


void CSnakeGame::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	switch (nChar)
	{
	case VK_UP://按向上键
		m_nDirect = DIREC_UP;//控制方向向量为 DIREC_UP
		break;	
	case VK_DOWN://按向下键
		m_nDirect = DIREC_DOWN;//控制方向向量为DIREC_DOWN
		break;
	case VK_LEFT://按向左键
		m_nDirect = DIREC_LEFT;//控制方向向量为DIREC_LEFT
		break;
	case VK_RIGHT://按向右键
		m_nDirect = DIREC_RIGHT;//控制方向向量为DIREC_RIGHT
		break;
	default:
		break;
	}

	CWnd::OnKeyUp(nChar, nRepCnt, nFlags);
}

void CSnakeGame::InitFoods()
{
	int m_ysX, m_ysY;
	while (1)
	{
		m_ysX = rand() % 28;
		m_ysY = rand() % 28;
		for (int i = 0; i <= m_Body.GetUpperBound(); i++)
		{
			CPoint ysPoint1 = m_Body.GetAt(i);//get the snake's body point
			if (ysPoint1.x != m_ysX || ysPoint1.y != m_ysY)//if the body's point of X and y,is equel the food's
			{
				m_psFood = CPoint(m_ysX, m_ysY);//mark the point is food's point
				return;
			}
		}
	}
}

void CSnakeGame::SetGameLevel(int level)
{
	m_nLevel = level;
}

BOOL CSnakeGame::GameStart()
{
	int nSleep = LOW_LEVEL_SLEEP;//set the default time of sleep
	char pszTmp[128] = { 0 };
	switch (m_nLevel)
	{
	case GAME_LEVEL_HIGH://high level
		nSleep = HIGH_LEVEL_SLEEP;
		break;
	case GAME_LEVEL_NOR:
		nSleep = NOR_LEVEL_SLEEP;//middle level
		break;
	default:
		break;
	}
	GetPrivateProfileString("HERO", "score", "0", pszTmp, 127, ".\\hero.ini");//read the game's record of score
	m_nHighScore = atoi(pszTmp);
	SetTimer(1, nSleep, NULL);//set the game's timer
	InitGame();//init the game
	return TRUE;
}

//------------------初始化游戏------------------//
void CSnakeGame::InitGame()
{
	m_Body.RemoveAll();//remove all data
	//------add the snake's length------//
	m_Body.Add(CPoint(3, 8));
	m_Body.Add(CPoint(3, 7));
	m_Body.Add(CPoint(3, 6));
	m_Body.Add(CPoint(3, 5));

	srand((unsigned)time(NULL));
	m_nDirect = DIREC_RIGHT;//the direct is RIGHT when init game
	m_nScore;//init score
	InitFoods();//init food
	Invalidate();//redraw window
}

//-------------redraw point-------------//
void CSnakeGame::ReDrawBody(CPoint pt)
{
	InvalidateRect(
		CRect(10 + pt.y * 10,
		120 + pt.x * 10,
		10 + (pt.y + 1) * 10,
		120 + (pt.x + 1) * 10)
		);

}
//------write somting to herolist and herolist's popup------//
void CSnakeGame::HeroWrite()
{
	CHeroDlg dlg;
	dlg.SetWriteFlg(TRUE);//set the flg of herdlg
	dlg.m_level = m_nLevel;//set the level
	dlg.m_score = m_nScore;//set the score
	dlg.DoModal();
}