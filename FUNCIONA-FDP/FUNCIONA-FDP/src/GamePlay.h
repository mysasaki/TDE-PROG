#pragma once
#include "ofMain.h"
#include "GameManager.h"
#include "Hero.h"

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
	Hero *Sona;
	ofImage m_background;
};

