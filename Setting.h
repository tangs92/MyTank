#pragma once
#include <list>
using namespace std;

#define MAX_ENEMYS  10

//��λ����
#define KEY_UP		72
#define KEY_DOWN	80
#define KEY_LEFT	75
#define KEY_RIGHT	77
#define KEY_UP_H	224
#define KEY_ESC		27
#define KEY_SPACE	32
#define KEY_ENTER	13

class Setting
{
public:

	static void NewGameLevel();
	static void TankDamaged();
	static void MainTankDie();
	static int GetLife()
	{
		return m_nLife;
	}

	static int GetGameLevel()
	{
		return m_nGameLevel;
	}

	static int GetTankLevel()
	{
		return m_nTankLevel;
	}

	static int GetSumScore()
	{
		return m_nSumScore;
	}

	static int GetTankSum()
	{
		return m_nTankSum;
	}

	static int GetTankNum()
	{
		return m_nTankNum;
	}
	
	static bool m_bNewLevel;

	static void AddLife()
	{
		if(m_nGameLevel%2==0)
			m_nLife = m_nLife + 2;
	}
private:
	static int m_nLife;//����ֵ
	static int m_nGameLevel;//��ǰ��Ϸ�ؿ�
	static int m_nTankLevel;//��ǰ̹�˼���

	static int m_nTankNum;//��ǰ̹����

	static int m_nSumScore;//�ܷ�
	static int  m_nTankScore;//����̹�˵÷�
	static int m_nTankSum;//����̹����
};

