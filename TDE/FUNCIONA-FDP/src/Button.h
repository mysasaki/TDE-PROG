#pragma once
#include "ofMain.h"

class Button
{
public:
	Button(float x, float y);
	void Draw();
	void Reset();
	bool WasClicked(int x, int y);
	~Button();
	
private:
	ofImage image;
	float
		m_x,
		m_y,
		m_width,
		m_height;
};

