#pragma once
#include "Person.h"

class Enemy
	: public Person
{
public:

	Enemy(const char* name, float hp, float atk, float def);

	void Display() const;

	//�X�L�����O�D�Q�T�{�グ��
	void SkillUp();
};
