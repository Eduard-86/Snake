#include "Map.h"
#include <iostream>

Map::Map(unsigned int width, unsigned int height, char sn_heat, 
	char sn_body, char mp_wall, char mp_ground, char fo_symbol, char cra_symbol)
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

	crash_synbol = cra_symbol;

	game_score = 0;
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
		game_score++;
	}
	
	FillMap();

	std::cout << "Очки :" << game_score << std::endl;
	std::cout << "Твои координаты :" << snake->GetHeatIterator()->first
		<< '-' << snake->GetHeatIterator()->second << std::endl;
	
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

	map[food_location.first][food_location.second] = food_symbol;
	
	std::vector<std::pair<int, int>>* SnakeArr = &(*snake).GetArr();
	std::vector<std::pair<int, int>>::iterator SnakeIterator = (*snake).GetHeatIterator();
	
	for(int i = 0; i < (*SnakeArr).size(); i++)
	{
		if((*SnakeArr)[i] == *(SnakeIterator))
		{
			map
			[(*SnakeArr)[i].first]
			[(*SnakeArr)[i].second] = snake_heat_simbol;

			continue;
		}
		
		map
		[(*SnakeArr)[i].first]
		[(*SnakeArr)[i].second] = snake_body_simbol;
	}

	
	if(SnakeIterator->first == 0 || SnakeIterator->first == (map_width-1) ||
		SnakeIterator->second == 0 || SnakeIterator->second == (map_height-1))
	{
		map[SnakeIterator->first][SnakeIterator->second] = crash_synbol;
		FooEnd(game_score);
	}

	
	

}



