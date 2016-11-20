#pragma once
#include "Hero.h"
#define MINION_SIZE 20.0f

class Minion
{
public:
	Minion();
	~Minion();

	void Reset();
	void Update();
	void Draw();

	void Move();
	void TakeDmg();

	void SetPosition(float x, float y);
	void SetDestination();
	void ReduceHealth();
	void SetMinionSpeed(float spd);
	float SetSize();
	float GetHp();


private:
	ofImage image;
	float 
		m_health,
		m_minion_speed;

	ofVec2f
		m_position,
		m_direction, 
		m_speed, 
		m_destination;
};

