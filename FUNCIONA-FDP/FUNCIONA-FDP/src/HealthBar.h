#pragma once
#include "ofMain.h"
class HealthBar
{
public:
	HealthBar();

	void Draw(float hp);
	void Update(ofVec2f pos);
	void SetPosition(ofVec2f pos);
	~HealthBar();

private:
	float
		m_width,
		m_height;
	
	ofVec2f m_position;
};

