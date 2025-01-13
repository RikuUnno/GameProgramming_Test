#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include <iostream>
#include "Windows.h"

using namespace std;

Person::Person(const char* name, float hp, float atk, float def)
{
	//クラスの定義で名前を初期化
	m_name = new(nothrow) char[strlen(name) + 1];
	if (m_name != nullptr)
	{
		strcpy(m_name, name);
	}
	//hpの初期化
	m_hp = hp;
	//atkの初期化
	m_atk = atk;
	//defの初期化
	m_def = def;
}

//デストラクタ
Person::~Person()
{
	if (m_name != nullptr)
	{
		delete[] m_name;
		m_name = nullptr;
	}
}

//コピーコンストラクタ
Person::Person(const Person& other)
{
	//名前のコピー
	m_name = new(nothrow) char[strlen(other.m_name) + 1];
	if (m_name != nullptr)
	{
		strcpy(m_name, other.m_name);
	}
	//hpのコピー
	m_hp = other.m_hp;
	//atkのコピー
	m_atk = other.m_atk;
	//defのコピー
	m_def = other.m_def;
}

//オーバーロード
void Person::operator=(const Person& other)
{
	delete[] m_name;

	//名前の代入
	m_name = new(nothrow) char[strlen(other.m_name) + 1];
	if (m_name != nullptr)
	{
		strcpy(m_name, other.m_name);
	}
	//hpの代入
	m_hp = other.m_hp;
	//atkの代入
	m_atk = other.m_atk;
	//defの代入
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
	cout << "名前：" << m_name << " 体力：" << m_hp << " 攻撃力：" << m_atk << " 防御力：" << m_def << endl;
}

//攻撃メソッド
void Person::Attack(Person& target)
{
	Sleep(2000);

	cout << m_name << "の攻撃" << endl;

	float damage = m_atk - target.m_def;

	cout << target.m_name << "に" << damage << "のダメージ" << endl;

	if (damage > 0) {
		target.m_hp -= damage;
	}

	//マイナスかのチェック
	if (target.m_hp < 0)
	{
		target.m_hp = 0;
	}

	cout << endl;
}