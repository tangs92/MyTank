#include "Graphic.h"
#include "Setting.h"
Rect Graphic::m_rectScreen;
Rect Graphic::m_rectBattleGround;
char Graphic::m_pArray[100];
char Graphic::m_pArrayInfo[100];
Graphic::Graphic()
{

}

void Graphic::Create()
{
	m_rectScreen.Set(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	m_rectBattleGround.Set(BATTLE_GROUND_X1, BATTLE_GROUND_Y1, BATTLE_GROUND_X2, BATTLE_GROUND_Y2);
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	setbkcolor(DARKGRAY);

	//设置战斗区域
	
}

void Graphic::Destroy()
{
	closegraph();
}

void Graphic::ShowScore()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();


	rectangle(SCORE_LEFT, SCORE_TOP, SCORE_LEFT + 200, SCORE_TOP + 40);


	RECT r = { SCORE_LEFT, SCORE_TOP, SCORE_LEFT + 200, SCORE_TOP + 40 };
	wsprintf((LPWSTR)m_pArray, _T("第 %d 关"), Setting::GetGameLevel());
	drawtext((LPWSTR)m_pArray, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPWSTR)m_pArray, _T("分  数  :  %d"), Setting::GetSumScore());
	drawtext((LPWSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPWSTR)m_pArray, _T("级  别  :  %d"), Setting::GetTankLevel());
	drawtext((LPWSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPWSTR)m_pArray, _T("生  命  :  %d"), Setting::GetLife());
	drawtext((LPWSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPWSTR)m_pArray, _T("敌人数  :  %d"), Setting::GetTankNum());
	drawtext((LPWSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;

	line(SCORE_LEFT, r.bottom, SCREEN_WIDTH - 5, r.bottom);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPWSTR)m_pArray, _T("共击毁敌人数  :  %d"), Setting::GetTankSum());
	drawtext((LPWSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);


	setcolor(color_save);
	setfillcolor(fill_color_save);
}


void Graphic::ShowInfo()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();


	/*写要提示的信息*/
	//Point mid_pos(SCREEN_WIDTH/2, SCREEN_HEIGHT / 2);
	//rectangle(mid_pos.GetX() - 100, mid_pos.GetY() - 100, mid_pos.GetX() + 100, mid_pos.GetY() + 100);
	//rectangle(BATTLE_GROUND_X1 + 100, BATTLE_GROUND_Y1 + 200, BATTLE_GROUND_X1 + 700, BATTLE_GROUND_Y1 + 380);
	//RECT r = { BATTLE_GROUND_X1 + 100, BATTLE_GROUND_Y1 + 200, BATTLE_GROUND_X1 + 700, BATTLE_GROUND_Y1 + 380 };
	//wsprintf((LPWSTR)m_pArrayInfo, _T("GAME-OVER \n最后得分: %d"), Setting::GetSumScore());
	//drawtext((LPWSTR)m_pArrayInfo, &r, DT_CENTER | DT_VCENTER | DT_WORDBREAK);

	LOGFONT fontBak;
	gettextstyle(&fontBak);
	LOGFONT f = fontBak;
	f.lfHeight = 48;//字体高度为48
	//_tcscanf_s(f.lfFaceName, _T("黑体"));//输出字体黑体
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	wsprintf((LPWSTR)m_pArray, _T("GAME-OVER"), Setting::GetSumScore());
	outtextxy(BATTLE_GROUND_X1 + 320, BATTLE_GROUND_Y1 + 100, (LPWSTR)m_pArray);
	wsprintf((LPWSTR)m_pArray, _T("最后得分: %d"), Setting::GetSumScore());
	outtextxy(BATTLE_GROUND_X1 + 315, BATTLE_GROUND_Y1 + 250, (LPWSTR)m_pArray);


	//恢复之前的字体
	settextstyle(&fontBak);

	setcolor(color_save);
	setfillcolor(fill_color_save);
}
void Graphic::ShowGameLevel(int level)
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	rectangle(BATTLE_GROUND_X1 + 100, BATTLE_GROUND_Y1 + 200, BATTLE_GROUND_X1 + 700, BATTLE_GROUND_Y1 + 380);
	
	LOGFONT fontBak;
	gettextstyle(&fontBak);

	LOGFONT f = fontBak;
	f.lfHeight = 48;//字体高度为48
	//_tcscanf_s(f.lfFaceName, _T("黑体"));//输出字体黑体
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	wsprintf((LPWSTR)m_pArray, _T("坦克大战"), level);
	outtextxy(BATTLE_GROUND_X1 + 320, BATTLE_GROUND_Y1 + 100, (LPWSTR)m_pArray);
	wsprintf((LPWSTR)m_pArray, _T("第%d关"), level);
	outtextxy(BATTLE_GROUND_X1 + 350, BATTLE_GROUND_Y1 + 250, (LPWSTR)m_pArray);


	f.lfHeight = 18;
	settextstyle(&f);
	wsprintf((LPWSTR)m_pArray, _T("按 Enter 键开始"), level);
	outtextxy(BATTLE_GROUND_X1 + 550, BATTLE_GROUND_Y1 + 350, (LPWSTR)m_pArray);

	//恢复之前的字体
	settextstyle(&fontBak);

	setcolor(color_save);
	setfillcolor(fill_color_save);

}
void Graphic::DrawBattleGround()
{
	rectangle(m_rectBattleGround.GetStartPoint().GetX(), m_rectBattleGround.GetStartPoint().GetY(),
		m_rectBattleGround.GetEndPoint().GetX(), m_rectBattleGround.GetEndPoint().GetY());
}

int Graphic::GetScreenWidth()
{
	return SCREEN_WIDTH;
}

int Graphic::GetScreenHeight()
{
	return SCREEN_HEIGHT;
}

Rect Graphic::GetBattleGround()
{
	return m_rectBattleGround;
}
