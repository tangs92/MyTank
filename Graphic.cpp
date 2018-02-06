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

	//����ս������
	
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
	wsprintf((LPWSTR)m_pArray, _T("�� %d ��"), Setting::GetGameLevel());
	drawtext((LPWSTR)m_pArray, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPWSTR)m_pArray, _T("��  ��  :  %d"), Setting::GetSumScore());
	drawtext((LPWSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPWSTR)m_pArray, _T("��  ��  :  %d"), Setting::GetTankLevel());
	drawtext((LPWSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPWSTR)m_pArray, _T("��  ��  :  %d"), Setting::GetLife());
	drawtext((LPWSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPWSTR)m_pArray, _T("������  :  %d"), Setting::GetTankNum());
	drawtext((LPWSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;

	line(SCORE_LEFT, r.bottom, SCREEN_WIDTH - 5, r.bottom);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPWSTR)m_pArray, _T("�����ٵ�����  :  %d"), Setting::GetTankSum());
	drawtext((LPWSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);


	setcolor(color_save);
	setfillcolor(fill_color_save);
}


void Graphic::ShowInfo()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();


	/*дҪ��ʾ����Ϣ*/
	//Point mid_pos(SCREEN_WIDTH/2, SCREEN_HEIGHT / 2);
	//rectangle(mid_pos.GetX() - 100, mid_pos.GetY() - 100, mid_pos.GetX() + 100, mid_pos.GetY() + 100);
	//rectangle(BATTLE_GROUND_X1 + 100, BATTLE_GROUND_Y1 + 200, BATTLE_GROUND_X1 + 700, BATTLE_GROUND_Y1 + 380);
	//RECT r = { BATTLE_GROUND_X1 + 100, BATTLE_GROUND_Y1 + 200, BATTLE_GROUND_X1 + 700, BATTLE_GROUND_Y1 + 380 };
	//wsprintf((LPWSTR)m_pArrayInfo, _T("GAME-OVER \n���÷�: %d"), Setting::GetSumScore());
	//drawtext((LPWSTR)m_pArrayInfo, &r, DT_CENTER | DT_VCENTER | DT_WORDBREAK);

	LOGFONT fontBak;
	gettextstyle(&fontBak);
	LOGFONT f = fontBak;
	f.lfHeight = 48;//����߶�Ϊ48
	//_tcscanf_s(f.lfFaceName, _T("����"));//����������
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	wsprintf((LPWSTR)m_pArray, _T("GAME-OVER"), Setting::GetSumScore());
	outtextxy(BATTLE_GROUND_X1 + 320, BATTLE_GROUND_Y1 + 100, (LPWSTR)m_pArray);
	wsprintf((LPWSTR)m_pArray, _T("���÷�: %d"), Setting::GetSumScore());
	outtextxy(BATTLE_GROUND_X1 + 315, BATTLE_GROUND_Y1 + 250, (LPWSTR)m_pArray);


	//�ָ�֮ǰ������
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
	f.lfHeight = 48;//����߶�Ϊ48
	//_tcscanf_s(f.lfFaceName, _T("����"));//����������
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	wsprintf((LPWSTR)m_pArray, _T("̹�˴�ս"), level);
	outtextxy(BATTLE_GROUND_X1 + 320, BATTLE_GROUND_Y1 + 100, (LPWSTR)m_pArray);
	wsprintf((LPWSTR)m_pArray, _T("��%d��"), level);
	outtextxy(BATTLE_GROUND_X1 + 350, BATTLE_GROUND_Y1 + 250, (LPWSTR)m_pArray);


	f.lfHeight = 18;
	settextstyle(&f);
	wsprintf((LPWSTR)m_pArray, _T("�� Enter ����ʼ"), level);
	outtextxy(BATTLE_GROUND_X1 + 550, BATTLE_GROUND_Y1 + 350, (LPWSTR)m_pArray);

	//�ָ�֮ǰ������
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
