#pragma once
#include "ofMain.h"

#define TOWER_SIZE 80.0f

class Tower
{
public:
	Tower();

	void Reset();
	//void Update();
	void Draw();

	float SetSize();
	void TakeDmg();
	void ReduceHealth();
	
	ofVec2f getPosition();
	~Tower();

private:
	ofImage image;
	float m_health;
	ofVec2f m_position;
};

