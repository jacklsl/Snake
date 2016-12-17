#pragma once


// CSnakeGame
#include"Afxtempl.h"//����ģ��ͷ�ļ�
#define GAME_LEVEL_LOW 2//������ֺ�
#define GAME_LEVEL_NOR 4
#define GAME_LEVEL_HIGH 8

#define DIREC_UP 1//���ϵı�־
#define DIREC_DOWN 2//���µı�־
#define DIREC_RIGHT 3//���ҵı�־
#define DIREC_LEFT 4//����ı�־

#define LOW_LEVEL_SLEEP 100
#define NOR_LEVEL_SLEEP 50
#define HIGH_LEVEL_SLEEP 30

class CSnakeGame : public CWnd
{
	DECLARE_DYNAMIC(CSnakeGame)


public:
	void HeroWrite();//����Ӣ�۰�д��
	void ReDrawBody(CPoint pt);//�ػ�һ����
	void InitGame();//��ʼ����Ϸ


	CSnakeGame();//���캯��
	virtual ~CSnakeGame();//��������
	BOOL GameStart();//��Ϸ��ʼ����
	void InitFoods();//��ʼ����ʵ����
	void SetGameLevel(int level);//������Ϸ�ȼ�
private:
	CPoint m_psFood;//��ǰʳ������
	int m_nDirect;//��ǰ��ǰ������
	int m_nScore;//��ǰ��Ϸ����
	int m_nLevel;//��ǰ��Ϸ�ȼ�
	int m_nHighScore;//��ǰ��Ϸ��߷�
	CArray<CPoint, CPoint>m_Body;//��������
protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};


