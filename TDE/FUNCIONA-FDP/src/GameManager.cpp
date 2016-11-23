#include "GameManager.h"



GameManager::GameManager(int state)
{
	m_game_state = state;
	//m_mouse.loadImage("images/cursor.png");
}


GameManager::~GameManager()
{
}

void GameManager::Update()
{
}

void GameManager::Draw()
{
	//m_mouse.draw(ofGetMouseX(), ofGetMouseY());
}

void GameManager::SetGameState(int state)
{
	m_game_state = state;
}

int GameManager::GetGameState()
{
	return m_game_state;
}
