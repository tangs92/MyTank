#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Point.h"
//�������
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

	Point GetStartPoint() const { return m_startPoint; }//m_startPoint��ʾ���Ͻ�
	Point GetEndPoint() const { return m_endPoint; }//m_endPoint��ʾ���½�

	//Point& GetStartPoint()  { return m_startPoint; }//m_startPoint��ʾ���Ͻ�
	//Point& GetEndPoint()  { return m_endPoint; }//m_endPoint��ʾ���½�


	void SetStartPoint(const Point p);
	void SetEndPoint(const Point p);

	int GetWidth();
	int GetHeight();

	//Point GetTRPoint() const ;//�������ϵ�
	//Point GetBLPoint()const;//�������ϵ�

	Point GetTRPoint() ;//�������ϵ�
	Point GetBLPoint();//�������ϵ�
private:
	void check();//�������ĺϷ���,��ʼ�Ƚ�����,�����ߵ�һ��
	//m_startPoint��ʾ���Ͻǣ�m_endPoint��ʾ���½�
	Point m_startPoint;//m_startPoint��ʾ���Ͻ�
	Point m_endPoint;//m_endPoint��ʾ���½�
};

#endif