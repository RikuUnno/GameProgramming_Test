#include "Person.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

void DisplayState(Player& player, Enemy& enemy);

int main()
{
	char name[16]; //プレイヤーの名前用
	int selectNum; // プレイヤーのスキルを選ぶ際に使う

	int turn = 0; //現在のターンを保持する
	const int PLAYER_SKILLUP_TURE = 2; //2ターンごとにスキルアップ
	const int ENEMY_SKILLUP_TURE = 5; //5ターンごとにスキルアップ

	Enemy enemy("エネミー", 18, 5, 2.5f); //敵を定義

	cout << "=================================" << endl
		<< endl
		<< "         /*タイトル*/" << endl
		<< endl
		<< "=================================" << endl;

	Sleep(2000);

	system("cls");

	do
	{
		//名前の入力
		cout << "ヒーローネームを入力してください。*16文字まで" << endl
			<< "> " << flush;
		cin >> name;

		if (strlen(name) <= sizeof(name))
		{
			break;
		}

		system("cls");

		// 名前が16文字以上の場合の処理
		cout << "名前が長すぎます！16文字以内で入力してください。" << endl;
	} while (true);

	Player player(name, 10, 5, 2.5f); //入力された名前でプレイヤーを定義

	DisplayState(player, enemy);

	do
	{
		turn++;

		//プレイヤーのターン
		player.Attack(enemy);

		//HPチェック
		if (enemy.GetHp() <= 0)
		{
			cout << enemy.GetName() << "が倒されました！" << player.GetName() << "の勝利！" << endl;
			break;
		}

		//敵のターン
		enemy.Attack(player);

		//HPチェック
		if (player.GetHp() <= 0)
		{
			cout << player.GetName() << "が倒されました！" << enemy.GetName() << "の勝利！" << endl;
			break;
		}

		//ステータスの表示
		DisplayState(player, enemy);

		//2ターン毎にプレイヤーのスキルアップ
		if (turn % PLAYER_SKILLUP_TURE == 0 && !(turn == 0))
		{

			cout << endl;

			do
			{
				cout << "スキルを上げられます。１～３のキーで上げるスキルを選んでください" << endl
					<< "1:体力 2:攻撃力 3:防御力" << endl
					<< "> " << flush;

				//入力
				cin >> selectNum;

				if (selectNum >= 1 && selectNum <= 3)
				{
					break;
				}

				cout << "1から3を入力してください" << endl;

			} while (true);

			//上げるスキルの選択
			player.ChooseSkill(selectNum);

			cout << endl;

			DisplayState(player, enemy);

		}

		//５ターン毎に敵のスキルアップ
		if (turn % ENEMY_SKILLUP_TURE == 0 && !(turn == 0))
		{
			cout << endl;

			cout << enemy.GetName() << "のスキル上げます" << endl;

			enemy.SkillUp();
		}

	} while (true);

	cout << "End" << endl;
}

//ステータス関数
void DisplayState(Player& player, Enemy& enemy)
{
	cout << "現在のステータス" << endl;
	player.Display();
	enemy.Display();

	cout << endl;
}