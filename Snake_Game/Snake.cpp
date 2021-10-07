#include "Snake.h"


Snake::Snake(unsigned int map_width)
{
	snake_length.reserve(map_width * map_width);

	int width = map_width / 2;

	snake_length.push_back(std::pair<int, int>(width, width));

	snake_direction.first = 1;
	snake_direction.second = 0;
	
	//head_index = 0;
	head_iterator = snake_length.begin();
}

void Snake::SetDirection(char a)
{
	switch (a)
	{
		case 'w':
		{
			snake_direction.first = -1;
			snake_direction.second = 0;

			break;
		}

		case 's':
		{
			snake_direction.first = 1;
			snake_direction.second = 0;

			break;
		}
		case 'a':
		{
			snake_direction.first = 0;
			snake_direction.second = -1;

			break;
		}
		case 'd':
		{
			snake_direction.first = 0;
			snake_direction.second = 1;

			break;
		}
		default:
		{
			break;
		}
	}
	
	head_iterator += 1;

	if(head_iterator != snake_length.end())
	{
		(*head_iterator).first = (*(head_iterator - 1)).first + snake_direction.first;
		(*head_iterator).second = (*(head_iterator - 1)).second + snake_direction.second;
	}
	else
	{
		snake_length[0].first = (*(head_iterator - 1)).first + snake_direction.first;
		snake_length[0].second = (*(head_iterator - 1)).second + snake_direction.second;

		head_iterator = snake_length.begin();
	}


	/*

	head_index += 1;

	if (snake_length.size() > head_index)
	{

		snake_length[head_index].first  = snake_length[head_index - 1].first + snake_direction.first;
		snake_length[head_index].second = snake_length[head_index - 1].second + snake_direction.second;

		
		if (snake_length[head_index].first >= 16)
			snake_length[head_index].first = 0;
		if (snake_length[head_index].first < 0)
			snake_length[head_index].first = 16;
	}
	else
	{
		snake_length[0].first = snake_length[head_index-1].first + snake_direction.first;
		snake_length[0].second = snake_length[head_index-1].second + snake_direction.second;
		
		head_index = 0;
	}*/
	
}


void Snake::AddElement()
{

	//head_iterator = snake_length.begin();
	//head_iterator += head_index;

	int index = 0;
	for (; ; index++)
	{
		if (snake_length[index] == *head_iterator)
		{
			break;
		}
	}
	
	snake_length.insert(head_iterator, *head_iterator);

	head_iterator = snake_length.begin();
	head_iterator += index;


	/*
	snake_length.push_back(std::pair<int, int>(
		snake_length[0].first, 
		snake_length[0].second));

	std::cout << (*HeadIterator).second << std::endl;
	*/
}

