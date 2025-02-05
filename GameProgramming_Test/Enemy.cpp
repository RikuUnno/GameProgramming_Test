#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(const char* name, float hp, float atk, float def)
	: Person(name, hp, atk, def) {}

void Enemy::Display() const
{
	cout << "[Gl~[] " << "¼OF" << m_name << " ÌÍF" << m_hp
		<< " UÍF" << m_atk << " häÍF" << m_def << endl;
}

//XLðODQT{ã°é
void Enemy::SkillUp()
{
	m_hp += m_hp * m_reinforcement_Rate;	//HpUp
	m_atk += m_atk * m_reinforcement_Rate;	//UÍup
	m_def += m_def * m_reinforcement_Rate;	//häÍup
}