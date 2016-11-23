#pragma once
#include "ofMain.h"
#include "GameManager.h"
#include "Enemy.h"
#include "Tower.h"
#include "HealthBar.h"
#include<string>

#define HERO_SKILLDPS 5.0f
#define HERO_AUTODPS 1.0f
#define COST_SKILL1 15.0f
#define COST_SKILL2 26.0f
#define COST_SKILL3 24.0f

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
	void Move();
	void SetPosition(ofVec2f pos); 
	void SetDirection(ofVec2f dir);
	void SetDestination(ofVec2f dest);
	void SetSpeed(ofVec2f spd);

	/*Skills etc*/
	void ReduceHealth(float dmg);
	void EnemyLock(Enemy* enemy);
	bool IsInRange(Enemy* enemy, ofVec2f rang); // Como o champion pode usar varias distancias de ataque/suporte, usa esse parametro
	void AutoAttack(Enemy * enemy); //
	void AttackSkill(Enemy* enemy); // Hymn of Valor
	void HealSkill(); // Aria of Perseverance
	void BoostSkill(); // Song of Celerity

	/*Cooldowns no HUD*/
	void Skill1Cooldown(float x, float y);
	void Skill2Cooldown(float x, float y);
	void Skill3Colldown(float x, float y);

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
		count_Speed,
		count_Mana,
		count,
		m_heroSpeed,
		m_hp,
		m_mana; //265

	float //Cooldowns
		m_skill1Cd,
		m_skill2Cd,
		m_skill3Cd;

	bool
		b_skill3,
		b_lock;
};

