#include "Setting.h"

bool Setting::m_bNewLevel = true;

int Setting::m_nLife = 3;

int Setting::m_nGameLevel = 0;
int Setting::m_nTankLevel = 1;

int Setting::m_nTankNum = MAX_ENEMYS;

int Setting::m_nSumScore = 0;

int Setting::m_nTankScore = 5;

int Setting::m_nTankSum = 0;

void Setting::NewGameLevel()
{
	
	m_nTankNum = MAX_ENEMYS + 5 * (m_nGameLevel - 1);
	m_nGameLevel++;
	m_nTankScore += 5;
	AddLife();
}

void Setting::TankDamaged()
{
	m_nTankNum--;
	m_nSumScore += m_nTankScore;
	m_nTankLevel = m_nSumScore / 150 + 1;

	m_nTankSum++;
	if (m_nTankLevel == 0)
	{
		m_bNewLevel = true;
	}
}

void Setting::MainTankDie()
{
	if (m_nLife > 0)
	{
		m_nLife--;
	}

}