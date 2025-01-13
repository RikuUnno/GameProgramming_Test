#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include <iostream>
#include "Windows.h"

using namespace std;

Person::Person(const char* name, float hp, float atk, float def)
{
	//�N���X�̒�`�Ŗ��O��������
	m_name = new(nothrow) char[strlen(name) + 1];
	if (m_name != nullptr)
	{
		strcpy(m_name, name);
	}
	//hp�̏�����
	m_hp = hp;
	//atk�̏�����
	m_atk = atk;
	//def�̏�����
	m_def = def;
}

//�f�X�g���N�^
Person::~Person()
{
	if (m_name != nullptr)
	{
		delete[] m_name;
		m_name = nullptr;
	}
}

//�R�s�[�R���X�g���N�^
Person::Person(const Person& other)
{
	//���O�̃R�s�[
	m_name = new(nothrow) char[strlen(other.m_name) + 1];
	if (m_name != nullptr)
	{
		strcpy(m_name, other.m_name);
	}
	//hp�̃R�s�[
	m_hp = other.m_hp;
	//atk�̃R�s�[
	m_atk = other.m_atk;
	//def�̃R�s�[
	m_def = other.m_def;
}

//�I�[�o�[���[�h
void Person::operator=(const Person& other)
{
	delete[] m_name;

	//���O�̑��
	m_name = new(nothrow) char[strlen(other.m_name) + 1];
	if (m_name != nullptr)
	{
		strcpy(m_name, other.m_name);
	}
	//hp�̑��
	m_hp = other.m_hp;
	//atk�̑��
	m_atk = other.m_atk;
	//def�̑��
	m_def = other.m_def;
}

float Person::GetHp() const
{
	return m_hp;
}

char* Person::GetName() const
{
	return m_name;
}

void Person::Display() const
{
	cout << "���O�F" << m_name << " �̗́F" << m_hp << " �U���́F" << m_atk << " �h��́F" << m_def << endl;
}

//�U�����\�b�h
void Person::Attack(Person& target)
{
	Sleep(2000);

	cout << m_name << "�̍U��" << endl;

	float damage = m_atk - target.m_def;

	cout << target.m_name << "��" << damage << "�̃_���[�W" << endl;

	if (damage > 0) {
		target.m_hp -= damage;
	}

	//�}�C�i�X���̃`�F�b�N
	if (target.m_hp < 0)
	{
		target.m_hp = 0;
	}

	cout << endl;
}