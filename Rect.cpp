#include "Rect.h"


void Rect::Set(const Point pStart, const Point pEnd)
{
	m_startPoint = pStart;
	m_endPoint = pEnd;
}

void Rect::Set(int x1, int y1, int x2, int y2)
{
	m_startPoint.Set(x1, y1);
	m_endPoint.Set(x2, y2);
}

void Rect::SetStartPoint(const Point p)
{
	m_startPoint = p;
}

void Rect::SetEndPoint(const Point p)
{
	m_endPoint = p;
}

int Rect::GetWidth()
{
	return m_endPoint.GetX() - m_startPoint.GetX();
}

int Rect::GetHeight()
{
	return m_endPoint.GetY()- m_startPoint.GetY();
}

 Point Rect::GetTRPoint()
{
	Point p = m_startPoint;//取得左上角的Y
	p.SetX(m_endPoint.GetX());//取得右上角的X，赋值给p
	return p;
}

 Point Rect::GetBLPoint()
{
	Point p = m_startPoint;//取得左上角的X
	p.SetY(m_endPoint.GetY());//取得右上角的Y，赋值给p
	return p;
}


void Rect::check()
{
	if (m_startPoint.GetX() > m_endPoint.GetX() || m_startPoint.GetY() > m_endPoint.GetY())
	{
		Point tmp = m_startPoint;
		m_startPoint = m_endPoint;
		m_endPoint = tmp;
	}
}
