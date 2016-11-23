#pragma once
#include "ofMain.h"
#include "GameManager.h"
#include "Hero.h"
#include "Minion.h"
#include "HealthBar.h"
#include "Tower.h"
#include "HUD.h"
#include<string>
#include <vector>

class GamePlay
{
public:
	GamePlay(GameManager *game);
	~GamePlay();

	void Draw(GameManager *game);
	void Update(GameManager *game);
	void Reset(GameManager *game);

	void AddMinions(int num, Tower *torre);

	void MousePressed(int x, int y, int button);
	void KeyPressed(int key);

private:
	HUD *hud;
	Hero *Sona;
	Tower *Torrone;
	HealthBar *HeroHp;
	HealthBar *TowerHp;
	//Minion *Mini;
	ofImage m_background;
	vector <Minion*> Mob;
};

