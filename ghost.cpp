#include"ghost.h"
Ghost::Ghost(int _x, int _y)
{
	x = _x;
	y = _y;
	sign = '$';
	direc = UP;
	x_to_chase = 0;
	y_to_chase = 0;
	move_cnt = 0;
}
void Ghost::set_pacman_xy(int x, int y)
{
	x_to_chase = x;
	y_to_chase = y;
} // sets for each ghost pacman x and y to chase /
double Ghost::vector_to_pacman(int x_pac, int y_pac, int x_gh, int y_gh)
{
	double sqrt_x = pow(x_pac - x_gh, 2);
	double sqrt_y = pow(y_pac - y_gh, 2);
	return sqrt(sqrt_x + sqrt_y);
}//function that calculate distance from possible ghost steps to pacman in order to evaluate shortest path to pacman
void Ghost::move(Board& gameboard, Offgame& gameplay ,const int choice[], int mode, ofstream& save, ofstream& result, ifstream& loud)
{
	if (mode == 1 || mode == 3)
	{
		char c = get_vector_gh()[move_cnt];
		switch (c) // make ghost move
		{
		case 'U':
		{
			--y;
			direc = UP;
			break;
		}
		case 'D':
		{
			++y;
			direc = DOWN;
			break;
		}
		case 'R':
		{
			++x;
			direc = RIGHT;
			break;
		}
		case 'L':
		{
			--x;
			direc = LEFT;
			break;
		}
		}
		move_cnt++;
	}
	else
	{
		if (choice[1] == 'a')
		{
			smart_move(gameboard);
		}
		if (choice[1] == 'b')
		{
			gameplay.addmove();
			if (gameplay.getmove() > 15)
			{
				smart_move(gameboard);
			}
			else
			{
				reg_move(gameboard, gameplay, choice);
			}
			if (gameplay.getmove() == 40)
			{
				gameplay.setmove();
			}
		}
		if (choice[1] == 'c')
		{
			reg_move(gameboard, gameplay, choice);
		}
	}
}//make the ghost move
bool Ghost::pac_ghost_meet(int x_pac, int y_pac, Offgame& gameplay)
{
	if (x_pac == x && y_pac == y)
	{
		return true;
	}
	return false;
} // checks if ghost & pacman meets
void Ghost::reg_move(Board& gameboard, Offgame& gameplay, const int choice[])
{
	int random = 0;
	int move = 0;
	char file_char;
	int random_move = 0;
	random = rand() % 4;
	switch (random) // make ghost move
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
		} // move ghost
		while (gameboard.getcell(y, x) == '#' || y == 0 || x == 0 || y == gameboard.getrows() || x == gameboard.getcols())
		{
			switch (direc) // return ghost to prev location
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
			switch (random) // make ghost move
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
		}
		file_char = direc;
		switch (file_char) // make ghost move
		{
		case UP:
		{
			file_char = 'U';
			break;
		}
		case DOWN:
		{
			file_char = 'D';
			break;
		}
		case RIGHT:
		{
			file_char = 'R';
			break;
		}
		case LEFT:
		{
			file_char = 'L';
			break;
		}
		}
		m_gh.push_back(file_char);
}
void Ghost::smart_move(Board& gameboard)
{
	char file_char;
	point_dir arr[3];
	if (this->direc == UP)
	{
		arr[0].x = x - 1; arr[0].y = y; arr[0].dir = LEFT;
		arr[1].x = x; arr[1].y = y-1; arr[1].dir = UP;
		arr[2].x = x + 1; arr[2].y = y; arr[2].dir = RIGHT;
		
	}
	else if (this->direc == RIGHT)
	{
		arr[0].x = x; arr[0].y = y - 1; arr[0].dir = UP;
		arr[1].x = x + 1; arr[1].y = y; arr[1].dir = RIGHT;
		arr[2].x = x; arr[2].y = y+1; arr[2].dir = DOWN;
	}
	else if (this->direc == DOWN)
	{
		arr[0].x = x + 1; arr[0].y = y; arr[0].dir = RIGHT;
		arr[1].x = x; arr[1].y = y + 1; arr[1].dir = DOWN;
		arr[2].x = x - 1; arr[2].y = y; arr[2].dir = LEFT;
	}
	else if (this->direc == LEFT)
	{
	arr[0].x = x; arr[0].y = y + 1; arr[0].dir = DOWN;
	arr[1].x = x - 1; arr[1].y = y; arr[1].dir = LEFT;
	arr[2].x = x; arr[2].y = y - 1; arr[2].dir = UP;
	}
	double max_move = 10000;
	double cur = 0;
	for (int i = 0; i < 3; i++)
	{
		if ((gameboard.getcell(arr[i].y, arr[i].x) != '#') && (arr[i].y != 0) && (arr[i].x != 0) && (arr[i].y != gameboard.getrows()) && (arr[i].x != gameboard.getcols()))
		{
			cur = (vector_to_pacman(x_to_chase, y_to_chase, arr[i].x, arr[i].y));
			if (cur < max_move)
			{
				max_move = cur;
				this->direc = arr[i].dir;
			}
		}
	}
	switch (this->direc) // make ghost move
	{
	case UP:
	{
		--y;
		break;
	}
	case DOWN:
	{
		++y;
		break;
	}
	case RIGHT:
	{
		++x;
		break;
	}
	case LEFT:
	{
		--x;
		break;
	}
	}
	file_char = direc;
	switch (file_char) // make ghost move
	{
	case UP:
	{
		file_char = 'U';
		break;
	}
	case DOWN:
	{
		file_char = 'D';
		break;
	}
	case RIGHT:
	{
		file_char = 'R';
		break;
	}
	case LEFT:
	{
		file_char = 'L';
		break;
	}
	}
	m_gh.push_back(file_char);
}
vector<char> Ghost::get_vector_gh()
{
	return m_gh;
}
void Ghost::set_vector_gh(char c)
{
	m_gh.push_back(c);
}




