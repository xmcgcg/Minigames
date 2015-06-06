#include "chess.h"
using namespace CG;

Ju::Ju(SC x, SC y, const string& nm, color cl): Chess(x, y, nm, cl) {} //use Chess's constructor

bool Ju::move(SC x, SC y, const vector<Chess*>& ar)       //return TRUE if moving to (x,y) is valid, otherwise return FALSE
{
	if (x != Xcoord && y != Ycoord)                   //车 has to move horizontally or vertically
		return false;

	if (x == Xcoord && y != Ycoord)                   //if 车 wants to move vertically
	{
		SC min, max;                              //check whether other chesses are between
		min = y < Ycoord ? y : Ycoord;            //the destination and the current position of 车
		max = y > Ycoord ? y : Ycoord;
		min++;
		while (min < max)
		{
			for (auto ch : ar)                //iterate the container
				if (ch->compare(x, min))
					return false;     //return FALSE if a chess is found in between
			min++;
		}
	}

	if (x != Xcoord && y == Ycoord)                   //if 车 wants to move horizontally
	{
		SC min, max;                              //similar procedure as above
		min = x < Xcoord ? x : Xcoord;
		max = x > Xcoord ? x : Xcoord;
		min++;
		while (min < max)
		{
			for (auto ch : ar)
				if (ch->compare(min, y))
					return false;     //return FALSE if a chess is found in between
			min++;
		}
	}

	return true;                                      //since no chess is found in between, return TRUE
}

bool Ju::attack(SC x, SC y, const vector<Chess*>& ar)     //the moving method and the attacking method of 车 are the same
{
	return move(x, y, ar);                            //therefore call the move function here
}
