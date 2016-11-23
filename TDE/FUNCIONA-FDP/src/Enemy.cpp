#include "Enemy.h"



Enemy::Enemy()
{
	Reset();
}


Enemy::~Enemy()
{
}

void Enemy::Reset()
{
	m_size = 0.0f;
	m_health = 100.0f;
	m_position.set(0, 0);
}

bool Enemy::CheckClicked(int x, int y)
{
	if (((float) x > m_position.x) && ((float) x < m_position.x + m_size) 
		&& ((float)y > m_position.y) && ((float) y < m_position.y + m_size))
	{
		std::cout << "clicou no inimigo porra" << std::endl;
		return true;
	}
	return false;
}

void Enemy::SetSize(float siz)
{
	m_size = siz;
}

void Enemy::SetPosition(ofVec2f pos)
{
	m_position.set(pos);
}

void Enemy::TakeDmg(float dmg)
{
	ReduceHealth(dmg);
}

void Enemy::ReduceHealth(float dmg)
{
	m_health -= dmg;
}

ofVec2f Enemy::GetPosition()
{
	return m_position;
}

float Enemy::GetHealth()
{
	return m_health;
}
