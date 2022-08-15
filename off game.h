#pragma once
#ifndef OFF_GAME_H
#define OFF_GAME_H
#include "board.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
enum direction {UP = 'W', UP_L = 'w', LEFT = 'A', LEFT_L = 'a', RIGHT = 'D', RIGHT_L = 'd',
	DOWN = 'X', DOWN_L = 'x', STAY = 'S', STAY_L = 's' };
using namespace std;
class Offgame
{
public:
	void set_food(int food);
	int get_edge_down();
	int get_edge_left();
	int get_edge_right();
	int get_edge_up();
	bool are_we_in_tunnel(const int x, const int y);
	void implement_food();
	int get_food();
	void set_edges(Board &board);
	void loading_maps(int choice, vector <string> &maps);
	void printMenu();
	int getChoice();
	void winDeclare();
	void lossDeclare();
	void instruct_print();
	int get_size(fstream file);
	bool not_valid_file(ifstream& in_file);
	void print_frame();
	void printScore();
	void updateScore(int num);
	void updateLifes();
	void addmove();
	int getLifes()
	{
		return lifes;
	}
	int getScore()
	{
		return score;
	}
	void set_score_life();
	void pause_mode();
	char ghostLevel();
	int getmove();
	void setmove();
	int screen_choose();
	void initelegpos(int _legx, int _legy)
	{
		legx = _legx;
		legy = _legy;
	};
private:
	int score = 0;
	int lifes = 3;
	int cnt_smartmoves = 0;
	int legx;
	int legy;
	int num_of_breadcrumbs;
	int edge_top = -1;
	int edge_down = -1;
	int edge_right = -1;
	int edge_left = 0;
};
#endif // !OFF_GAME_H