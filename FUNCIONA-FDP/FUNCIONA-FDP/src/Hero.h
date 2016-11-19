#pragma once
#include "ofMain.h"
#include "GameManager.h"
#include<string>

class Hero
{
public:
	/*Construtor*/
	Hero();

	void Reset();
	void Draw();
	void Update(GameManager* game);

	/*Ajustes de hp*/
	void SetHealth(float hp);

	/*Metodos de acesso*/
	float GetHealth();
	float GetMana();
	ofVec2f GetPosition();
	ofVec2f GetDirection();
	ofVec2f GetSpeed();
	ofVec2f GetDestination();

	/*Movimento*/
	void SetPosition(ofVec2f pos);
	void SetDirection(ofVec2f dir);
	void SetDestination(ofVec2f dest);
	void SetSpeed(ofVec2f spd);

	~Hero();

private:
	ofImage m_image;
	ofVec2f m_position;
	ofVec2f m_direction;
	ofVec2f m_speed;
	ofVec2f m_destination;

	float
		m_hp,
		m_mana; //265
};

