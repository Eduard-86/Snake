#include "Game_Master.h"
#include <iostream>
#include <conio.h>
//#include <synchapi.h>

/*
void Game_Master::Menu()
{
	

}*/

void Game_Master::Start_Game()
{
	
	using std::cout;
	using std::cin;
	using std::endl;

	int width = 0;
	int height = 0;

	int key = 0;

	cout << "Выбераем сложность \nЛегкая (1)\nСредняя (2)\nТяжёлая (3)\n";

	cin >> key;

	switch (key)
	{
		case 1 :
		{
			time_tact = 400;
			width = 15;
			height = 15;
			break;
		}
		case 2:
		{
			time_tact = 300;
			width = 13;
			height = 13;
			break;
		}
		case 3:
		{
			time_tact = 200;
			width = 11;
			height = 11;
			break;
		}
		default:
			break;
	}

	map = new Map(width, height);

	std::function<void(int)> FooEnd =
		std::bind(&Game_Master::End_Game, this, std::placeholders::_1);

	map->SetFooEnd(FooEnd);
	
}

void Game_Master::Tick(char muve_key)
{
	map->Tick(muve_key);
}

void Game_Master::End_Game(int score)
{
	std::cout << "Ты проиграл\n";
	std::cout << "Твой счёт :" << score << std::endl << std::endl;

	system("pause");
	exit(0);
}
