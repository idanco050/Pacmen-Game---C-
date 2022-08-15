#pragma once
#ifndef GHOST_H
#define GHOST_H
#include <string>
#include <vector>
#include <time.h>
#include "off game.h"
#include "entity.h"
class Ghost : public entity
{
public:
	Ghost(int _x, int _y);
	void move(Board& gameboard, Offgame& gameplay, const int choice[], int mode, ofstream& save, ofstream& result, ifstream& loud);
	double vector_to_pacman(int x_pac, int y_pac, int x_gh, int y_gh);
	bool pac_ghost_meet(int x_pac, int y_pac, Offgame& gameplay);
	void reg_move(Board& gameboard, Offgame& gameplay, const int choice[]);
	void smart_move(Board& gameboard);
	void set_pacman_xy(int x, int y);
	vector<char> get_vector_gh();
	void set_vector_gh(char c);
private:
	char direc;
	int move_cnt;
	vector<char> m_gh;
	int x_to_chase;
	int y_to_chase;
};
#endif // !GHOST_H

