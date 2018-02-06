#include "MainTank.h"

void MainTank::SetDir(Dir dir)
{
	m_dir = dir;
}

void MainTank::Display()
{
	COLORREF color_save = getfillcolor();//�����ɫ
	COLORREF fill_color_save = getcolor();//�߿���ɫ

	setfillcolor(m_color);
	setcolor(fill_color_save);
	DrawTankBody();

	//���ݷ����ڹ�
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
	setfillcolor(fill_color_save);//�ָ�ԭ������ɫ
}

void MainTank::Move()
{
	//�����ƶ�����,��������
	//����ս����Ե�Ͳ��ܼ�����ǰ����
	switch (m_dir)
	{
	case UP:
		m_pos.SetY(m_pos.GetY() - m_step);
		if (m_rectSphere.GetStartPoint().GetY() < Graphic::GetBattleGround().GetStartPoint().GetY())
		{
			m_pos.SetY(m_pos.GetY() + m_step);
			
		}
		break;
	case DOWN:
		m_pos.SetY(m_pos.GetY() + m_step);
		if (m_rectSphere.GetEndPoint().GetY() > Graphic::GetBattleGround().GetEndPoint().GetY())
		{
			m_pos.SetY(m_pos.GetY() - m_step);
		}
		break;
	case LEFT:
		m_pos.SetX(m_pos.GetX() - m_step);
		if (m_rectSphere.GetStartPoint().GetX() < Graphic::GetBattleGround().GetStartPoint().GetX())
		{
			m_pos.SetX(m_pos.GetX() + m_step);
		}
		break;
	case RIGHT:
		m_pos.SetX(m_pos.GetX() + m_step);
		if (m_rectSphere.GetEndPoint().GetX() > Graphic::GetBattleGround().GetEndPoint().GetX())
		{
			m_pos.SetX(m_pos.GetX() - m_step);
		}
		break;
	default:
		break;
	}

	CalculateSphere();//���¼���̹������
}

void MainTank::Shoot(std::list<Object*>& lstBullets)
{
	/*
	����һ���µ��ڵ���ӵ������list�м��ɡ�
	�����ڵ�ʱ�����ǽ�̹����������Դ����ڵ�����
	*/
	Bullet * pBullet = new Bullet(m_pos, m_dir, m_color);
	lstBullets.push_back(pBullet);
}

void MainTank::Boom(std::list<Object*>& lstBooms)
{
	lstBooms.push_back(new Bomb(m_pos, LARGE));
}

void MainTank::CalculateSphere()
{
	/*
	�������ƿ�������/���Ҹ���һ����ʽ�������
	���ĵ������ǻ���,Ȼ���������Ͻ�,���½������������ĵ��������
	*/
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

/*
��������Ĳ������õ��ˣ�
����������ͨ��̹�˵�ǰ�������ж�������״��
�ڻ����Ĵ�ʱ������������m_rectSphere��λ�����꣬
��Ȼ�������������ˣ���ֻ��һ������4��������ģ�
�������Ĵ��Ŀ�ȡ������������Ҫ���������Ļ���
���ǻ����Կ��ǰ�����һ����Ա��������������
*/
//void fillrectangle (int left, int top, int right, int bottom);
/*
left
������ x ���ꡣ

top
�����ϲ� y ���ꡣ

right
�����Ҳ� x ���ꡣ

bottom
�����²� y ���ꡣ
*/
void MainTank::DrawTankBody()
{
	fillrectangle(m_pos.GetX() - 6, m_pos.GetY() - 6, m_pos.GetX() + 6, m_pos.GetY() + 6);


	switch (m_dir)
	{
	case UP:
	case DOWN:
		fillrectangle(m_rectSphere.GetStartPoint().GetX(), m_rectSphere.GetStartPoint().GetY(),
			m_rectSphere.GetStartPoint().GetX() + 4, m_rectSphere.GetEndPoint().GetY());

		fillrectangle(m_rectSphere.GetEndPoint().GetX() - 4, m_rectSphere.GetStartPoint().GetY(),
			m_rectSphere.GetEndPoint().GetX(), m_rectSphere.GetEndPoint().GetY());
		break;
	case LEFT:
	case RIGHT:
		fillrectangle(m_rectSphere.GetStartPoint().GetX(), m_rectSphere.GetStartPoint().GetY(),
			m_rectSphere.GetEndPoint().GetX(), m_rectSphere.GetStartPoint().GetY() + 4);

		fillrectangle(m_rectSphere.GetStartPoint().GetX(), m_rectSphere.GetEndPoint().GetY() - 4,
			m_rectSphere.GetEndPoint().GetX(), m_rectSphere.GetEndPoint().GetY());
		break;
	default:
		break;
	}

}
