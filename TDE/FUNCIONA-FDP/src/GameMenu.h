#pragma once
#include "ofMain.h"
#include "Button.h"
#include "GameManager.h"
class GameMenu
{
public:
	GameMenu(GameManager *game);
	void Draw();
	void Reset();
	void MousePressed(int x, int y, int button, GameManager *game);
	~GameMenu();

private:
	ofImage background;
	Button *Playbutton;
};

