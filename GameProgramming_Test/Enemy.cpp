#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(const char* name, float hp, float atk, float def)
	: Person(name, hp, atk, def) {}

void Enemy::Display() const
{
	cout << "[�G�l�~�[] " << "���O�F" << m_name << " �̗́F" << m_hp
		<< " �U���́F" << m_atk << " �h��́F" << m_def << endl;
}

//�X�L�����O�D�Q�T�{�グ��
void Enemy::SkillUp()
{
	m_hp += m_hp * m_reinforcement_Rate;	//HpUp
	m_atk += m_atk * m_reinforcement_Rate;	//�U����up
	m_def += m_def * m_reinforcement_Rate;	//�h���up
}