#pragma once
#include "ofMain.h"
#include "Hero.h"

#define GAME_MENU 0
#define GAME_PLAY 1

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 600

class GameManager
{
public:
	GameManager(int state);
	~GameManager();

	void Update();
	void Draw();

	void SetGameState(int state);
	int GetGameState();

private:
	int m_game_state;
};

