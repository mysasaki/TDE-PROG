#pragma once
#include "Hero.h"
#include "Tower.h"
#define MINION_SIZE 20.0f

class Minion
{
public:
	Minion(Tower *torre);
	~Minion();

	void Reset();
	void Update(Tower *torre);
	void Draw();

	void Move();
	void TakeDmg();
	void PewPew(Tower *torre);

	bool IsRange(Tower *torre); // Verifica se alvo está numa distancia 

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
		m_health,
		m_minion_speed;

	ofVec2f
		m_position,
		m_direction, 
		m_speed, 
		m_destination,
		m_range;

};

