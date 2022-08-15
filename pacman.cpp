#include "pacman.h"
Pacman::Pacman(int pac_x, int pac_y)
{
	sign = '@';
	x = pac_x;
	init_x = pac_x;
	y = pac_y;
	init_y = pac_y;
}
int Pacman::get_initx()
{
	return init_x;
}
int Pacman::get_inity()
{
	return init_y;
}
void Pacman::update_ghost_arr(vector<Ghost> arr)
{
	for (int i = 0; i < ghost_arr.size(); i++)
	{
		ghost_arr[i].x = arr[i].getx();
		ghost_arr[i].y = arr[i].gety();
	}
}
void Pacman::paclanding_act(Board& TheGameBoard,char& c, Offgame& gameplay, int& breadcrumbs)
{
	if ((TheGameBoard).getcell(y, x) == '#') // if pacman hits walls
	{
		switch (c)
		{
		case UP:
		case UP_L:
		{
			++(y);
			c = STAY;
			return;
		}
		case DOWN:
		case DOWN_L:
		{
			--(y);
			c = STAY;
			return;;
		}
		case RIGHT:
		case RIGHT_L:
		{
			--(x);
			c = STAY;
			return;
		}
		case LEFT:
		case LEFT_L:
		{
			++(x);
			c = STAY;
			return;;
		}
		}
	}
	else if ((TheGameBoard).getcell(y, x) == '.' && c != STAY)
	{
		(TheGameBoard).setcell(y, x, ' ');
		(gameplay).updateScore(1);
		breadcrumbs++;
	}
}
void Pacman::set_arr(vector<System::point> arr)
{
	ghost_arr = arr;
}
void Pacman::move(Board& TheGameBoard, Offgame& gameplay, const int choice[], int mode, ofstream& save, ofstream& result, ifstream& loud)//function that initiats the pacman game.
{
	int eaten = 0; // do not checks if ghost eat pacman after pac mov if after ghost move pac was eaten 
	System s;
	int gh_size = ghost_arr.size();
	vector <Ghost> GH_ARR;//vector of ghosts
	Ghost curr(5,5);
	for (int i = 0; i < gh_size; i++)// enter ghosts to vector
	{
		curr.setx(ghost_arr[i].y);
	    curr.sety(ghost_arr[i].x);
		GH_ARR.push_back(curr);
	}
	fruit F;
	int numofbreadcrumbs = 0;char fruit_char;
	int cnt_dis = 40; // count moves and changing bin_alive 
	int cnt_move = 0; // fruits moves once in a 3 pacman moves so i count them
	int bin_alive = -1; // -1 if fruit is not shown 1 if fruit is shown
	system("cls");_flushall();
	TheGameBoard.printboard(); // print the board
	gameplay.printScore();
	char c = STAY;
	char lastc;
	int move_gh = 1;
	int flag = 1;
	int over = 0;
	int pot =  0;
	if (mode == 1 || mode == 3)// 1 for load silent and 3 for regular load
	{
		char in;
		in = loud.get();
		while (in != ':') // counting number of rows and cols for the game board
		{
			in = loud.get();
		}
		in = loud.get();
		in = loud.get();
		while (in != '\n')
		{
			m_pac.push_back(in);
			in = loud.get();
			in = loud.get();
		}
		for (int i = 0; i < GH_ARR.size(); i++)
		{
			in = loud.get();
			while (in != ':') // counting number of rows and cols for the game board
			{
				in = loud.get();
			}
			in = loud.get();
			in = loud.get();
			while (in != '\n')
			{
				GH_ARR[i].set_vector_gh(in);
				in = loud.get();
				in = loud.get();
			}
		}
	}
	while (!_kbhit() || _getch() != 27 || mode == 1 || mode == 3)// esc (Ascii 27) ends the loop
	{
		if ((pot + 1) == m_pac.size())
		{
			break;
		}
			pot++;
			lastc = c;
			/*if (gameplay.are_we_in_tunnel(x,y) == true) //tunnels check
			{
				tunnleTeleport(c, x, y, gameplay);
			}*/
			flag = flag * (-1); // make ghost move twice slowly than pacman
			if (mode == 2 || mode == 4)
			{
				paclanding_act(TheGameBoard, c, gameplay, numofbreadcrumbs); //make pacman eat food and avoid walls
				char file_char = c;
				switch (file_char)
				{
				case UP:
				case UP_L:
				{
					file_char = 'U';
					break;
				}
				case DOWN:
				case DOWN_L:
				{
					file_char = 'D';
					break;
				}
				case RIGHT:
				case RIGHT_L:
				{
					file_char = 'R';
					break;
				}
				case LEFT:
				case LEFT_L:
				{
					file_char = 'L';
					break;
				}
				case STAY:
				case STAY_L:
				{
					file_char = 'S';
					break;
				}
				}
				m_pac.push_back(file_char);
			}
			if (flag == 1) // moving ghosts
			{
				for (int k = 0; k < GH_ARR.size(); k++)
				{
					GH_ARR[k].set_pacman_xy(x, y);
					GH_ARR[k].move(TheGameBoard, gameplay, choice, mode, save, result,loud);
				}
			}//moving ghost
			if (cnt_dis == 40)
			{
				bin_alive = bin_alive * (-1);
				if (bin_alive == 1)
				{
					F.set_random_char();
					fruit_char = F.getsign();
				}
				cnt_dis = 0;
			}
			if (bin_alive == 1)
			{
				if (F.pac_fruit_meet(x, y, ghost_arr, gameplay) == true)
				{
					bin_alive = -1;
					cnt_dis = 0;
					cnt_move = 0;
				}
			}
			eaten = 0;
			for (int d = 0; d < ghost_arr.size(); d++)
			{
				if (GH_ARR[d].pac_ghost_meet(x, y, gameplay))
				{
					gameplay.updateLifes();
					result << pot;
					result << " ";
					result << "Dead\n";
					x = get_initx();
					y = get_inity();
					eaten = 1;
				}
			}
			update_ghost_arr(GH_ARR);
			TheGameBoard.print_pac_ghost(x, y, ghost_arr, F.getx(), F.gety(), bin_alive, fruit_char, s, flag, choice, mode); // print out pacman and ghost
			if (_kbhit())
			{
				c = _getch();
				if (mode == 2 || mode == 4 || mode == 0)
				{
					if (c == 27) // deals with "esc" pausing game
					{
						gameplay.pause_mode();
					}
					if (c != UP && c != DOWN && c != LEFT && c != RIGHT && c != STAY && c != 'w' && c != 'x' && c != 'd' && c != 'a' && c != 's')// Deals with invalid inputs
					{
						c = lastc;
					}
				}
			}
			if (mode == 1 || mode == 3)
			{
				c = m_pac[pot];
				switch (c)
				{
				case 'U':
				{
					--y;
					break;
				}
				case 'D':
				{
					++y;
					break;
				}
				case 'R':
				{
					++x;
					break;
				}
				case 'L':
				{
					--x;
					break;
				}
				case 'S':
				{
					break;
				}
				}
			}
			else
			{
				switch (c) // deals with changing directions of the pacman
				{
				case UP:
				case UP_L:
				{
					--y;
					break;
				}
				case DOWN:
				case DOWN_L:
				{
					++y;
					break;
				}
				case RIGHT:
				case RIGHT_L:
				{
					++x;
					break;
				}
				case LEFT:
				case LEFT_L:
				{
					--x;
					break;
				}
				case STAY:
				case STAY_L:
				{
					break;
				}
				}
			}
			
			for (int d = 0; d < ghost_arr.size(); d++)
			{
				if (GH_ARR[d].pac_ghost_meet(x, y, gameplay))
				{
					if (eaten != 1)
					{
						gameplay.updateLifes();
						result << pot;
						result << " ";
						result << "Dead\n";
					}
					x = get_initx();
					y = get_inity();
				}
			}
			if (bin_alive == 1)
			{
				if (F.pac_fruit_meet(x, y, ghost_arr, gameplay) == true)
				{
					bin_alive = -1;
					cnt_dis = 0;
					cnt_move = 0;
				}
				else if (cnt_move == 3)
				{
					F.move(TheGameBoard, gameplay, choice, mode, save, result, loud);
					cnt_move = 0;
				}
				cnt_move++;
			}
			cnt_dis++;
			if (numofbreadcrumbs == gameplay.get_food()) // win scenerio
			{
				gameplay.winDeclare();
				result << pot;
				result << " ";
				result << "Win\n";
				break;
			}
			if (gameplay.getLifes() <= 0) // lose scenerio
			{
				gameplay.lossDeclare();
				break;
			}
		
	}
	if (mode == 2 || mode == 4)
	{
		save << "Pacman : ";
		for (int j = 0; j < get_vector_pac().size(); j++)
		{
			save << get_vector_pac()[j];
			save << " ";
		}
		save << "\n";
		for (int k = 0; k < GH_ARR.size(); k++)
		{
			save << "Ghost : ";
			for (int j = 0; j < GH_ARR[k].get_vector_gh().size(); j++)
			{
				save << GH_ARR[k].get_vector_gh()[j];
				save << " ";
			}
			save << "\n";
		}
	}
}
void Pacman::tunnleTeleport(char c, int& _x, int& _y, Offgame& game)
{
	if (c == LEFT || c == LEFT_L)
	{
		(_x) = game.get_edge_right();
	}
	if (c == RIGHT || c == RIGHT_L)
	{
		(_x) = game.get_edge_left();
	}
	if (c == UP || c == UP_L)
	{
		(_y) = game.get_edge_down();
	}
	if (c == DOWN || c == DOWN_L)
	{
		(_y) = game.get_edge_up();
	}
	return;
} //function that deals with moving the pacman in the tunnels
vector<char> Pacman::get_vector_pac()
{
	return m_pac;
}







