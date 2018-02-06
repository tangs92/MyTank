#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Graphic.h"
#include <list>

enum Dir {UP,DOWN,LEFT,RIGHT};

class Object
{
public:
	virtual void Display() = 0;//绘图
	virtual void Move() = 0;//移动
	virtual bool IsDisappear() = 0;//是否消失
	virtual void SetDisappear() = 0;//让它消失
	virtual void Boom(std::list<Object*>&lstBooms) = 0;// 爆炸
	virtual Rect GetSphere() = 0;//返回势力范围
protected:
	virtual void CalculateSphere() = 0;//计算势力范围

	Point m_pos;//位置
	Rect m_rectSphere;//势力范围
	COLORREF m_color;//颜色
	Dir m_dir;//方向
	bool m_bDisappear;//存在状态
	int m_step;//移动速度
	bool m_bNeedShoot;//能射击吗
};












#endif