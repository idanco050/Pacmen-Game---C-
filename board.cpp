#include"board.h"
void Board::setboard(char** game_board)
{
	gameboard = game_board;
} //sets game board
void Board::setrows(int num_rows)
{
	rows = num_rows;
} // sets number of rows after reading from file
void Board::setcols(int num_cols)
{
	cols = num_cols;
}//sets number of columns after reading from file
void Board::printboard()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			std::cout << gameboard[i][j];
		}
		std::cout << endl;
	}
}//prints board
void Board::printframe_board()
{
	for (int k = 1; k <= 6; k++)// FRAME OF BOARD
	{
		int r = 12;
		int c = 79;
		{
			gameboard[r - 1][c - k] = '#';
			gameboard[r + 1][c - k] = '#';
		}
	}
	for (int k = 1; k <= 6; k++)
	{
		int r = 12;
		int c = 0;
		{
			gameboard[r - 1][c + k] = '#';
			gameboard[r + 1][c + k] = '#';
		}
	}
	for (int k = 1; k <= 6; k++)
	{
		int r = 0;
		int c = 39;
		{
			gameboard[r + k][c + 1] = '#';
			gameboard[r + k][c - 1] = '#';
		}
	}
	for (int k = 1; k <= 6; k++)
	{
		int r = 24;
		int c = 39;
		{
			gameboard[r - k][c + 1] = '#';
			gameboard[r - k][c - 1] = '#';
		}
	}
}
void Board::printcenterframe_board()
{
	for (int d = 0; d < 14; d++) //FRAME OF CENTER BOARD
	{
		gameboard[14][32 + d] = '#';
	}
	for (int i = 1; i < 6; i++)
	{
		gameboard[15 - i][32] = '#';
		gameboard[15 - i][46] = '#';

	}
	for (int i = 0; i < 6; i++)
	{
		gameboard[10][33 + i] = '#';
		gameboard[10][45 - i] = '#';
	}

	for (int d = 0; d < 18; d++) //BIGGER FRAME 2 OF CENTER BOARD
	{
		gameboard[16][31 + d] = '#';
	}
	for (int i = 1; i < 10; i++)
	{
		gameboard[17 - i][30] = '#';
		gameboard[17 - i][48] = '#';

	}
	for (int i = 0; i < 10; i++)
	{
		gameboard[8][31 + i] = '#';
		gameboard[8][47 - i] = '#';
	}
	gameboard[8][39] = ' ';
	gameboard[10][39] = ' ';
	gameboard[10][38] = ' ';
	gameboard[10][40] = ' ';
}
void Board::printblocks_board()
{
	int r = 5;
	int c = 17;
	for (int i = 0; i < 2; i++) //BLOCKS A
	{

		gameboard[r][c] = '#';
		gameboard[r + 1][c] = '#';
		gameboard[r + 2][c] = '#';
		gameboard[r + 3][c] = '#';
		gameboard[r][c + 1] = '#';
		gameboard[r + 1][1 + c] = '#';
		gameboard[r + 2][1 + c] = '#';
		gameboard[r + 3][1 + c] = '#';
		gameboard[r][c + 2] = '#';
		gameboard[r + 1][c + 2] = '#';
		gameboard[r + 2][c + 2] = '#';
		gameboard[r + 3][c + 2] = '#';
		gameboard[r][c + 3] = '#';
		gameboard[r + 1][c + 3] = '#';
		gameboard[r + 2][c + 3] = '#';
		gameboard[r + 3][c + 3] = '#';
		gameboard[r][c + 4] = '#';
		gameboard[r + 1][c + 4] = '#';
		gameboard[r + 2][c + 4] = '#';
		gameboard[r + 3][c + 4] = '#';
		r = r + 11;
		gameboard[r][c] = '#';
		gameboard[r + 1][c] = '#';
		gameboard[r + 2][c] = '#';
		gameboard[r + 3][c] = '#';
		gameboard[r][c + 1] = '#';
		gameboard[r + 1][1 + c] = '#';
		gameboard[r + 2][1 + c] = '#';
		gameboard[r + 3][1 + c] = '#';
		gameboard[r][c + 2] = '#';
		gameboard[r + 1][c + 2] = '#';
		gameboard[r + 2][c + 2] = '#';
		gameboard[r + 3][c + 2] = '#';
		gameboard[r][c + 3] = '#';
		gameboard[r + 1][c + 3] = '#';
		gameboard[r + 2][c + 3] = '#';
		gameboard[r + 3][c + 3] = '#';
		gameboard[r][c + 4] = '#';
		gameboard[r + 1][c + 4] = '#';
		gameboard[r + 2][c + 4] = '#';
		gameboard[r + 3][c + 4] = '#';
		c = c + 41;
		r = r - 11;
	}

	for (int i = 2; i < 19; i++)//BLOCKS B
	{
		gameboard[2][i] = '#';
		gameboard[3][i] = '#';
		gameboard[22][i] = '#';
		gameboard[21][i] = '#';
		gameboard[2][79 - i] = '#';
		gameboard[3][79 - i] = '#';
		gameboard[22][79 - i] = '#';
		gameboard[21][79 - i] = '#';
		gameboard[2][i + 18] = '#';
		gameboard[3][i + 18] = '#';
		gameboard[22][i + 18] = '#';
		gameboard[21][i + 18] = '#';
		gameboard[2][61 - i] = '#';
		gameboard[3][61 - i] = '#';
		gameboard[22][61 - i] = '#';
		gameboard[21][61 - i] = '#';
	}
	gameboard[2][42] = '#';
	gameboard[3][42] = '#';
	gameboard[22][42] = '#';
	gameboard[21][42] = '#';
	for (int j = 5; j < 10; j++) // BLOCKS C
	{
		for (int k = 2; k < 16; k++)
		{
			gameboard[j][k] = '#';
			gameboard[j + 10][k] = '#';
			gameboard[j][k + 62] = '#';
			gameboard[j + 10][k + 62] = '#';
		}
	}
	for (int h = 5; h < 7; h++)
	{
		for (int c = 23; c < 37; c++)
		{
			gameboard[h][c] = '#';
			gameboard[h + 13][c] = '#';
			gameboard[h][c + 19] = '#';
			gameboard[h + 13][c + 19] = '#';
		}
	}
	gameboard[5][56] = '#';
	gameboard[6][56] = '#';
	for (int h = 10; h < 15; h++)
	{
		for (int c = 17; c < 29; c++)
		{
			gameboard[h][c] = '#';
			gameboard[h][c + 33] = '#';
		}
	}

	for (int c = 23; c < 29; c++)
	{
		gameboard[8][c] = '#';
		gameboard[8][c + 27] = '#';
		gameboard[16][c] = '#';
		gameboard[16][c + 27] = '#';
	}
	gameboard[8][56] = '#';
	gameboard[16][56] = '#';
	for (int r = 10; r < 14; r++)
	{
		for (int c = 8; c < 16; c++)
		{
			if (r != 12)
			{
				gameboard[r][c] = '#';
				gameboard[r][c + 55] = '#';
			}
		}
	}
	gameboard[12][22] = 'R';
	gameboard[12][23] = 'A';
	gameboard[12][24] = 'Z';
	gameboard[12][54] = 'I';
	gameboard[12][55] = 'D';
	gameboard[12][56] = 'A';
	gameboard[12][57] = 'N';
	for (int i = 0; i < 4; i++)
	{
		if (i != 2)
		{
			gameboard[10 + i][71] = '#';
		}
	}
	gameboard[18][56] = '#';
	gameboard[19][56] = '#';
}
void Board::createObstacles()
{
	printframe_board();
	printcenterframe_board();
	printblocks_board();
}//fill the board with walls and frames 
void Board::fillFood()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			if (gameboard[i][j] != '#')// && (i!=12 && ((j<24 && j>22) || j<58 && j>53)))
			{
				gameboard[i][j] = '.';
			}
		}
	}
} // fills the board with food
char Board::getcell(int x, int y)
{
	return gameboard[x][y];
}
int Board::getrows()
{
	return rows;
}
int Board::getcols()
{
	return cols;
}
void Board::setcell(int x, int y, char c)
{
	gameboard[x][y] = c;
	return;
}
void Board::print_pac_ghost(int x_pac, int y_pac, vector<System::point> arr, int x_f, int y_f, int alive, char sign, System s, int flag, const int choice[], int mode)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (choice[0] == 2)
	{
		SetConsoleTextAttribute(hConsole, 14);
	}
	s.gotoxy(x_pac, y_pac);
	std::cout << '@' << endl;
	if (choice[0] == 2)
	{
		SetConsoleTextAttribute(hConsole, 15);
	}
	if (flag == 1)
	{
		if (choice[0] == 2)
		{
			SetConsoleTextAttribute(hConsole, 12);
		}
		for (int i = 0; i < arr.size(); i++)
		{
			s.gotoxy(arr[i].x, arr[i].y);
			std::cout << '$' << endl;
		}
		if (choice[0] == 2)
		{
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
	if (alive == 1)
	{
		if (choice[0] == 2)
		{
			SetConsoleTextAttribute(hConsole, 10);
		}
		s.gotoxy(x_f, y_f);
		std::cout << sign << endl;
		if (choice[0] == 2)
		{
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
	if (mode == 1)
	{
		Sleep(12);
	}
	else
	{
	    Sleep(60);
    }
	s.gotoxy(x_f, y_f);
	std::cout << ' ' << endl;
	s.gotoxy(x_pac, y_pac);
	std::cout << ' ' << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		s.gotoxy(arr[i].x, arr[i].y);
		std::cout << ' ' << endl;
	}
	for (int i = 0; i < arr.size(); i++)
	{
		if (gameboard[arr[i].y][arr[i].x] == '.')
		{
			s.gotoxy(arr[i].x, arr[i].y);
			std::cout << '.' << endl;
		}
	}
	if (gameboard[y_f][x_f] == '.') // prevent fruit from make food disapeer
	{
		s.gotoxy(x_f, y_f);
		std::cout << "." << endl;
	}
}