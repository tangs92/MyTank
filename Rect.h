#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Point.h"
//定义矩形
class Rect
{
public:
	Rect(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) :m_startPoint(x1, y1), m_endPoint(x2, y2) {};
	Rect(const Point p1, const Point p2) :m_startPoint(p1), m_endPoint(p2) {}

	~Rect() {}
	Rect& operator=(const Rect &rhs)
	{
		m_startPoint = rhs.GetStartPoint();
		m_endPoint = rhs.GetEndPoint();
		return *this;
	}
	void Set(const Point pStart, const Point pEnd);
	void Set(int x1, int y1, int x2, int y2);

	Point GetStartPoint() const { return m_startPoint; }//m_startPoint表示左上角
	Point GetEndPoint() const { return m_endPoint; }//m_endPoint表示右下角

	//Point& GetStartPoint()  { return m_startPoint; }//m_startPoint表示左上角
	//Point& GetEndPoint()  { return m_endPoint; }//m_endPoint表示右下角


	void SetStartPoint(const Point p);
	void SetEndPoint(const Point p);

	int GetWidth();
	int GetHeight();

	//Point GetTRPoint() const ;//返回右上点
	//Point GetBLPoint()const;//返回左上点

	Point GetTRPoint() ;//返回右上点
	Point GetBLPoint();//返回左上点
private:
	void check();//检测坐标的合法性,开始比结束大,两个颠倒一下
	//m_startPoint表示左上角，m_endPoint表示右下角
	Point m_startPoint;//m_startPoint表示左上角
	Point m_endPoint;//m_endPoint表示右下角
};

#endif