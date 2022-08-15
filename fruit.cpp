#include "fruit.h" 
fruit::fruit()
{
	x = 4;
	y = 2;
	direc = DOWN;
}
void fruit::move(Board& TheGameBoard, Offgame& gameplay, const int choice[], int mode, ofstream& save, ofstream& result, ifstream& loud)
{
	int random = 0;
	int move = 0;
	random = rand() % 4;
	switch (random) // make fruit move
	{
	case 0:
	{
		--y;
		direc = UP;
		break;
	}
	case 1:
	{
		++y;
		direc = DOWN;
		break;
	}
	case 2:
	{
		++x;
		direc = RIGHT;
		break;
	}
	case 3:
	{
		--x;
		direc = LEFT;
		break;
	}
	
	}
	while (TheGameBoard.getcell(y, x) == '#' || y == 0 || x == 0 || y == TheGameBoard.getrows() || x == TheGameBoard.getcols())
	{
		switch (direc) // return fruit to prev location
		{
		case UP:
		{
			++y;
			break;
		}
		case DOWN:
		{
			--y;
			break;
		}
		case RIGHT:
		{
			--x;
			break;
		}
		case LEFT:
		{
			++x;
			break;
		}
		}
		random = rand() % 4;
		switch (random) // make fruit move
		{
		case 0:
		{
			--y;
			direc = UP;
			break;
		}
		case 1:
		{
			++y;
			direc = DOWN;
			break;
		}
		case 2:
		{
			++x;
			direc = RIGHT;
			break;
		}
		case 3:
		{
			--x;
			direc = LEFT;
			break;
		}
		}
		fruit_m.push_back(direc);
	}
}
	void fruit::set_random_char()
	{
		int random = rand() % 5;
		random = random + 5;
		char t = random + '0';
		sign = t;
	}//function that sets random value to the fruit
	bool fruit::pac_fruit_meet(int x_pac, int y_pac, vector<System::point> arr, Offgame& gameplay)
	{
		int val = sign - '0';
		if (x_pac == x && y_pac == y)
		{
			gameplay.updateScore(val);
			return true;
		}
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i].x == x && arr[i].y == y)
			{
				return true;
			}
		}
		return false;
	}//checks if fruit meets pacman or ghost
	vector<char> fruit::get_vector_fr()
	{
		return fruit_m;
	}
