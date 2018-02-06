#ifndef __BOMB_H__
#define __BOMB_H__

#include "Object.h"
#define BOMB_LARGE 20
#define BOMB_SAMLL 10
//±¨’®µƒ÷÷¿‡
enum BombType
{
	LARGE,
	SMALL
};
class Bomb :public Object
{
public:
	Bomb();
	Bomb(Point pos, BombType type);
	~Bomb() {}

	void Display();
	void Move();
	void Boom(std::list<Object*>&lstBooms);
	bool IsDisappear();
	Rect GetSphere()
	{
		return m_rectSphere;
	}
	void SetDisappear()
	{
		m_bDisappear = true;
	}

protected:
	void CalculateSphere();
	BombType m_type;
	int m_timer;

};

#endif