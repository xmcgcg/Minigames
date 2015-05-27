#include "chess.h"
#include <cstdlib>
using std::abs;

Ma::Ma(SC x, SC y, const string& nm, color cl): Chess(x, y, nm, cl) {} //use Chess's constructor

bool Ma::move(SC x, SC y, vector<Chess*> ar) //return TRUE if the movement is valid, otherwise return FALSE
{
	int Xdif = abs(x - Xcoord); //Xdif represents the number of rows to the destination
	int Ydif = abs(y - Ycoord); //Ydif represents the number of columns to the destination
	if ((Xdif == 2 && Ydif == 1) || (Xdif == 1 && Ydif == 2)) //if one of the two variables is 1 and the other is 2
	{
		if ((x - Xcoord) == 2)                       //if 马 wants to move to the right
			for (auto ch : ar)
				if (ch->compare(Xcoord + 1, Ycoord)) //if a chess is right next to 马 on the right
					return false;                //the move is invalid, return FALSE
		if ((Xcoord - x) == 2)                       //if 马 wants to move to the left
			for (auto ch : ar) 
				if (ch->compare(Xcoord - 1, Ycoord)) //if a chess is right next to 马 on the left
					return false;                //the move is invalid, return FALSE
		if ((y - Ycoord) == 2)                       //if 马 wants to move to the bottom
			for (auto ch : ar)
				if (ch->compare(Xcoord, Ycoord + 1)) //if a chess is right next to 马 on the bottom
					return false;                //the move is invalid, return FALSE
		if ((Ycoord - y) == 2)                       //if 马 wants to move to the top
			for (auto ch:ar)
				if (ch->compare(Xcoord, Ycoord - 1)) //if a chess is right next to 马 on the top
					return false;                //the move is invalid, return FALSE
		return true;                                 //return TRUE since the move is valid       
	}
	else
		return false;                                //return FALSE since 马 cannot move in other ways
}

bool Ma::attack(SC x, SC y, vector<Chess*> ar)               //the moving method and the attacking method of 马 are the same
{
	return move(x, y, ar);                               //therefore call the move function here
}
