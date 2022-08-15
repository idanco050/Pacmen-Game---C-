#pragma once
#ifndef SYSTEM_H
#define  SYSTEM_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>
using namespace std;
class System
{
public:
	struct point
	{
		int x;
		int y;
	};
	struct fruit_move
	{
		int x;
		int y;
		int app;
	};
	void gotoxy(int, int);
	void clrscr();
private:
};
#endif // !SYSTEM_H