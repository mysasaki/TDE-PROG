#include "Minion.h"
#include <iostream>



Minion::Minion(Tower *torre)
{
	image.loadImage("images/minion.png");
	SetDestination(torre->getPosition());
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
	m_range.set(10, 10);
}

void Minion::Update(Tower * torre) // Caso implementar mais de uma torre e fazer os minions atacarem a proxima torre, mexe aqui
{
	Move();
	if (IsRange(torre))
		PewPew(torre);
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

void Minion::PewPew(Tower * torre)
{
	torre->TakeDmg();
}

bool Minion::IsRange(Tower *torre)
{
	ofVec2f dist;
	dist.set(torre->getPosition() - m_position);
	if ((m_range.x >= dist.x) && (m_range.y >= dist.y))
		return true;

	/* ERA PRA SER SOBRECARGA DE OPERADOR SOQ VS FDP NAO TA RECONHECENDO
	if (m_range >= (torre->getPosition()-m_position)) // Sobrecarga de operador!!!!!!!
		return true;*/
	else
		return false;
}

/*-- Setters --*/
void Minion::SetPosition(float x, float y)
{
	m_position.set(x, y);
}

void Minion::SetDestination(ofVec2f dest) //Quando adicinar primeira torre muda aqui
{
	m_destination = dest;
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


/*
bool Minion::operator >=(const ofVec2f &v1) const
{
	return ((m_range.x >= v1.x) && (m_range.y >= v1.y));
}
*/