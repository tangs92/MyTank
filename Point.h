#ifndef __POINT_H__
#define __POINT_H__
//∂®“Âµ„
class Point
{
public:

	Point(int x = 0, int y = 0) :m_x(x), m_y(y) {}

	~Point() {}

	Point& operator=(const Point &rhs)
	{
		m_x = rhs.m_x;
		m_y = rhs.m_y;
		return *this;
	}
	void Set(int x, int y);
	void SetX(int x);
	void SetY(int y);

	int GetX();
	int GetY();
private:
	int m_x;
	int m_y;
};










#endif

