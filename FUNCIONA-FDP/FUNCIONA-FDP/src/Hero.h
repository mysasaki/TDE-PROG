#pragma once
#include "ofMain.h"
#include "GameManager.h"
#include "Enemy.h"
#include "Tower.h"
#include<string>

#define HERO_SPEED 1
#define HERO_SKILLDPS 5.0f
#define HERO_AUTODPS 1.0f

class Hero
{
public:
	/*Construtor*/
	Hero();

	void Reset();
	void Draw();
	void Update(Enemy* enemy);

	/*Ajustes de hp*/
	void SetHealth(float hp);

	/*Metodos de acesso*/
	float GetHealth();
	float GetMana();
	ofVec2f GetPosition();
	ofVec2f GetDirection();
	ofVec2f GetSpeed();
	ofVec2f GetDestination();

	/*Movimento*/
	void SetPosition(ofVec2f pos); 
	void SetDirection(ofVec2f dir);
	void SetDestination(ofVec2f dest);
	void SetSpeed(ofVec2f spd);

	/*Skills etc*/
	void EnemyLock(Enemy* enemy);
	bool IsInRange(Enemy* enemy, ofVec2f rang); // Como o champion pode usar varias distancias de ataque/suporte, usa esse parametro
	void AutoAttack(Enemy * enemy); //
	void AttackSkill(Enemy* enemy); // Hymn of Valor

	/*Cooldowns*/
	void Skill1Cooldown(float x, float y);

	~Hero();

private:
	ofImage m_image;
	
	ofVec2f
		m_range,
		m_position,
		m_direction,
		m_speed,
		m_destination;

	float
		count,
		m_hp,
		m_mana; //265

	float //Cooldowns
		m_skill1Cd;

	bool m_lock;
};

