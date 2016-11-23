#pragma once
#include "Hero.h"
#include "Tower.h"
#include "Enemy.h"
#define MINION_SIZE 20.0f

class Minion
{
public:
	Minion(Enemy *enemy);
	~Minion();

	void Reset();
	void Update(Enemy *enemy);
	void Draw();

	void Move();
	void TakeDmg();
	void PewPew(Enemy *enemy);

	bool IsRange(Enemy *enemy); // Verifica se alvo está numa distancia 

	void SetPosition(float x, float y);
	void SetDestination(ofVec2f dest);
	void ReduceHealth();
	void SetMinionSpeed(float spd);
	float SetSize();
	float GetHp();

	// bool operator>=(const ofVec2f &v1) const;

private:
	ofImage image;
	float
		count,
		m_dps,
		m_health,
		m_minion_speed;

	ofVec2f
		m_position,
		m_direction, 
		m_speed, 
		m_destination,
		m_range;

};

