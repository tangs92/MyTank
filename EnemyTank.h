#pragma once

#include "Tank.h"
#include "Time.h"
#include "Bullet.h"
#include "Setting.h"
#define MAX_STEP 10//定义最大的行驶步数,超过就切换方向
#define MAX_SPEED 8//定义坦克的最大速度
#define MAX_STEP_SHOOT 20
class EnemyTank :public Tank
{

public:
	EnemyTank()//敌军坦克构造函数
	{
		RandomTank();
	}
	~EnemyTank() {}
	void Display();
	void Move();
	void Boom(std::list<Object*>&lstBooms);
	Rect GetSphere()
	{
		return m_rectSphere;
	}
	void SetDisappear()
	{
		m_bDisappear = true;
	}
	//开炮
	void Shoot(std::list<Object*>& lstBullets)
	{
		Bullet * pBullet = new Bullet(m_pos, m_dir, RED);
		lstBullets.push_back(pBullet);
		m_bNeedShoot = false;
	}
protected:
	void CalculateSphere();
	void RandomTank();//随机生成敌方坦克的参数
	void RamdomDir(int type);//随机生成坦克的方向
	//1  新方向必须和原方向不一样
	//2 任意一个新方向

	//随机生成坦克的速度
	void RamdomSpeed(int type);
	//1  新速度必须和原方向不一样
	//2 任意一个新速度
	int m_stepCnt;//用来记录坦克当前行驶的步数
};

