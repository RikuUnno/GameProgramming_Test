#pragma once
#include "Person.h"

class Enemy
	: public Person
{
public:

	Enemy(const char* name, float hp, float atk, float def);

	void Display() const;

	//ƒXƒLƒ‹‚ğ‚OD‚Q‚T”{ã‚°‚é
	void SkillUp();
};
