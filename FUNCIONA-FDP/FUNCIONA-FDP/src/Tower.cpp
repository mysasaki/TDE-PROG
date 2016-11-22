#include "Tower.h"


Tower::Tower()
{
	image.loadImage("images/tower.png");
	Reset();
}

void Tower::Reset()
{
	m_size = 80.0f;
	m_health = 100.0f;
	m_position.set(1100,450);
}

void Tower::Draw()
{
	image.draw(m_position, SetSize(), SetSize());
}

float Tower::SetSize()
{
	return(m_size * (m_health / 100.0f));
}


Tower::~Tower()
{
}
