#pragma once
#include "Rect.h"
class Shape
{
public:
	static bool CheckPointInRect(Point * point, Rect & rect);//�ж�һ�����Ƿ���һ�����εķ�Χ��
	static bool CheckIntersect(Rect * rectA, Rect* rectB);//�ж����������Ƿ��غ�
};

