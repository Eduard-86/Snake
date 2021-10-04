#pragma once
#include "Snake.h"
#include <time.h>


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
	

	//Snake* snake;
	
public:
	
	Map( unsigned int width, unsigned int height, char sn_heat = '#', char sn_body = '*', 
		char mp_wall = '0', char mp_ground = '.', char fo_symbol = '$' );

	void PrintMap();

	void Tick(char move_snake);

	void SpavnFood();

	//void FillMap(const std::pair<int, int>& snakelocation)
	void FillMap();
	//Snake& snake
};
