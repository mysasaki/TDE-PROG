#pragma once
#include "ofMain.h"
#include "GameManager.h"
#include "Hero.h"
#include "Minion.h"
#include "HUD.h"
#include<string>

class GamePlay
{
public:
	GamePlay(GameManager *game);
	~GamePlay();

	void MousePressed(int x, int y, int button);
	void Draw(GameManager *game);
	void Update(GameManager *game);
	void Reset(GameManager *game);

private:
	HUD *hud;
	Hero *Sona;
	Minion *Mini;
	ofImage m_background;
};

