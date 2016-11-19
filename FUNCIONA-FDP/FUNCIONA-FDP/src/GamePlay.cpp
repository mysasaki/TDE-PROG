#include "GamePlay.h"


GamePlay::GamePlay(GameManager *game)
{
	m_background.loadImage("images/GamePlayBG.png");

	Sona = new Hero();
	Reset(game);
}


GamePlay::~GamePlay()
{
}

void GamePlay::MousePressed(int x, int y, int button)
{
	if (button == OF_MOUSE_BUTTON_3)
		Sona->SetDestination(ofVec2f(ofGetMouseX(), ofGetMouseY()));
}

void GamePlay::Draw(GameManager * game)
{
	m_background.draw(0, 0);
	Sona->Draw();
}

void GamePlay::Update(GameManager * game)
{
	Sona->Update(game);
}

void GamePlay::Reset(GameManager * game)
{
	Sona->Reset();
}
