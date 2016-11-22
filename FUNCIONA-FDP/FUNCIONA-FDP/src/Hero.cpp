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
	count = 0;
	m_hp = 100.0f;
	m_mana = 100.f;
	m_position.set(0, 0);
	m_range.set(100,100);
	m_lock = false;
	m_skill1Cd = 10;
}

void Hero::Draw()
{
	m_image.draw(m_position, 30,30);
}

void Hero::Update(Enemy* enemy)
{
	/*-- Cooldowns --*/
	m_skill1Cd += ofGetLastFrameTime();


	/*-- Ataques --*/
	count += ofGetLastFrameTime();
	if (IsInRange(enemy, m_range))
	{
		if (count >= 10)
		{
			AutoAttack(enemy);
			count = 0;
		}
	}

	if (!IsInRange(enemy, m_range)) // Se o player se afastar demais do inimigo
		m_lock = false;

	/*-- Movimento do player --*/
	m_direction = m_destination - m_position;
	m_speed = m_direction.normalize();

	if (m_destination.distance(m_position) > 5)
		m_position = m_position + m_speed * HERO_SPEED;
}

/*-- Status do hero --*/
void Hero::SetHealth(float hp)
{
	m_hp = hp;
}

/*-- Skills etc --*/

void Hero::EnemyLock(Enemy * enemy)
{
	if (IsInRange(enemy, m_range))
	{
		std::cout << "Enemy locked" << std::endl;
		m_lock = true;
	}
}

bool Hero::IsInRange(Enemy * enemy, ofVec2f rang)
{
	ofVec2f dist;
	dist.set(enemy->getPosition() - m_position);
	if ((rang.x >= dist.x) && (rang.y >= dist.y))
		return true;
	return false;
}

void Hero::AutoAttack(Enemy * enemy)
{
	if (IsInRange(enemy, m_range))
	{
		std::cout << "pew pew" << std::endl;
		enemy->TakeDmg(HERO_AUTODPS);
	}
}

void Hero::AttackSkill(Enemy * enemy)
{
	if (IsInRange(enemy, m_range))
	{
		if (m_skill1Cd >= 10)
		{
			enemy->TakeDmg(HERO_SKILLDPS);
			std::cout << "Hymn of valor used" << std::endl;
			m_skill1Cd = 0;
		}
		else
			std::cout << "skill em cd" << std::endl;
	}
}

void Hero::Skill1Cooldown(float x, float y)
{
	if (m_skill1Cd >= 10) // Skill está disponivel pra uso
	{
		ofSetColor(255, 255, 255);
		ofDrawBitmapString("Hymn of Valor disponivel", x, y);
	}
	else
	{
		ofSetColor(255, 255, 255);
		ofDrawBitmapString("Skill em cd. Espere " + ofToString(10 - (int)m_skill1Cd) + " segundos", x, y);
	}
}

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

