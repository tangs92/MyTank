#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Graphic.h"
#include <list>

enum Dir {UP,DOWN,LEFT,RIGHT};

class Object
{
public:
	virtual void Display() = 0;//��ͼ
	virtual void Move() = 0;//�ƶ�
	virtual bool IsDisappear() = 0;//�Ƿ���ʧ
	virtual void SetDisappear() = 0;//������ʧ
	virtual void Boom(std::list<Object*>&lstBooms) = 0;// ��ը
	virtual Rect GetSphere() = 0;//����������Χ
protected:
	virtual void CalculateSphere() = 0;//����������Χ

	Point m_pos;//λ��
	Rect m_rectSphere;//������Χ
	COLORREF m_color;//��ɫ
	Dir m_dir;//����
	bool m_bDisappear;//����״̬
	int m_step;//�ƶ��ٶ�
	bool m_bNeedShoot;//�������
};












#endif