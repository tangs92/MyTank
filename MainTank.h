#ifndef __MAIN_TANK__
#define __MAIN_TANK__

#include "Tank.h"
#include "Setting.h"
//主战坦克
class MainTank :public Tank
{
public:
	MainTank()//构造函数
	{
		m_pos.Set(300, 400);//设置坦克的中心点
		this->CalculateSphere();
		m_color = YELLOW;
		m_dir = Dir::UP;
		m_step = 5;
		
	}

	~MainTank() {}

	void SetDir(Dir dir);//设置行驶方向
	void Display() override;
	void Move() override;//移动
	void Shoot(std::list<Object*>& lstBullets);
	void Boom(std::list<Object*>&lstBooms);
	Rect GetSphere()
	{
		return m_rectSphere;
	}
	void SetDisappear(bool flag)
	{
		m_bDisappear = flag;
	}

protected:
	void CalculateSphere();//计算出矩形位置
	void DrawTankBody();//画坦克
};





#endif