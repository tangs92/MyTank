#pragma once
#include "Rect.h"
class Shape
{
public:
	static bool CheckPointInRect(Point * point, Rect & rect);//判断一个点是否在一个矩形的范围中
	static bool CheckIntersect(Rect * rectA, Rect* rectB);//判断两个矩形是否重合
};

