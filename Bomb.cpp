#include "Bomb.h"



Bomb::Bomb()
{
	this->m_bDisappear = false;
	this->m_color = YELLOW;
	this->m_dir = UP;
	this->m_timer = 0;
}

Bomb::Bomb(Point pos, BombType type) : Bomb()
{
	this->m_pos = pos;
	this->m_type = type;
	switch (m_type)
	{
	case LARGE:
		m_timer = BOMB_LARGE;
		break;
	case SMALL:
		m_timer = BOMB_SAMLL;
		break;
	default:
		break;

	}

}

void Bomb::Display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	setfillcolor(m_color);
	setcolor(RED);

	fillcircle(m_pos.GetX(), m_pos.GetY(), 8 - m_timer);
	setcolor(color_save);
	setfillcolor(fill_color_save);
}

void Bomb::Move()
{
	m_timer -= 5;
	if (m_timer < 0)
	{
		m_bDisappear = true;//炮弹时间到，动画完毕
	}
}

void Bomb::Boom(std::list<Object*>& lstBooms)
{
}



bool Bomb::IsDisappear()
{
	return m_bDisappear;
}

void Bomb::CalculateSphere()
{
}
