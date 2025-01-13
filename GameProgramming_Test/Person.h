#pragma once

class Person
{
protected:
	char* m_name;
	float m_hp;
	float m_atk;
	float m_def;
	const float m_reinforcement_Rate = 0.25f; //������(�v���C���[�E�G�l�~�[����)

public:
	//�R���X�g���N�^
	Person(const char* name, float hp, float atk, float def);

	//�f�X�g���N�^
	virtual ~Person();

	//�R�s�[�R���X�g���N�^
	Person(const Person& other);

	//�I�[�o�[���[�h
	void operator=(const Person& other);

	float GetHp() const;

	char* GetName() const;

public:

	virtual void Display() const;

	//�U�����\�b�h
	void Attack(Person& target);
};
