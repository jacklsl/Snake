// SnakeGame.cpp : ʵ���ļ�
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


// CSnakeGame ��Ϣ�������




void CSnakeGame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);//�����ڴ����DC����
	CBitmap bmp;
	CPen pen;
	bmp.LoadBitmapA(IDB_BMP_BJ);
	pen.CreatePen(PS_SOLID, 1, 0xff);
	MemDC.SelectObject(&bmp);
	MemDC.SelectObject(&pen);
	MemDC.SetROP2(R2_NOTXORPEN);
	CString ysStr;//�����ַ���������ʾ��Ϸʱ�䣬�÷֣��ȼ�
	MemDC.SetBkMode(TRANSPARENT);//�������屳��
	MemDC.SetTextColor(67);//����������ɫ����ʼ���ַ���
	ysStr.Format("��ǰ�÷�:%d", m_nScore);
	MemDC.TextOut(30, 50, ysStr);
//�����������������������ݵȼ��жϡ�������������������//
	switch (m_nLevel)
	{
	case GAME_LEVEL_LOW:
		ysStr.Format("��ǰ�ȼ�������");
		break;
	case GAME_LEVEL_NOR:
		ysStr.Format("��ǰ�ȼ����м�");
		break;
	case GAME_LEVEL_HIGH:
		ysStr.Format("��ǰ�ȼ����߼�");
		break;

	default:
		ysStr.Format("��ǰ�ȼ���ʾ����");
		break;
	}
	MemDC.TextOut(30, 30, ysStr);//����ַ�
 //�������������������������ߵ���ʽ��������������������//
	CPen yspen;//�����ɫ���ʻ����ߵı߿�
	yspen.CreatePen(1, 1, RGB(255, 255, 255));
	MemDC.SelectObject(&yspen);

	CBrush ysbrush;
	int k = m_Body.GetUpperBound() + 2;//����һ�������洢̰���ߵ����峤��
	if (k < 10)
	{
		ysbrush.CreateSolidBrush(RGB(0, 255, 0));//���k<10Ϊ�棬��ô̰���߾�Ϊ��ɫ
		MemDC.SelectObject(&ysbrush);
		//------���ƹ�ʵ------//
		MemDC.Rectangle(
			CRect(10 + m_psFood.y * 10, 
			120 + m_psFood.x * 10, 
			10 + (m_psFood.y + 1) * 10, 
			120 + (m_psFood.x + 1) * 10)
			);

	}
	else if (k>10&&k<20)
	{
		ysbrush.CreateSolidBrush(RGB(0, 0, 255));//���k>10��k<20Ϊ�棬��ô̰���߾�Ϊ��ɫ
		MemDC.SelectObject(&ysbrush);
		//------���ƹ�ʵ------//
		MemDC.Rectangle(
			CRect(10 + m_psFood.y * 10,
			120 + m_psFood.x * 10,
			10 + (m_psFood.y + 1) * 10,
			120 + (m_psFood.x + 1) * 10)
			);
	}
	else if (k>20&&k<30)
	{
		ysbrush.CreateSolidBrush(RGB(255, 255, 0));//���k>20��k<30Ϊ�棬��ô̰���߾�Ϊ��ɫ
		MemDC.SelectObject(&ysbrush);
		//------���ƹ�ʵ------//
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
		//------���ƹ�ʵ------//
		MemDC.Rectangle(
			CRect(10+m_psFood.y*10,
			120+m_psFood.x*10,
			10 + (m_psFood.y+1)*10,
			120 + (m_psFood.x+1)*10)
			);
	}
	//---------------��ʼ��������---------------//
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
	// ��Ϊ��ͼ��Ϣ���� CWnd::OnPaint()
}


void CSnakeGame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
			AfxMessageBox("��Ϸ���������ķ���̫��û�ܽ���Ӣ�۰�");
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nChar)
	{
	case VK_UP://�����ϼ�
		m_nDirect = DIREC_UP;//���Ʒ�������Ϊ DIREC_UP
		break;	
	case VK_DOWN://�����¼�
		m_nDirect = DIREC_DOWN;//���Ʒ�������ΪDIREC_DOWN
		break;
	case VK_LEFT://�������
		m_nDirect = DIREC_LEFT;//���Ʒ�������ΪDIREC_LEFT
		break;
	case VK_RIGHT://�����Ҽ�
		m_nDirect = DIREC_RIGHT;//���Ʒ�������ΪDIREC_RIGHT
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

//------------------��ʼ����Ϸ------------------//
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