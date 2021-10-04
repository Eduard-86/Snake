#pragma once
#include "Snake.h"
#include <time.h>
#include <functional>


//struct Snake;

class Map
{

	//char map[16][16];

	char** map;

	int map_width;
	int map_height;

	char map_wall;
	char map_ground;

	char snake_heat_simbol;
	char snake_body_simbol;

	Snake* snake;

	char food_symbol;
	std::pair<int, int> food_location;

	char crash_synbol;

	int game_score;

	std::function<void(int)> FooEnd;

	//Snake* snake;
	
public:
	
	Map( unsigned int width, unsigned int height, char sn_heat = '#', char sn_body = '*', 
		char mp_wall = '0', char mp_ground = '.', char fo_symbol = '$', char cra_symbol = '@');

	void PrintMap();

	void Tick(char move_snake);

	void SpavnFood();

	//void FillMap(const std::pair<int, int>& snakelocation)
	void FillMap();
	//Snake& snake

	void SetFooEnd(std::function<void(int)> Foo)
	{
		FooEnd = Foo;
	}
};
