#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(const char* name, float hp, float atk, float def)
	: Person(name, hp, atk, def) {}

void Player::Display() const
{
	cout << "[vC[] " << "¼OF" << m_name << " ÌÍF" << m_hp
		<< " UÍF" << m_atk << " häÍF" << m_def << endl;
}

void Player::ChooseSkill(int num)
{
	switch (num)
	{
	case 1:
		m_hp += 5;	//ÌÍup
		break;
	case 2:
		m_atk += m_atk * m_reinforcement_Rate;	//UÍup
		break;
	case 3:
		m_def += m_def * m_reinforcement_Rate;	//häÍup
		break;
	}
}