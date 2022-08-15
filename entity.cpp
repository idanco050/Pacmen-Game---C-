#include "entity.h"

int entity::getx()
{
	return x;
} //getter for x
int entity:: gety()
{
	return y;
}  //getter for y
void entity::setx(int new_x)
{
	x = new_x;
} // setter for x
void entity::sety(int new_y)
{
	y = new_y;
} // setter for y
char entity::getsign()
{
	return sign;
} // getter for sign char