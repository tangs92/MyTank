#pragma once
#ifndef __BULLET_H__
#define __BULLET_H__

#include "Object.h"
#define BULLET_DISAPPEAR BULLET_SPEED*15
#define  BULLET_SPEED 20

class Bullet :public Object
{
public:
	Bullet();
	Bullet(Point pos, Dir dir, COLORREF color);
	~Bullet();

	void Display();
	void Move();
	bool IsDisappear()
	{
		return m_bDisappear;
	}
	void SetDisappear()
	{
		m_bDisappear = true;
	}
	void Boom(std::list<Object*>&lstBooms);
	Rect GetSphere()
	{
		return m_rectSphere;
	}
protected:
	void CalculateSphere();
	int m_stepCnt;//记录炮弹走过的距离


};



#endif
