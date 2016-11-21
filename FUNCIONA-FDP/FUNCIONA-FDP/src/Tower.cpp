#include "Tower.h"


Tower::Tower()
{
	image.loadImage("images/tower.png");
	Reset();
}

void Tower::Reset()
{
	m_health = 100.0f;
	m_position.set(1100,450);
}

void Tower::Draw()
{
	image.draw(m_position, SetSize(), SetSize());
}

float Tower::SetSize()
{
	return(TOWER_SIZE * (m_health / 100.0f));
}

void Tower::TakeDmg() // Depois ajustar essa funcao pra diferenciar dano recebido por heroi ou minion
{
	ReduceHealth();
}

void Tower::ReduceHealth(/*float*/)
{
	if (m_health >= 0)
	{
		m_health -= 5.0f;
	}
}


ofVec2f Tower::getPosition()
{
	return m_position;
}

Tower::~Tower()
{
}
