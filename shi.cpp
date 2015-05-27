#include "chess.h"

Shi::Shi(SC x, SC y, const string& nm, color cl): Chess(x, y, nm, cl) {} //use Chess's constructor

bool Shi::move(SC x, SC y, vector<Chess*> ar) //return TRUE if the movement is valid, otherwise return FALSE
{
	switch (Ycoord)
	{
	case 'a':                      //if 仕/士 is on the first or third row
	case 'c':
		if (x == '5' && y == 'b')
			return true;   //it can only move to B5 to return TRUE
		else
			return false;
	case 'b':                      //if 仕/士 is at B5
		if ((x == '4' || x == '6') && (y == 'a' || y == 'c'))
			return true;   //it can move to A4/A6/B4/B6 to return TRUE
		else
			return false;
	case 'h':                      //if 仕/士 is on the last ot third last row
	case 'j':
		if (x == '5' && y == 'i')
			return true;   //it can only move to I5 to return true
		else
			return false;
	case 'i':                      //if 仕/士 is at I5
		if ((x == '4' && x == '6') && (y == 'h' || y == 'j'))
			return true;            //it can move to H4/H6/I4/I6  to return TRUE
		else
			return false;
	default:                                //if 仕/士 is on other rows, return FALSE
		return false;
	}
}

bool Shi::attack(SC x, SC y, vector<Chess*> ar) //the moving method and the attacking method of 仕/士 are the same
{
	return move(x, y, ar);                  //therefore call the move function here
}
