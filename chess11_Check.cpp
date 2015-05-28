#include "chess.h"
#include <iostream>
using std::cout;
using std::endl;

bool checkX(SC x)                 //check whether the X-coordinate input is valid
{
	if (x < '1' || x > '9')   //the range for x is [1,9]
	{
		cout << "Input invalid, please enter a number digit: ";
		return true;      //return TRUE if x is in the range
	}
	else
		return false;     //otherwise return FALSE
}

bool checkY(SC y)                 //check whether the Y-coordinate input is valid
{
	if (y < 'a' || y > 'j')   //the range for y is [a,j]
	{
		cout << "Input invalid, please enter a letter between A and J (inclusive): ";
		return true;      //return TRUE if y is in the range
	}
	else
		return false;     //otherwise return FALSE
}
