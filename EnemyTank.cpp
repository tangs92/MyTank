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
		//������η�Χ��Y������<ս����Ե��Y������Ļ�
		if (m_rectSphere.GetStartPoint().GetY() < Graphic::GetBattleGround().GetStartPoint().GetY())
		{
			m_pos.SetY(m_pos.GetY() + m_step);//��Y��������Զ���Ե�ĵط��ƶ�
			this->RamdomDir(1);//�������һ���뵱ǰ����һ�����������
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

	//����10�������������
	m_stepCnt++;
	if (m_stepCnt >= MAX_STEP)
	{
		m_stepCnt = 0;
		this->RamdomDir(0);
		this->RamdomSpeed(0);
	}
	//����20���Ϳ���
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
	//������ɺϷ���XY����
	auto tmpX = rand() % Graphic::GetBattleGround().GetWidth();
	auto tmpY = rand() % Graphic::GetBattleGround().GetHeight();



	m_pos.SetX(tmpX);
	m_pos.SetY(tmpY);

	m_color = GREEN;
	m_dir = (Dir)(Dir::UP + (rand() % 4));
	m_step =Setting::GetTankLevel()*2;
	m_stepCnt = rand() % MAX_STEP;
	//��ʼ��������ʱ��Ϊm_stepCnt�������һ����ǰ����
	//���ÿ��̹�˵ĵ�ǰ������ͬ�Ļ�����ô����ʮ�i��ʱ�����е�̹�˻Ἧ��ת��

}

void EnemyTank::RamdomDir(int type)
{
	if (type == 1)
	{
		Dir dir;
		while ((dir = (Dir)(Dir::UP + (rand() % 4))) == m_dir) {}
		//�������һ�������ڷ���һ���ķ���
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


