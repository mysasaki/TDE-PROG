#include "GameMenu.h"



GameMenu::GameMenu(GameManager *game)
{
	background.loadImage("images/GameMenuBG.png");
	Reset();
}

void GameMenu::Draw()
{
	background.draw(0, 0);
	Playbutton->Draw();
}

void GameMenu::Reset()
{
	Playbutton = new Button(550, 450);
}

void GameMenu::MousePressed(int x, int y, int button, GameManager *game)
{
	if (Playbutton->WasClicked(x, y) && button == OF_MOUSE_BUTTON_1)
		game->SetGameState(GAME_PLAY);
}


GameMenu::~GameMenu()
{
}
