#include "off game.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
namespace fs = std::filesystem;
using namespace std;
int Offgame:: get_edge_down()
{
	return edge_down;
}
int Offgame::get_edge_left()
{
	return edge_left;
}
int Offgame::get_edge_right()
{
	return edge_right;
}
int Offgame::get_edge_up()
{
	return edge_top;
}
bool Offgame::are_we_in_tunnel(const int x, const int y)
{
	if ((y == edge_top) || (y == edge_down) || (x == edge_left) || (x == edge_right))
	{
		return true;
	}
	return false;
}
void Offgame::set_edges(Board& board)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (edge_top == -1)
	{
		if (board.getcell(i,0) == '#')
		{
			edge_top = i;
		}
		i++;
	}
	i = edge_top;
	for (int j = edge_top;j<board.getrows() - 1;j++)
	{
		if (board.getcell(j+1, 0) == ' ')
		{
			edge_down = j;
		}
	}
	if (j == board.getrows() - 1)
	{
		edge_down = board.getrows();
	}
	for (int k = 0; k < board.getcols() - 1; k++)
	{
		if (board.getcell(edge_top, k+1) == ' ')
		{
			edge_right = k;
		}
	}
	if (k == board.getcols() - 1)
	{
		edge_right = board.getcols();
	}

}
void Offgame::implement_food()
{
	num_of_breadcrumbs++;
}
int Offgame::get_food()
{
	return num_of_breadcrumbs;
}
void Offgame::set_food(int food)
{
	num_of_breadcrumbs = food;
}
void Offgame::printMenu()
{
	System S;
	S.clrscr();
	print_frame();
	S.gotoxy(31, 7);
	cout << "(1) Start a new game";
	S.gotoxy(31, 8);
	cout << "(2) Start a new game with colors";
	S.gotoxy(31, 9);
	cout << "(8) Present instructions and keys";
	S.gotoxy(31, 10);
	cout << "(9) Exit";
}//Function that prints menu
void Offgame::loading_maps(int choice, vector <string> &maps)
{
	System s;
	if (choice == 1)
	{
		system("cls");
		string filename;// filename
		cout << "enter file name: " << endl;
		s.gotoxy(38, 17);
		cin >> (filename);
		maps.push_back(filename);
	}
	if (choice == 2)
	{
		string path("C:/Users/IdanC/Desktop/project-pacman (1)/project");
		string ext(".screen");
		for (auto& p : fs::recursive_directory_iterator(path))
		{
			if (p.path().extension() == ext)
			{
				maps.push_back(p.path().stem().string());
			}
		}
	}
}
void Offgame::print_frame()
{
	System S;
	S.gotoxy(30, 2);
	cout << "__________________________________________________";
	for (int i = 3; i < 16; i++)
	{
		S.gotoxy(80, i);
		cout << "|";
	}
	S.gotoxy(30, 15);
	cout << "__________________________________________________";
	for (int i = 3; i < 16; i++)
	{
		S.gotoxy(30, i);
		cout << "|";
	}

}//function that prints frame for menu (to improve ui)
int Offgame::getChoice()
{
	int choose;
	System s;
	s.gotoxy(38, 16);
	cin >> choose;
	while ((choose != 1) && (choose != 8) && (choose != 9) && (choose != 2))
	{
		cout << "Invalid choice, please try again!" << endl;
		cout << "please enter 1,2,8 or 9" << endl;
		cin >> choose;
	}
	return choose;
}//function that gets menu input from user 
void Offgame::printScore()
{
	System s;
	s.gotoxy(legx, legy);
	cout << "Your score :" << score;
	cout << "            Remaining Life :" << lifes;
}//function that prints scor and lifes in screen bottom
void Offgame::addmove()
{
	cnt_smartmoves++;
}
int Offgame::getmove()
{
	return cnt_smartmoves;
}
void Offgame::setmove()
{
	cnt_smartmoves = 0;
}
void Offgame::updateScore(int num)//function that add score point to the scoreboard
{
	score= score + num;
	printScore();
}
void Offgame::updateLifes() // function that reduce life from the lifes board
{
	lifes--;
	printScore();
}
void Offgame::winDeclare()
{
	System s;
	s.clrscr();
	print_frame();
	s.gotoxy(31, 7);
	cout << "You win!!! you are the michael jorden of pacman!" << endl;
	s.gotoxy(31, 8);
	cout << "Press any key for menu" << endl;
}//function that prints out win declare
void Offgame::lossDeclare()
{
	System s;
	s.clrscr();
	print_frame();
	s.gotoxy(31, 7);
	cout << "You lose!!! you are so bad at this bro!" << endl;
	s.gotoxy(31, 8);
} //function that prints loss message after gameover
void Offgame::instruct_print()
{
	System s;
	s.clrscr();
	print_frame();
	s.gotoxy(31, 5);
	cout << "Your mission is to eat all the food in the" << endl;
	s.gotoxy(31, 6);
	cout << "board while avoiding the ghosts" << endl;
	s.gotoxy(31, 7);
	cout << "Press W for moving up" << endl;
	s.gotoxy(31, 8);
	cout << "Press D for moving down" << endl;
	s.gotoxy(31, 9);
	cout << "Press R for moving right" << endl;
	s.gotoxy(31, 10);
	cout << "Press L for moving left" << endl;
	s.gotoxy(31, 11);
}//function that print out game instruction 
void Offgame::set_score_life()
{
	score = 0;
	lifes = 3;
}////function that initiats 3 lifes and 0 score when the game starts.
void Offgame::pause_mode()
{
	System s;
	char c = 0;
	while (c != 27)
	{
		s.gotoxy(22, 0);
		cout << "~GAME PAUSED~ press ESC to continue";
		c = _getch();
	}
	s.gotoxy(22, 0);
	cout << "##########################################";
}//function that pauses the game
char Offgame::ghostLevel()
{
	System s;
	char ch;
	s.clrscr();
	print_frame();
	s.gotoxy(31, 7);
	cout << "please select the difficulty you wish to play!" << endl;
	s.gotoxy(31, 8);
	cout << "(a) BEST" << endl;
	s.gotoxy(31, 9);
	cout << "(b) GOOD" << endl;
	s.gotoxy(31, 10);
	cout << "(c) NOVICE" << endl;
	s.gotoxy(38, 16);
	cin >> ch;
	while (ch != 'a' && ch != 'b' && ch != 'c')
	{
		s.gotoxy(31, 11);
		cout << "invalid input! , please select again!" << endl;
		s.gotoxy(38, 16);
		cin >> ch;
	}
	return ch;
}
bool Offgame::not_valid_file(ifstream& in_file) // targil 3
{
	int cnt_pac = 0;
	char c;
	int cnt_gh = 0;
	int cnt_legend = 0;
	int cnt_char = 0;
	c = in_file.get();
	if (c == EOF)
	{
		return true;
	}
	while (c!= EOF)
	{
		if (c == '@')
		{
			cnt_pac++;
		}
		else if (c == '$')
		{
			cnt_gh++;
		}
		else if (c == '&')
		{
			cnt_legend++;
		}
		c = in_file.get();
	}
	if (cnt_pac != 1 || cnt_gh > 4 || cnt_legend != 1)
	{
		return true;
	}
	else
	{
		return false;
	}

}
int Offgame::get_size(fstream file)
{
	file.seekg(0, ios::end); // go to file end
	int size = file.tellg(); // get size of file
	file.seekg(0, ios::beg); // go to beg of file
	return size;
}
int Offgame::screen_choose()
{
	System s;
	int screen;
	s.clrscr();
	print_frame();
	s.gotoxy(31, 7);
	cout << "choose screen mode" << endl;
	s.gotoxy(31, 8);
	cout << "(1) Specific screen" << endl;
	s.gotoxy(31, 9);
	cout << "(2) From the start" << endl;
	s.gotoxy(38, 16);
	cin >> screen;
	while (screen != 1 && screen != 2)
	{
		s.gotoxy(31, 11);
		cout << "invalid input! , please select again!" << endl;
		s.gotoxy(38, 16);
	    cin >> screen;
	}
	return screen;
} //function to take user's screens input
