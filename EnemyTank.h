#pragma once

#include "Tank.h"
#include "Time.h"
#include "Bullet.h"
#include "Setting.h"
#define MAX_STEP 10//����������ʻ����,�������л�����
#define MAX_SPEED 8//����̹�˵�����ٶ�
#define MAX_STEP_SHOOT 20
class EnemyTank :public Tank
{

public:
	EnemyTank()//�о�̹�˹��캯��
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
	//����
	void Shoot(std::list<Object*>& lstBullets)
	{
		Bullet * pBullet = new Bullet(m_pos, m_dir, RED);
		lstBullets.push_back(pBullet);
		m_bNeedShoot = false;
	}
protected:
	void CalculateSphere();
	void RandomTank();//������ɵз�̹�˵Ĳ���
	void RamdomDir(int type);//�������̹�˵ķ���
	//1  �·�������ԭ����һ��
	//2 ����һ���·���

	//�������̹�˵��ٶ�
	void RamdomSpeed(int type);
	//1  ���ٶȱ����ԭ����һ��
	//2 ����һ�����ٶ�
	int m_stepCnt;//������¼̹�˵�ǰ��ʻ�Ĳ���
};

