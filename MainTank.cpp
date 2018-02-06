#include "MainTank.h"

void MainTank::SetDir(Dir dir)
{
	m_dir = dir;
}

void MainTank::Display()
{
	COLORREF color_save = getfillcolor();//填充颜色
	COLORREF fill_color_save = getcolor();//边框颜色

	setfillcolor(m_color);
	setcolor(fill_color_save);
	DrawTankBody();

	//根据方向画炮管
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
	setfillcolor(fill_color_save);//恢复原来的颜色
}

void MainTank::Move()
{
	//根据移动方向,计算坐标
	//超过战场边缘就不能继续往前走了
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

	CalculateSphere();//重新计算坦克区域
}

void MainTank::Shoot(std::list<Object*>& lstBullets)
{
	/*
	创建一个新的炮弹添加到传入的list中即可。
	创建炮弹时，我们将坦克自身的属性传给炮弹对象
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
	这里的设计可以上下/左右各用一套算式算出坐标
	中心点坐标是会变的,然后区域左上角,右下角坐标是以中心点来计算的
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
这个函数的参数被拿掉了，
在这里我们通过坦克当前方向来判断它的形状。
在绘制履带时，我们利用了m_rectSphere的位置坐标，
虽然看起来代码变多了，但只有一个数字4是无意义的，
它代表履带的宽度。如果这个宽度需要经常调整的话，
我们还可以考虑把它用一个成员变量管理起来。
*/
//void fillrectangle (int left, int top, int right, int bottom);
/*
left
矩形左部 x 坐标。

top
矩形上部 y 坐标。

right
矩形右部 x 坐标。

bottom
矩形下部 y 坐标。
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
