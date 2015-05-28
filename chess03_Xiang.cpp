#include "chess.h"
#include <cstdlib>
using std::abs;

Xiang::Xiang(SC x, SC y, const string& nm, color cl): Chess(x, y, nm, cl) {} use Chess's constructor

bool Xiang::move(SC x, SC y, vector<Chess*> ar) //return TRUE if the movement is valid, otherwise return FALSE
{
	if (Ycoord == 'e' && y > 'e')           //相/象 cannot cross the river
		return false;                   //if it tries to cross the river, return FALSE
	if (Ycoord == 'f' && y < 'f')           //same as above
		return false;
	int Xdif = abs(x - Xcoord);             //Xdif represents the number of columns to the destination
	int Ydif = abs(y - Ycoord);             //Ydif represents the number of rows to the destination
	if (Xdif == 2 && Ydif == 2)             //if both Xdif and Ydif are 2
	{
		if (x - Xcoord == 2)
		{
			if (y - Ycoord == 2)    //if 相/象 tries to move to bottom right corner
				for (auto ch : ar)
					if (ch->compare(x + 1, y + 1)) //if a chess is next to 相/象 at the corner
						return false;          //the move is invalid, return FALSE
			if (Ycoord - y == 2)    //if 相/象 tries to move to top right corner
				for (auto ch : ar)
					if (ch->compare(x + 1, y - 1)) //if a chess is next to 相/象 at the corner
						return false;          //the move is invalid, return FALSE
		}
		else
		{
			if (y - Ycoord == 2)    //if 相/象 tries to move to bottom left corner
				for (auto ch : ar)
					if (ch->compare(x - 1, y + 1)) //if a chess is next to 相/象 at the corner
						return false;          //the move is invalid, return FALSE
			if (Ycoord - y == 2)    //if 相/象 tries to move to top left corner
				for (auto ch : ar)
					if (ch->compare(x - 1, y - 1)) //if a chess is next to 相/象 at the corner
						return false;          //the move is invalid, return FALSE
		}
		return true;                          //if no chess blocks the move, return TRUE
	}
	else
		return false;                         //return FALSE if 相/象 does not move diagonally
}

bool Xiang::attack(SC x, SC y, vector<Chess*> ar)     //the moving method and the attacking method of 相/象 are the same
{
	return move(x, y, ar);                        //therefore call the move function here
}
