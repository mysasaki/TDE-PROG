#include "Hero.h"
#include<iostream>
#include<string>


Hero::Hero()
{
	m_image.loadImage("images/char.png");
	Reset();
}

void Hero::Reset()
{
	m_hp = 100.0f;
	m_mana = 100.f;
	m_position.set(0, 0);
}

void Hero::Draw()
{
	m_image.draw(m_position, 30,30);
}

void Hero::Update()
{
	m_direction = m_destination - m_position;
	m_speed = m_direction.normalize();

	if (m_destination.distance(m_position) > 5)
		m_position = m_position + m_speed * 2;
}

/*-- Status do hero --*/
void Hero::SetHealth(float hp)
{
	m_hp = hp;
}

/*-- etc --*/

Hero::~Hero()
{
}

/*-- Movimento --*/
void Hero::SetPosition(ofVec2f pos)
{
	m_position = pos;
}

void Hero::SetDirection(ofVec2f dir)
{
	m_direction = dir;
}

void Hero::SetDestination(ofVec2f dest)
{
	m_destination = dest;
}

void Hero::SetSpeed(ofVec2f spd)
{
	m_speed = spd;
}


/*-- Getters --*/
float Hero::GetHealth()
{
	return m_hp;
}

float Hero::GetMana()
{
	return m_mana;
}

ofVec2f Hero::GetPosition()
{
	return m_position;
}

ofVec2f Hero::GetDirection()
{
	return m_direction;
}

ofVec2f Hero::GetSpeed()
{
	return m_speed;
}

ofVec2f Hero::GetDestination()
{
	return m_destination;
}

