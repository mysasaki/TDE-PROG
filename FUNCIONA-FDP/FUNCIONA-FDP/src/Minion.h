#pragma once
#include "Hero.h"
#define MINION_SPEED 1.2

class Minion
{
public:
	Minion();
	~Minion();

	void Reset();
	void Update(Hero *hero);
	void Draw();

	void Move();
	void TakeDmg();

	void SetDestination();
	void ReduceHealth();
	float SetSize();

private:
	ofImage image;
	float m_health;

	ofVec2f 
		m_position,
		m_direction, 
		m_speed, 
		m_destination;
};

