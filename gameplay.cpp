#include "gameplay.h"
int Gameplay::mode_status(char** argv)
{
	if (strcmp(argv[1], "-load[-silent]") == 0) // 1 for load silent
	{
		return 1;
	}
	if (strcmp(argv[1], "-save[-silent]") == 0) // 2 for save
	{
		return 2;
	}
	if (strcmp(argv[1], "-load") == 0) // 3 for load no silent
	{
		return 3;
	}
	if (strcmp(argv[1], "-save") == 0) // 4 for save
	{
		return 4;
	}
	return 0; // not valid
}
void Gameplay::startgame(Offgame& off, int mode)
{
	int choice[3];
	System s;
	Board b;
	if (mode == 1 || mode == 3)// load mode
	{
		int pac_x; int pac_y;
		vector<System::point> gstarray; // array of the init x,y of ghost
		vector<string> maps;
		off.loading_maps(2, maps);
		off.set_score_life();// initiats scoreboard
		for (int i = 0; i < maps.size(); i++)
		{
			int cnt_ghost = 0; int col = 0; int row = 1; int col_run = 1; char in; bool not_valid = false;
			ifstream in_file(maps[i] + ".screen");
			not_valid = off.not_valid_file(in_file);
			in_file.clear();
			in_file.seekg(0, ios::beg);
			if (not_valid == false)
			{
				in = in_file.get();
				while (in != EOF) // counting number of rows and cols for the game board
				{
					if (in == '\n')
					{
						row++;
						if (col_run > col)
						{
							col = col_run;
						}
						col_run = 0;
					}
					col_run++;
					in = in_file.get();
				}
				char** game_board = new char* [row];//declare char** in the right size
				for (int j = 0; j < row; j++)
				{
					game_board[j] = new char[col];
				}
				b.setrows(row);
				b.setcols(col);
				for (int k = 0; k < row; k++)
				{
					for (int t = 0; t < col; t++)
					{
						game_board[k][t] = ' ';
					}
				}
				in_file.clear();
				in_file.seekg(0, ios::beg); // go to begin of file in order to implement the gameboard
				in = in_file.get(); int food = 0;
				int r = 0; int c = 0;//r and c for the implement of board
				while (in != EOF)
				{
					if (in == '\n')
					{
						r++;
						c = 0;
					}
					else if (in == '@')
					{
						pac_x = c;
						pac_y = r;
						c++;
					}
					else if (in == '$')
					{
						gstarray.push_back({ r,c });
						c++;
					}
					else if (in == '&')
					{
						off.initelegpos(c, r); // init legend position for printing out the score
						c++;
					}
					else if (in == '%')
					{
						game_board[r][c] = ' ';
						c++;
					}
					else if (in == '#')
					{
						game_board[r][c] = '#';
						c++;
					}
					else
					{
						game_board[r][c] = '.';
						food++;
						c++;
					}
					in = in_file.get();
				}
				ofstream save("demo1" + maps[i]);
				ofstream result("demo2" + maps[i]);
				ifstream loud("steps_" + maps[i]);
				//save << "Pacman, Ghosts & Fruit Steps\n";
				//result << "Pacman Deaths\n";
				off.set_food(food);
				b.setboard(game_board);
				off.set_edges(b);
				Pacman pac(pac_x, pac_y);
				pac.set_arr(gstarray);
				pac.move(b, off, choice, mode, save, result, loud);
				if (off.getLifes() <= 0)
				{
					i = maps.size();
				}
			}
			else
			{
				off.print_frame();
				s.gotoxy(31, 7);
				cout << "File isn't Valid";
				s.gotoxy(31, 9);
			}
		}
		
	}
	else
	{
		off.printMenu();
		choice[0] = off.getChoice();
		int pac_x; int pac_y;
		while (choice[0] != 9)
		{
			if (choice[0] == 1 || choice[0] == 2) // game play choice
			{
				choice[1] = off.ghostLevel();
				choice[2] = off.screen_choose();
				vector<System::point> gstarray; // array of the init x,y of ghost
				vector<string> maps;
				off.loading_maps(choice[2], maps);
				off.set_score_life();// initiats scoreboard
				for (int i = 0; i < maps.size(); i++)
				{
					int cnt_ghost = 0; int col = 0; int row = 1; int col_run = 1; char in; bool not_valid = false;
					ifstream in_file(maps[i] + ".screen");
					not_valid = off.not_valid_file(in_file);
					in_file.clear();
					in_file.seekg(0, ios::beg);
					if (not_valid == false)
					{
						in = in_file.get();
						while (in != EOF) // counting number of rows and cols for the game board
						{
							if (in == '\n')
							{
								row++;
								if (col_run > col)
								{
									col = col_run;
								}
								col_run = 0;
							}
							col_run++;
							in = in_file.get();
						}
						char** game_board = new char* [row];//declare char** in the right size
						for (int j = 0; j < row; j++)
						{
							game_board[j] = new char[col];
						}
						b.setrows(row);
						b.setcols(col);
						for (int k = 0; k < row; k++)
						{
							for (int t = 0; t < col; t++)
							{
								game_board[k][t] = ' ';
							}
						}
						in_file.clear();
						in_file.seekg(0, ios::beg); // go to begin of file in order to implement the gameboard
						in = in_file.get(); int food = 0;
						int r = 0; int c = 0;//r and c for the implement of board
						while (in != EOF)
						{
							if (in == '\n')
							{
								r++;
								c = 0;
							}
							else if (in == '@')
							{
								pac_x = c;
								pac_y = r;
								c++;
							}
							else if (in == '$')
							{
								gstarray.push_back({ r,c });
								c++;
							}
							else if (in == '&')
							{
								off.initelegpos(c, r); // init legend position for printing out the score
								c++;
							}
							else if (in == '%')
							{
								game_board[r][c] = ' ';
								c++;
							}
							else if (in == '#')
							{
								game_board[r][c] = '#';
								c++;
							}
							else
							{
								game_board[r][c] = '.';
								food++;
								c++;
							}
							in = in_file.get();
						}
						ofstream save("steps_" + maps[i]);
						ofstream result("result_" + maps[i]);
						ifstream loud("steps_" + maps[i]);
						save << "Pacman, Ghosts & Fruit Steps\n";
						result << "Pacman Deaths\n";
						off.set_food(food);
						b.setboard(game_board);
						off.set_edges(b);
						Pacman pac(pac_x, pac_y);
						pac.set_arr(gstarray);
						pac.move(b, off, choice, mode, save, result, loud);
						if (off.getLifes() <= 0)
						{
							i = maps.size();
						}
					}
					else
					{
						off.print_frame();
						s.gotoxy(31, 7);
						cout << "File isn't Valid";
						s.gotoxy(31, 9);
					}
				}
				system("pause");
				off.printMenu();
				choice[0] = off.getChoice();
				//int size = get_size(in_file); /*if (not_valid_file(in_file, size) == true){cout << "not valid file";}*/
				// get char from file
				// declare board	
			}
			if (choice[0] == 8) // instruction choice
			{
				off.instruct_print();
				system("pause");
				off.printMenu();
				choice[0] = off.getChoice();
			}
		}
	}
}//function that reads file create board and initiate the game.
