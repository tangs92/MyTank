#ifndef __TANK_H__
#define __TANK_H__

#include "Graphic.h"
#include "Point.h"
#include "Rect.h"
#include "Object.h"
#include "Bullet.h"
#include "Bomb.h"
#include <list>
enum SHOOT_TYPE {DEF,M2E,E2M};
class Tank :public Object
{
public:

	Tank()
	{
		m_pos.Set(300, 300);
		this->CalculateSphere();
		m_color = YELLOW;
		m_dir = Dir::UP;
		m_step = 4;
		m_bDisappear = false;
		
	}
	~Tank() {}
	void Boom(std::list<Object*>&lstBooms)
	{
		lstBooms.push_back(new Bomb(m_pos, LARGE));
	}
	void Display() {}//画
	void Move() {}//移动
	void Shoot(std::list<Object*>& lstBullets)//射击
	{
		//需要实现的开炮方法其实是在传入的列表中加入新的炮弹信息即可
	}
	Rect GetSphere()
	{
		return m_rectSphere;
	}
	bool IsDisappear()//返回显示状态
	{
		return m_bDisappear;
	}

	void SetDisappear()//设置消失
	{
		m_bDisappear = true;
	}

	bool NeedShoot()//允许射击吗
	{
		return m_bNeedShoot;
	}

protected:
	void CalculateSphere() 
	{

	}

	

	/*
	我们把坐标用Point对象m_pos表示，
	又添加了一个新属性m_rectSphere，
	它是一个Rect对象，用来记录坦克的形状范围。
	之前我们的坦克总是用一组坐标来表示，这个坐标是坦克的中心点，
	所有跟坦克相关的行为都通过这个点来计算位置，实现起来有些复杂，有了这个Rect对象，
	相当于我们记录了这个坦克所在的矩形的位置，这样在绘制坦克时更容易计算坐标
	*/

	//Point m_pos;  //坐标
	//Rect  m_rectSphere;//势力范围

	////int m_x;//x坐标
	////int m_y;//y坐标
	//COLORREF m_color;//坦克的颜色

	//Dir m_dir;//坦克的方向
	//int m_step;//单位移动距离
};






#endif