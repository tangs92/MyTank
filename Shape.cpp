#include "Shape.h"



bool Shape::CheckPointInRect(Point * point, Rect & rect)
{
	if (
		(point->GetX() < rect.GetStartPoint().GetX()) ||
		(point->GetX() > rect.GetEndPoint().GetX())   ||
		(point->GetY() < rect.GetStartPoint().GetY()) ||
		(point->GetY() > rect.GetEndPoint().GetY())
		)
	{
		return false;//点不在矩形范围之内
	}
	else
	{
		return true;//点在矩形范围之内
	}
}

bool Shape::CheckIntersect(Rect* rectA, Rect * rectB)
{
	if (
		(CheckPointInRect(&(rectA->GetStartPoint()),*rectB)) ||
		(CheckPointInRect(&(rectA->GetEndPoint()), *rectB)) ||
		(CheckPointInRect(&(rectA->GetTRPoint()), *rectB)) ||
		(CheckPointInRect(&(rectA->GetBLPoint()), *rectB))
		)
	{
		return true;//两个矩形重合了
	}
	else
	{
		return false;//两个矩形未重合
	}
}
