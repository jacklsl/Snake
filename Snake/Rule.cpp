#include "stdafx.h"
#include "Rule.h"


CRule::CRule()
{
}


CRule::~CRule()
{
}

BOOL CRule::IsOver(CPoint &pt, CArray<CPoint, CPoint>&body)
{
	if (pt.x >= MAX_POINT || pt.x<MIN_POINT)                 //���������������¶˱߿�����������϶˱߿�
	{
		return TRUE;                      //�ж�����
	}
	else if (pt.y >= MAX_POINT || pt.y<MIN_POINT)           //������������Ҷ˱߿�
	{
		return TRUE;                      //�ж�����
	}

	for (int i = 0; i <= body.GetUpperBound(); i++)
	{
		CPoint pt1 = body.GetAt(i);     //������������괫�ݸ��¶���ĵ�
		if (pt.x == pt1.x&&pt.y == pt1.y)	  //���������ȫ��ͬ,˵������������
		{
			return TRUE;				  //�ж�����
		}
	}

	return FALSE;
}