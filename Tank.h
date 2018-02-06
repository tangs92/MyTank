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
	void Display() {}//��
	void Move() {}//�ƶ�
	void Shoot(std::list<Object*>& lstBullets)//���
	{
		//��Ҫʵ�ֵĿ��ڷ�����ʵ���ڴ�����б��м����µ��ڵ���Ϣ����
	}
	Rect GetSphere()
	{
		return m_rectSphere;
	}
	bool IsDisappear()//������ʾ״̬
	{
		return m_bDisappear;
	}

	void SetDisappear()//������ʧ
	{
		m_bDisappear = true;
	}

	bool NeedShoot()//���������
	{
		return m_bNeedShoot;
	}

protected:
	void CalculateSphere() 
	{

	}

	

	/*
	���ǰ�������Point����m_pos��ʾ��
	�������һ��������m_rectSphere��
	����һ��Rect����������¼̹�˵���״��Χ��
	֮ǰ���ǵ�̹��������һ����������ʾ�����������̹�˵����ĵ㣬
	���и�̹����ص���Ϊ��ͨ�������������λ�ã�ʵ��������Щ���ӣ��������Rect����
	�൱�����Ǽ�¼�����̹�����ڵľ��ε�λ�ã������ڻ���̹��ʱ�����׼�������
	*/

	//Point m_pos;  //����
	//Rect  m_rectSphere;//������Χ

	////int m_x;//x����
	////int m_y;//y����
	//COLORREF m_color;//̹�˵���ɫ

	//Dir m_dir;//̹�˵ķ���
	//int m_step;//��λ�ƶ�����
};






#endif