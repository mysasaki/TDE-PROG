#include "GamePlay.h"
#include<iostream>

GamePlay::GamePlay(GameManager *game)
{
	m_background.loadImage("images/GamePlayBG.png");

	Sona = new Hero();
	hud = new HUD(game, Sona);
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
	m_background.draw(0, 0, 1200, 600);
	Sona->Draw();
	hud->Draw(Sona);
}

void GamePlay::Update(GameManager * game)
{
	Sona->Update();
}

void GamePlay::Reset(GameManager * game)
{
	Sona->Reset();
}
