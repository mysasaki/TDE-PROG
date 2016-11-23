#include "HealthBar.h"



HealthBar::HealthBar()
{
	m_width = 50.0f;
	m_height = 15.0f;
	//std::cout << "health bar created" << std::endl;
}


void HealthBar::SetPosition(ofVec2f pos)
{
	ofVec2f offset;
	offset.set(10, 20);
	m_position.set(pos);
	m_position -= offset;
}

void HealthBar::Draw(float hp)
{
	//std::cout << "health bar drew" << std::endl;
	ofSetColor(0, 102, 0);
	ofDrawRectangle(m_position, m_width * (hp/100), m_height);
}

void HealthBar::Update(ofVec2f pos)
{
	SetPosition(pos);
}

HealthBar::~HealthBar()
{
}
