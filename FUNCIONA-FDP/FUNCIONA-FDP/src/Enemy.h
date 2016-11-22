#pragma once
#include "ofMain.h"
class Enemy
{
public:
	Enemy();
	~Enemy();

	virtual void Reset();
	//void Update();
	bool CheckClicked(int x, int y);

	virtual void SetSize(float siz);
	void SetPosition(ofVec2f pos);
	void TakeDmg(float dmg);
	void ReduceHealth(float dmg);
	ofVec2f getPosition();

protected:
	float
		m_size,
		m_health;
	ofVec2f m_position;
};

