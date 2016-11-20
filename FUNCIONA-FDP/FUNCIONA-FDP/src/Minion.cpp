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
	m_position.set(0, 0);
}

void Minion::Update(Hero *hero)
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
		m_position = m_position + m_speed * MINION_SPEED;
}

void Minion::TakeDmg()
{
	ReduceHealth();
}

/*-- Setters --*/
void Minion::SetDestination(/*ofVec2f dest*/) //Quando adicinar primeira torre muda aqui
{
	m_destination.set(1200, 600);
}

void Minion::ReduceHealth() // Se der tempo, mudar por um setHealth onde pode variar varios tipos de ataque
{
	m_health -= 10.0f;
}

float Minion::SetSize() // Como não desenhei barra de vida pra cada minion, o hp de cada um vai ser medido pelo tamanho do minion
{
	return (10.0 / (m_health / 100.0));
}

