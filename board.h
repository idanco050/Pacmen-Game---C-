#pragma once
#ifndef BOARD_H
#define BOARD_H
#include "system.h"
#include<iostream>
#include<vector>
using namespace std;
class Board
{
public:
	void printframe_board(); 
	void printcenterframe_board();
	void printblocks_board();
	void printboard();
	void createObstacles();
	char getcell(int x, int y);
	void setcell(int x, int y, char c);
	void fillFood();
	void setrows(int num_rows);
	void setcols(int num_cols);
	int getrows();
	int getcols();
	void setboard(char** game_board);
	void print_pac_ghost(int x_pac, int y_pac, vector <System::point> arr, int x_f, int y_f, int alive, char sign, System s, int flag, const int choice[], int mode);
private:
	int rows = 0;
	int cols = 0;
	char** gameboard;
};
#endif // !1
