#pragma once
#ifndef FRUIT_H
#define FRUIT_H
#include "off game.h"
#include "entity.h"
class fruit : public entity 
{
public:
	fruit();
	void set_random_char();
	void move(Board& TheGameBoard, Offgame& gameplay, const int choice[], int mode, ofstream& save, ofstream& result, ifstream& loud);
	bool pac_fruit_meet(int x_pac, int y_pac, vector<System::point> arr, Offgame& gameplay);
	vector<char> get_vector_fr();
private:
	char direc;
	vector<char> fruit_m;
};
#endif // !FRUIT