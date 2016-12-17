#pragma once
#include<afxtempl.h>
#define MAX_POINT 29
#define MIN_POINT 0
class CRule
{
public:
	CRule();
	~CRule();
	BOOL IsOver(CPoint &pt, CArray<CPoint, CPoint>&body);
};

