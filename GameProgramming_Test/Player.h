#pragma once
#include "Person.h"

class Player
	: public Person
{
public:

	Player(const char* name, float hp, float atk, float def);

	void Display() const;

	// 強化する値を選ぶ
	void ChooseSkill(int num);
};
