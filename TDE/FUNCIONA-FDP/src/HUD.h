#pragma once
#include "Hero.h"
#include "GameManager.h"

class HUD
{
public:
	HUD(GameManager *game, Hero *hero);
	~HUD();
	void Update();
	void Draw(Hero *hero);
	void Reset();

private:
	ofImage m_background;
	int
		m_width,
		m_height,
		m_x,
		m_y;
};

