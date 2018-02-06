#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__

#include <graphics.h>
#include "Rect.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#define BATTLE_GROUND_X1 5
#define BATTLE_GROUND_Y1 5
#define BATTLE_GROUND_X2 800
#define BATTLE_GROUND_Y2 (SCREEN_HEIGHT-BATTLE_GROUND_Y1)

const int SCORE_LEFT = 810;
const int SCORE_TOP = 5;

class Graphic
{
public:
	Graphic();
	static void Create();//创建画布
	static void Destroy();//销毁画布
	static void ShowScore();

	static void ShowInfo();//显示信息
	static void ShowGameLevel(int level);//显示关卡
	static void DrawBattleGround();

	static int GetScreenWidth();//返回屏幕宽度
	static int GetScreenHeight();//返回屏幕高度

	static Rect GetBattleGround();

private:
	static char m_pArray[100];
	static char m_pArrayInfo[100];
	static Rect m_rectScreen;//设置屏幕区域
	static Rect m_rectBattleGround;//设置战斗区域
};

#endif

