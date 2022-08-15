#pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "pacman.h"
#include "fruit.h"
class Gameplay
{
public:
	int mode_status(char** argv);
	void startgame(Offgame& gameplay, int mode);
};
#endif // !GAMEPLAY