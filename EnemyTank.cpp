#include "EnemyTank.h"

void EnemyTank::Display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	setfillcolor(m_color);
	setcolor(m_color);

	fillrectangle(m_pos.GetX() - 6, m_pos.GetY() - 6, m_pos.GetX() + 6, m_pos.GetY() + 6);

	fillrectangle(m_rectSphere.GetStartPoint().GetX(), m_rectSphere.GetStartPoint().GetY(),
		m_rectSphere.GetStartPoint().GetX() + 4, m_rectSphere.GetStartPoint().GetY() + 4);
	fillrectangle(m_rectSphere.GetEndPoint().GetX() - 4, m_rectSphere.GetStartPoint().GetY(),
		m_rectSphere.GetEndPoint().GetX(), m_rectSphere.GetStartPoint().GetY() + 4);

	fillrectangle(m_rectSphere.GetStartPoint().GetX(), m_rectSphere.GetEndPoint().GetY() - 4,
		m_rectSphere.GetStartPoint().GetX() + 4, m_rectSphere.GetEndPoint().GetY());
	fillrectangle(m_rectSphere.GetEndPoint().GetX() - 4, m_rectSphere.GetEndPoint().GetY() - 4,
		m_rectSphere.GetEndPoint().GetX(), m_rectSphere.GetEndPoint().GetY());

	switch (m_dir)
	{
	case UP:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX(), m_pos.GetY() - 15);
		break;
	case DOWN:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX(), m_pos.GetY() + 15);
		break;
	case LEFT:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX() - 15, m_pos.GetY());
		break;
	case RIGHT:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX() + 15, m_pos.GetY());
		break;
	default:
		break;
	}

	setcolor(color_save);
	setfillcolor(fill_color_save);
}

void EnemyTank::Move()
{
	switch (m_dir)
	{
	case UP:
		m_pos.SetY(m_pos.GetY() - m_step);
		//如果矩形范围的Y轴坐标<战场边缘的Y轴坐标的话
		if (m_rectSphere.GetStartPoint().GetY() < Graphic::GetBattleGround().GetStartPoint().GetY())
		{
			m_pos.SetY(m_pos.GetY() + m_step);//让Y轴坐标往远离边缘的地方移动
			this->RamdomDir(1);//随机产生一个与当前方向不一样的随机方向
			this->RamdomSpeed(1);
		}
		break;
	case DOWN:
		m_pos.SetY(m_pos.GetY() + m_step);
		if (m_rectSphere.GetEndPoint().GetY() > Graphic::GetBattleGround().GetEndPoint().GetY())
		{
			m_pos.SetY(m_pos.GetY() - m_step); this->RamdomDir(1); this->RamdomSpeed(1);
		}
		break;
	case LEFT:
		m_pos.SetX(m_pos.GetX() - m_step);
		if (m_rectSphere.GetStartPoint().GetX() < Graphic::GetBattleGround().GetStartPoint().GetX())
		{
			m_pos.SetX(m_pos.GetX() + m_step); this->RamdomDir(1); this->RamdomSpeed(1);
		}
		break;
	case RIGHT:
		m_pos.SetX(m_pos.GetX() + m_step);
		if (m_rectSphere.GetEndPoint().GetX() > Graphic::GetBattleGround().GetEndPoint().GetX())
		{
			m_pos.SetX(m_pos.GetX() - m_step); this->RamdomDir(1); this->RamdomSpeed(1);
		}
		break;
	default:
		break;
	}

	//超过10步就随机换方向
	m_stepCnt++;
	if (m_stepCnt >= MAX_STEP)
	{
		m_stepCnt = 0;
		this->RamdomDir(0);
		this->RamdomSpeed(0);
	}
	//超过20步就开炮
	if (m_stepCnt % MAX_STEP_SHOOT == 0)
	{
		m_bNeedShoot = true;
	}
	else
	{
		m_bNeedShoot = false;
	}
	CalculateSphere();

}

void EnemyTank::Boom(std::list<Object*>& lstBooms)
{
	lstBooms.push_back(new Bomb(m_pos, LARGE));
}



void EnemyTank::CalculateSphere()
{
	switch (m_dir)
	{
	case UP:
	case DOWN:
		m_rectSphere.Set(m_pos.GetX() - 13, m_pos.GetY() - 10, m_pos.GetX() + 13, m_pos.GetY() + 10);
		break;
	case LEFT:
	case RIGHT:
		m_rectSphere.Set(m_pos.GetX() - 10, m_pos.GetY() - 13, m_pos.GetX() + 10, m_pos.GetY() + 13);
		break;
	default:
		break;
	}
}

void EnemyTank::RandomTank()
{
	//随机生成合法的XY坐标
	auto tmpX = rand() % Graphic::GetBattleGround().GetWidth();
	auto tmpY = rand() % Graphic::GetBattleGround().GetHeight();



	m_pos.SetX(tmpX);
	m_pos.SetY(tmpY);

	m_color = GREEN;
	m_dir = (Dir)(Dir::UP + (rand() % 4));
	m_step =Setting::GetTankLevel()*2;
	m_stepCnt = rand() % MAX_STEP;
	//初始化变量的时候为m_stepCnt随机产生一个当前步数
	//如果每个坦克的当前步数相同的话，那么到第十歩的时候所有的坦克会集体转向

}

void EnemyTank::RamdomDir(int type)
{
	if (type == 1)
	{
		Dir dir;
		while ((dir = (Dir)(Dir::UP + (rand() % 4))) == m_dir) {}
		//随机生成一个与现在方向不一样的方向
		m_dir = dir;
	}
	else
	{
		m_dir = (Dir)(Dir::UP + (rand() % 4));
	}
}

void EnemyTank::RamdomSpeed(int type)
{
	//if (type == 1)
	//{
	//	int speed;
	//	while ((speed = (rand() % MAX_SPEED+1)) != m_step)
	//	{
	//		;
	//	}
	//	m_step = speed;
	//}
	//else
	//{
	//	m_step = rand() % MAX_SPEED+1;
	//}
}


