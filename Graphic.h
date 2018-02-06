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
	static void Create();//��������
	static void Destroy();//���ٻ���
	static void ShowScore();

	static void ShowInfo();//��ʾ��Ϣ
	static void ShowGameLevel(int level);//��ʾ�ؿ�
	static void DrawBattleGround();

	static int GetScreenWidth();//������Ļ���
	static int GetScreenHeight();//������Ļ�߶�

	static Rect GetBattleGround();

private:
	static char m_pArray[100];
	static char m_pArrayInfo[100];
	static Rect m_rectScreen;//������Ļ����
	static Rect m_rectBattleGround;//����ս������
};

#endif

