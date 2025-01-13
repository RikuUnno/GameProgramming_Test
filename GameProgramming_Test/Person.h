#pragma once

class Person
{
protected:
	char* m_name;
	float m_hp;
	float m_atk;
	float m_def;
	const float m_reinforcement_Rate = 0.25f; //強化率(プレイヤー・エネミー共通)

public:
	//コンストラクタ
	Person(const char* name, float hp, float atk, float def);

	//デストラクタ
	virtual ~Person();

	//コピーコンストラクタ
	Person(const Person& other);

	//オーバーロード
	void operator=(const Person& other);

	float GetHp() const;

	char* GetName() const;

public:

	virtual void Display() const;

	//攻撃メソッド
	void Attack(Person& target);
};
