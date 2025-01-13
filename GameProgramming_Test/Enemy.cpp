#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(const char* name, float hp, float atk, float def)
	: Person(name, hp, atk, def) {}

void Enemy::Display() const
{
	cout << "[ƒGƒlƒ~[] " << "–¼‘OF" << m_name << " ‘Ì—ÍF" << m_hp
		<< " UŒ‚—ÍF" << m_atk << " –hŒä—ÍF" << m_def << endl;
}

//ƒXƒLƒ‹‚ð‚OD‚Q‚T”{ã‚°‚é
void Enemy::SkillUp()
{
	m_hp += m_hp * m_reinforcement_Rate;	//HpUp
	m_atk += m_atk * m_reinforcement_Rate;	//UŒ‚—Íup
	m_def += m_def * m_reinforcement_Rate;	//–hŒä—Íup
}