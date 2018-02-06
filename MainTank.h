#ifndef __MAIN_TANK__
#define __MAIN_TANK__

#include "Tank.h"
#include "Setting.h"
//��ս̹��
class MainTank :public Tank
{
public:
	MainTank()//���캯��
	{
		m_pos.Set(300, 400);//����̹�˵����ĵ�
		this->CalculateSphere();
		m_color = YELLOW;
		m_dir = Dir::UP;
		m_step = 5;
		
	}

	~MainTank() {}

	void SetDir(Dir dir);//������ʻ����
	void Display() override;
	void Move() override;//�ƶ�
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
	void CalculateSphere();//���������λ��
	void DrawTankBody();//��̹��
};





#endif