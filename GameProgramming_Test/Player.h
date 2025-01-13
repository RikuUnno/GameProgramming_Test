#pragma once
#include "Person.h"

class Player
	: public Person
{
public:

	Player(const char* name, float hp, float atk, float def);

	void Display() const;

	// ‹­‰»‚·‚é’l‚ð‘I‚Ô
	void ChooseSkill(int num);
};
