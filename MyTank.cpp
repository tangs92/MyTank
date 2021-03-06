
#pragma warning(disable:4996)

#include <iostream>
#include <conio.h>
#include <time.h>

#include "Graphic.h"
#include "MainTank.h"
#include "EnemyTank.h"
#include "Shape.h"
#include "Setting.h"


//敌方坦克list
std::list<Tank*> lstTanks;
//爆炸list
std::list<Object*> lstBombs;
//我的子弹list
std::list<Object*> mylstBullets;
//敌人的子弹list
std::list<Object*> EnemyslstBullets;

//主战坦克
MainTank mainTank;

bool loop = true;//游戏循环控制
bool skip = false;//游戏暂停控制

//退出前销毁
void Destroy()
{
	// Destroy
	for (auto it = lstTanks.begin(); it != lstTanks.end(); it++)
	{
		delete *it;
	}
	lstTanks.clear();

	for (auto it = EnemyslstBullets.begin(); it != EnemyslstBullets.end(); it++)
	{
		delete *it;
	}
	EnemyslstBullets.clear();

	for (auto it = mylstBullets.begin(); it != mylstBullets.end(); it++)
	{
		delete *it;
	}
	mylstBullets.clear();



	for (auto it = lstBombs.begin(); it != lstBombs.end(); it++)
	{
		delete *it;
	}
	lstBombs.clear();
	Graphic::Destroy();
}

//子弹移动显示
void BulletDisplay()
{
	//敌方子弹移动显示
	for (auto it = EnemyslstBullets.begin(); it != EnemyslstBullets.end(); )
	{
		(*it)->Move();
		if ((*it)->IsDisappear())
		{
			//爆炸效果
			(*it)->Boom(lstBombs);

			delete *it;
			it = EnemyslstBullets.erase(it);
			continue;
		}
		(*it)->Display();
		++it;
	}

	//我的子弹移动显示
	for (auto it = mylstBullets.begin(); it != mylstBullets.end(); )
	{
		(*it)->Move();
		if ((*it)->IsDisappear())
		{
			//爆炸效果
			(*it)->Boom(lstBombs);

			delete *it;
			it = mylstBullets.erase(it);
			continue;
		}
		(*it)->Display();
		++it;
	}

}

//爆炸显示
void BoomDisplay()
{
	//爆炸显示
	for (auto it = lstBombs.begin(); it != lstBombs.end();)
	{
		(*it)->Move();

		if ((*it)->IsDisappear())
		{
			delete *it;
			it = lstBombs.erase(it);
			continue;
		}

		(*it)->Display();
		it++;
	}
}

//坦克显示
void TankDisplay()
{
	mainTank.Move();
	mainTank.Display();

	//敌方坦克移动，显示
	for (auto it = lstTanks.begin(); it != lstTanks.end();)
	{
		(*it)->Move();

		//能射击吗
		if ((*it)->NeedShoot())
		{
			EnemyTank *p = (EnemyTank *)*it;
			p->Shoot(EnemyslstBullets);
		}

		//被击中了吗
		if ((*it)->IsDisappear())
		{
			// Add a bomb
			(*it)->Boom(lstBombs);

			// Delete the tank
			delete *it;
			it = lstTanks.erase(it);
			Setting::TankDamaged();

			continue;
		}

		(*it)->Display();

		it++;
	}

}

//初始化游戏
void InitPlay()
{
	srand((unsigned)time(NULL));
	//初始化画布
	Graphic::Create();

	//清除各种list
	lstTanks.clear();
	lstBombs.clear();
	mylstBullets.clear();
	EnemyslstBullets.clear();
	
	



}

//检查击中情况
void CheckCrash()
{
	//我射中敌人
	for (auto it = mylstBullets.begin(); it != mylstBullets.end(); ++it)
	{
		for (auto itt = lstTanks.begin(); itt != lstTanks.end(); ++itt)
		{
			if (Shape::CheckIntersect(&(*it)->GetSphere(), &(*itt)->GetSphere()))
			{
				(*itt)->SetDisappear();
				(*it)->SetDisappear();
			}

		}
		
	}

	//敌人打中我
	for (auto it = EnemyslstBullets.begin(); it != EnemyslstBullets.end(); ++it)
	{

 			if (Shape::CheckIntersect(&(*it)->GetSphere(),&mainTank.GetSphere()))
			{
				//检测如果自己被射中以后的问题
				Setting::MainTankDie();
				mainTank.Boom(lstBombs);
				mainTank.SetDisappear(true);
				Sleep(50);
				mainTank.SetDisappear(false);
			}
	}


}

bool CheckNewLevel()
{
	if (Setting::m_bNewLevel)
	{
		Setting::m_bNewLevel = false;

		Setting::NewGameLevel();
		Graphic::ShowGameLevel(Setting::GetGameLevel());
		//初始化敌方坦克
		for (int i = 0; i < Setting::GetTankNum(); i++)
		{
			lstTanks.push_back(new EnemyTank());
		}
		skip = true;
		return true;
	}
	return false;
}

inline bool CheckGameOver()
{
	//命用完了
	if (Setting::GetLife() == 0)
	{
		loop = false;
		cleardevice();
		Graphic::ShowInfo();
		Sleep(5000);
		return true;
	}
	return false;
}

inline void CheckEnemyNum()
{
	if (lstTanks.size() == 0)
	{
		Setting::m_bNewLevel = true;
	}
}
void Play()
{

	InitPlay();

	while (loop)
	{

		if (_kbhit())
		{
			int key = _getch();
			switch (key)
			{
				// Up
			case KEY_UP:
				mainTank.SetDir(Dir::UP);
				break;
				// Down
			case KEY_DOWN:
				mainTank.SetDir(Dir::DOWN);
				break;
				// Left
			case KEY_LEFT:
				mainTank.SetDir(Dir::LEFT);
				break;
				// Right
			case KEY_RIGHT:
				mainTank.SetDir(Dir::RIGHT);
				break;
			case KEY_UP_H: // 方向键高8位
				break;
				// Esc 程序退出
			case KEY_ESC:
				loop = false;
				break;
				// Space
			case KEY_SPACE:// Space
				mainTank.Shoot(mylstBullets);//打炮
				break;
				// Enter 程序暂停，再按一下程序继续
			case KEY_ENTER:
				if (skip)
					skip = false;
				else
					skip = true;
				break;
			default:
				break;
			}

		}
		if (!skip)//不暂停的话 
		{
			cleardevice(); //清屏
		
			
			if (CheckGameOver() == true)//检查游戏是否结束
			{
				break;
			}
			CheckEnemyNum();
			if (CheckNewLevel()==true)//检测是不是到下一关
			{
				continue;
			}

			Graphic::ShowScore();
			CheckCrash();//检测击中
			Graphic::DrawBattleGround();//画战斗区域
			TankDisplay();//坦克显示
			BulletDisplay();//子弹显示
			BoomDisplay();//爆炸显示
		}


		Sleep(50);

	}

	Destroy();

}
int main()
{
	Play();
	return 0;
}

