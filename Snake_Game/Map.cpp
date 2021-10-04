#include "Map.h"
#include <iostream>

Map::Map(unsigned int width, unsigned int height, char sn_heat, char sn_body, char mp_wall, char mp_ground, char fo_symbol)
{
	srand(time(NULL));
	
	map_width = width;
	map_height = height;
	
	map = new char* [width];

	for (int i = 0; i < width; i++)
	{
		map[i] = new char[height];
	}

	snake_heat_simbol = sn_heat;
	snake_body_simbol = sn_body;

	map_wall = mp_wall;
	map_ground = mp_ground;

	snake = new Snake(width);

	food_symbol = fo_symbol;

	SpavnFood();
}



void Map::PrintMap()
{
	for (int i = 0; i < map_width; ++i)
	{
		for (int j = 0; j < map_height; ++j)
		{
			std::cout << map[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void Map::Tick(char move_snake)
{
	snake->SetDirection(move_snake);

	if( (*snake).GetHeatIterator()->first == food_location.first &&
			(*snake).GetHeatIterator()->second == food_location.second)
	{
		snake->AddElement();
		SpavnFood();
	}
	
	FillMap();
	PrintMap();
}

void Map::SpavnFood()
{
	food_location.first = (rand() % map_width);
	food_location.second = (rand() % map_height);
}


void Map::FillMap()
{
	//Snake& snake;
	
	for (int i = 0; i < map_width; ++i)
	{
		for (int j = 0; j < map_height; ++j)
		{
			if (i == 0 || i == map_width - 1)
			{
				map[i][j] = map_wall;
			}
			else
			{
				if (j == 0 || j == map_height - 1)
					map[i][j] = map_wall;
				else
					map[i][j] = map_ground;
			}
		}
	}
	
	
	
	for(int i = 0; i < (*snake).GetArr().size(); i++)
	{
		if((*snake).GetArr()[i] == *((*snake).GetHeatIterator()))
		{
			map
			[(*snake).GetArr()[i].first]
			[(*snake).GetArr()[i].second] = snake_heat_simbol;

			continue;
		}
		
		map
		[(*snake).GetArr()[i].first]
		[(*snake).GetArr()[i].second] = snake_body_simbol;

	}

	map[food_location.first][food_location.second] = food_symbol;

	/*
	 *	std::vector<std::pair<int, int>> snake_l;
	int j = snake.GetHeatIndex();
	
	for(int i = 0; i < snake.GetArr().size(); i++)
	{
		if(j == snake.GetArr().size())
		{
			j = 0;
		}

		if(i == 0)
		{
			map[snake.GetArr()[j].first][snake.GetArr()[j].second] = '%';
		}
		else
		{
			map[snake.GetArr()[j].first][snake.GetArr()[j].second] = '*';
		}

		j++;
	}*/

}



