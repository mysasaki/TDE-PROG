#include "Minion.h"
#include <iostream>



Minion::Minion()
{
	image.loadImage("images/minion.png");
	SetDestination();
	Reset();
}


Minion::~Minion()
{
}

void Minion::Reset()
{
	m_health = 100.0f;
	m_minion_speed = 1.0;
	m_position.set(0, 0);
}

void Minion::Update()
{
	Move();
}

void Minion::Draw()
{
	image.draw(m_position, SetSize(), SetSize());
}

void Minion::Move()
{
	m_direction = m_destination - m_position;
	m_speed = m_direction.normalize();
	if (m_destination.distance(m_position) > 5)
		m_position = m_position + m_speed * m_minion_speed;
}

void Minion::TakeDmg()
{
	ReduceHealth();
}

/*-- Setters --*/
void Minion::SetPosition(float x, float y)
{
	m_position.set(x, y);
}

void Minion::SetDestination(/*ofVec2f dest*/) //Quando adicinar primeira torre muda aqui
{
	m_destination.set(1200, 600);
}

void Minion::ReduceHealth() // Se der tempo, mudar por um setHealth onde pode variar varios tipos de ataque
{
	if (m_health >= 0)
	{
		m_health = m_health - 10.0f;
	}
}

void Minion::SetMinionSpeed(float spd)
{
	m_minion_speed = spd;
}

float Minion::SetSize() // Como não desenhei barra de vida pra cada minion, o hp de cada um vai ser medido pelo tamanho do minion
{
	return (MINION_SIZE * (m_health / 100.0f));
}

float Minion::GetHp()
{
	return m_health;
}
