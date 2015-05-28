#include "chess.h"
#include <cstdlib>
using std::abs;

BingZu::BingZu(SC x, SC y, const string& nm, color cl): Chess(x, y, nm, cl) {} //use Chess's constructor

bool BingZu::move(SC x, SC y, vector<Chess*> ar)   //return TRUE if the movement is valid, otherwise return FALSE
{
	color down;                                //down represents the color of the chess from the bottom side
	for (auto ch : ar)
	{
		if (ch->GetName() == "帅")         //search for 帅
		{
			if (ch->GetY() < 'd')      //if 帅 is in the top half of the chess board
				down = black;      //bottom half is the base for the black side
			else
				down = red;        //otherwise bottom half is the base for the red side
			break;                     //break the search loop
		}
	}

	int Xdif = abs(x - Xcoord);                //Xdif represents the number of columns to the destination

	if ((down == black && side == black) || (down == red && side == red))
	{                                          //if 兵/卒 is placed on row G at the beginning
		if (Ycoord < 'f' && Xdif == 1)     //if 兵/卒 has crossed the river and move to the left and right
			return true;               //the move is valid, return TRUE
		else if (y < Ycoord && Xdif == 0)  //if 兵/卒 moves up
			return true;               //the move is also valid, return TRUE
		else
			return false;              //otherwise return FALSE
	}

	else                                       //if 兵/卒 is placed on row D at the beginning
	{
		if (Ycoord > 'f' && Xdif == 1)     //if 兵/卒 has crossed the river and move to the left and right
			return true;               //the move is valid, return TRUE
		else if (y > Ycoord && Xdif == 0)  //if 兵/卒 moves down
			return true;               //the move is also valid, return TRUE
		else
			return false;              //otherwise return FALSE
	}
}

bool BingZu::attack(SC x, SC y, vector<Chess*> ar) //the moving method and the attacking method of 兵/卒 are the same
{
	return move(x, y, ar);                     //therefore call the move function here
}
