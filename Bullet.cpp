#include "Bullet.h"
#include "Bomb.h"
Bullet::Bullet()
{

}
Bullet::~Bullet() 
{

}

Bullet::Bullet(Point pos, Dir dir, COLORREF color)
{
	m_pos = pos;
	m_dir = dir;
	m_color = color;
	m_stepCnt = 0;

	m_step = BULLET_SPEED;
	m_bDisappear = false;
	CalculateSphere();
}


void Bullet::Display()
{
	//用炮弹的位置和颜色填充一个圆形的炮弹
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	setfillcolor(m_color);
	setcolor(m_color);

	fillcircle(m_pos.GetX() - 1, m_pos.GetY() - 1, 4);

	setcolor(color_save);
	setfillcolor(fill_color_save);
}


void Bullet::Move()
{

	switch (m_dir)
	{
	case UP:
		m_pos.SetY(m_pos.GetY() - m_step);
		CalculateSphere();
		if (m_rectSphere.GetStartPoint().GetY() < Graphic::GetBattleGround().GetStartPoint().GetY())
		{
			m_pos.SetY(Graphic::GetBattleGround().GetStartPoint().GetY());
			m_bDisappear = true;
		}
		break;
	case DOWN:
		m_pos.SetY(m_pos.GetY() + m_step);
		CalculateSphere();
		if (m_rectSphere.GetEndPoint().GetY() > Graphic::GetBattleGround().GetEndPoint().GetY())
		{
			//强制把子弹的坐标设置在边缘
			m_pos.SetY(Graphic::GetBattleGround().GetEndPoint().GetY());
			m_bDisappear = true;
		}
		break;
	case LEFT:
		m_pos.SetX(m_pos.GetX() - m_step);
		CalculateSphere();
		if (m_rectSphere.GetStartPoint().GetX() < Graphic::GetBattleGround().GetStartPoint().GetX())
		{
			m_pos.SetX(Graphic::GetBattleGround().GetStartPoint().GetX());
			m_bDisappear = true;
		}
		break;
	case RIGHT:
		m_pos.SetX(m_pos.GetX() + m_step);
		CalculateSphere();
		if (m_rectSphere.GetEndPoint().GetX() > Graphic::GetBattleGround().GetEndPoint().GetX())
		{
			m_pos.SetX(Graphic::GetBattleGround().GetEndPoint().GetX());
			m_bDisappear = true;
		}
		break;
	default:
		break;
	}


	//如果炮弹射出后超过一定距离就就消失了
	if (m_stepCnt < BULLET_DISAPPEAR)
	{
		m_stepCnt = m_stepCnt + BULLET_SPEED;
	}
	else
	{
		m_stepCnt = 0;
		m_bDisappear = true;
	}
}


void Bullet::Boom(std::list<Object*>& lstBooms)
{
	lstBooms.push_back(new Bomb(m_pos, SMALL));
}

void Bullet::CalculateSphere()
{
	m_rectSphere.Set(m_pos.GetX() - 2, m_pos.GetY() - 2, m_pos.GetX() + 2, m_pos.GetY() + 2);
}

