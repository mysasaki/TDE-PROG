#include "GamePlay.h"
#include <iostream>
#include <vector>

GamePlay::GamePlay(GameManager *game)
{
	m_background.loadImage("images/GamePlayBG.png");

	Torrone = new Tower();
	Sona = new Hero();
	//Mini = new Minion();
	hud = new HUD(game, Sona);

	Reset(game);
	AddMinions(6, Torrone);
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
	Torrone->Draw();
	//Mini->Draw();
	hud->Draw(Sona);

	for (unsigned int i = 0; i < 6; i++)
	{
		Mob[i]->Draw();
		//std::cout << "minion " << i << " desenhado porra" << std::endl;

	}
}

void GamePlay::Update(GameManager * game)
{
	Sona->Update();
	//Mini->Update();

	for (unsigned int i = 0; i < 6; i++)
	{
		Mob[i]->Update(Torrone);
		//std::cout << "minion " << i << " atualizado caralha" << std::endl;
	}

}


void GamePlay::Reset(GameManager * game)
{
	Sona->Reset();
}

void GamePlay::AddMinions(int num, Tower *torre)
{
	float randX, randY, randSpd;

	for (unsigned int i = 0; i < num; i++)
	{
		randX = ofRandom(-50, -10);
		randY = ofRandom(-50, -10);
		randSpd = ofRandom(0.5, 0.8);
		Minion *minion = new Minion(torre);
		minion->SetPosition(randX, randY);
		minion->SetMinionSpeed(randSpd);
		Mob.push_back(minion);
		//std::cout << "Minion " << i << " criado PORRA" << std::endl;
	}
}


/*-- hacks pra testar dmg etc --*/
void GamePlay::KeyPressed(int key)
{
	if (key == 'b')
	{
		for (unsigned int i = 0; i < 6; i++)
		{
			if (Mob[i]->GetHp() > 0)
			{
				Mob[i]->TakeDmg();
				return;
			}
		}
		//Mini->TakeDmg();
	}

	if (key == 'n')
	{
		Torrone->TakeDmg();
	}

}