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

	cout << "\tВыбераем сложность \n\tЛегкая (1)\n\tСредняя (2)\n\tТяжёлая (3)\n";

	cin >> key;

	switch (key)
	{
		case 1 :
		{
			time_tact = 200;
			width = 10;
			height = 10;
			break;
		}
		case 2:
		{
			time_tact = 400;
			width = 15;
			height = 15;
			break;
		}
		case 3:
		{
			time_tact = 600;
			width = 20;
			height = 20;
			break;
		}
		default:
			break;
	}

	map = new Map(width, height);

}

void Game_Master::Tick(char muve_key)
{
	map->Tick(muve_key);
}
