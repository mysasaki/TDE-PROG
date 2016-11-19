#include "HUD.h"


HUD::HUD(GameManager *game, Hero *hero)
{
	m_background.loadImage("images/HUD.png");
	Reset();
}

HUD::~HUD()
{
}

void HUD::Update()
{
	
}

void HUD::Draw(Hero *hero)
{	
	/*	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255, 127);
	m_background.draw(m_x, m_y, m_width, m_height);
	ofDisableAlphaBlending();*/
	ofSetColor(0, 0, 0);
	ofDrawRectangle(0, 540, 1200, 60);
	ofSetColor(255,255,255);
	ofDrawBitmapString("Hp: " + ofToString(hero->GetHealth()) + "%", 30, 555);
	ofDrawBitmapString("Mana: " + ofToString(hero->GetMana()) + "%", 30, 570);
}

void HUD::Reset()
{
	m_x = 50;
	m_y = 500;
	m_width = 600;
	m_height = 100;
}
