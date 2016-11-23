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
	m_heroSpeed = 1;
	count_Speed = 0;
	count_Mana = 0;
	count = 0;
	m_hp = 100.0f;
	m_mana = 100.f;
	m_position.set(0, 0);
	m_range.set(100,100);
	m_skill1Cd = 10;
	m_skill3Cd = 20;

	b_lock = false;
	b_skill3 = false;
}

void Hero::Draw()
{
	m_image.draw(m_position, 30,30);
}

void Hero::Update(Enemy* enemy)
{

	/*-- Cooldowns & Regen mana --*/
	m_skill1Cd += ofGetLastFrameTime();
	m_skill3Cd += ofGetLastFrameTime();
	count_Mana += ofGetLastFrameTime();

	if (count_Mana >= 1)
	{
		if (m_mana < 100)
			m_mana += 0.2f;
		count_Mana = 0;
	}

	/*-- Skill 3 --*/
	if (b_skill3) 
	{
		if (count_Speed <= 4)
			count_Speed += ofGetLastFrameTime();
		else
		{
			std::cout << "Song of Celerity off" << std::endl;
			b_skill3 = false;
			m_heroSpeed = 1;
		}
	}

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
	{
		//std::cout << "Enemy unlocked" << std::endl;
		b_lock = false;
	}

	/*-- Movimento do player --*/
	Move();
}

/*-- Status do hero --*/
void Hero::SetHealth(float hp)
{
	m_hp = hp;
}

/*-- Skills etc --*/

void Hero::ReduceHealth(float dmg)
{
	m_hp -= dmg;
}

void Hero::EnemyLock(Enemy * enemy)
{
	if (IsInRange(enemy, m_range))
	{
		std::cout << "Enemy locked" << std::endl;
		b_lock = true;
	}
}

bool Hero::IsInRange(Enemy * enemy, ofVec2f rang)
{
	ofVec2f dist;
	dist.set(enemy->GetPosition() - m_position);
	if ((rang.x >= dist.x) && (rang.y >= dist.y))
		return true;
	return false;
}

void Hero::AutoAttack(Enemy * enemy)
{
	if (IsInRange(enemy, m_range) && b_lock)
	{
		std::cout << "pew pew" << std::endl;
		enemy->TakeDmg(HERO_AUTODPS);
	}
}

void Hero::AttackSkill(Enemy * enemy)
{
	if (IsInRange(enemy, m_range) && b_lock)
	{
		if (m_skill1Cd >= 10 && (m_mana - COST_SKILL1) > 0)
		{
			enemy->TakeDmg(HERO_SKILLDPS);
			std::cout << "Hymn of valor used" << std::endl;
			m_mana -= COST_SKILL1;
			m_skill1Cd = 0;
		}
		else
			std::cout << "skill em cd" << std::endl;
	}
}

void Hero::BoostSkill() // Skill aumenta a velocidade do champ por alguns segundos
{
	if (m_skill3Cd >= 20 && (m_mana - COST_SKILL3) > 0)
	{
		count_Speed = 0;
		b_skill3 = true;
		m_heroSpeed = 2;
		std::cout << "Song of celerity used" << std::endl;
		m_mana -= COST_SKILL3;
		m_skill3Cd = 0;
	}
	else
		std::cout << "skill em cd" << std::endl;
}

/*-- HUD CD --*/
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

void Hero::Skill3Colldown(float x, float y)
{
	if (m_skill3Cd >= 20) // Skill disponível
	{
		ofSetColor(255, 255, 255);
		ofDrawBitmapString("Song of Celerity disponivel", x, y);
	}
	else
	{
		ofSetColor(255, 255, 255);
		ofDrawBitmapString("Skill em cd. Espere " + ofToString(20 - (int)m_skill3Cd) + " segundos", x, y);
	}
}

Hero::~Hero()
{
}

/*-- Movimento --*/

void Hero::Move()
{
	m_direction = m_destination - m_position;
	m_speed = m_direction.normalize();

	if (m_destination.distance(m_position) > 5)
		m_position = m_position + m_speed * m_heroSpeed;
}

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

