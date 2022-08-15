#pragma once
#ifndef PACMAN_H
#define PACMAN_H
#define EATALLFOOD 715
#include<iostream>
#include <string>
#include <vector>
#include "entity.h"
#include "gameplay.h"
#include "ghost.h"
using namespace std;
class Pacman : public entity
{
public:
	Pacman(int pac_x, int pac_y);
	void move(Board& TheGameBoard, Offgame& gameplay, const int choice[], int mode, ofstream& save, ofstream& result, ifstream& loud);//function that initiats the pacman game.
	void paclanding_act(Board& TheGameBoard, char& c, Offgame& gameplay, int& breadcrumbs); // function that prevent pacman from hitting the walls and creates eating food method
	void tunnleTeleport(char c, int& _x, int& _y, Offgame& game); // function that checks if the pacman is locate in tunnel coordinate
	int get_initx(); // function to get initiate pacman x to respawn the pac.
	int get_inity();// function to get initiate pacman y to respawn the pac.
	void set_arr(vector<System::point> arr); // function to set points of ghost init spawn.
	void update_ghost_arr(vector<Ghost> arr);// function to update locations of ghosts while game running
	vector<char> get_vector_pac();
private:
	int init_x;
	int init_y;
	vector<char> m_pac;
	vector<System::point> ghost_arr;
};
#endif