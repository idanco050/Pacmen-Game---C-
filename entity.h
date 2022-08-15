#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include "off game.h"
class entity
{
public:
	struct point_dir
	{
		int x;
		int y;
		direction dir;
	};
	int getx();
	int gety();
	void setx(int new_x);
	void sety(int new_y);
	char getsign();
	virtual void move(Board& TheGameBoard, Offgame& gameplay, const int choice[], int mode, ofstream& save, ofstream& result, ifstream& loud)=0;
protected:
	int x;
	int y;
	char sign;
};
#endif 