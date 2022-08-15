#include "gameplay.h"
int main(int argc, char* argv[]) // main 
{
	Gameplay gameplay;
	Offgame offgame;
	int mode = gameplay.mode_status(argv);
	gameplay.startgame(offgame, mode);
}