#include "chess.h"
using namespace CG;

Pao::Pao(SC x, SC y, const string& nm, color cl): Chess(x, y, nm, cl) {} //use Chess's constructor

bool Pao::move(SC x, SC y, vector<Chess*> ar)            //return TRUE if moving to (x,y) is valid, otherwise return FALSE
{                                                        //炮/砲's moving method is the same as 车's
	if (x != Xcoord && y != Ycoord)                  //therefore Pao::move is equivalant to Ju::move
		return false;
	if (x == Xcoord && y != Ycoord)
	{
		SC min, max;
		min = y < Ycoord ? y : Ycoord;
		max = y > Ycoord ? y : Ycoord;
		min++;
		while (min < max)
		{
			for (auto ch : ar)
				if (ch->compare(x, min))
					return false;
			min++;
		}
	}

	if (x != Xcoord && y == Ycoord)
	{
		SC min, max;
		min = x < Xcoord ? x : Xcoord;
		max = x > Xcoord ? x : Xcoord;
		min++;
		while (min < max)
		{
			for (auto ch : ar)
				if (ch->compare(min, y))
					return false;
			min++;
		}
	}

	return true;
}

bool Pao::attack(SC x, SC y, vector<Chess*> ar)          //return TRUE if the attack is valid, otherwise return FALSE
{                                                        //炮/砲 is the only kind of chess with a unique attacking method
	bool found = false;                              //found indicates whether a chess is found between 炮/砲 and target

	if (x != Xcoord && y != Ycoord)                  //return FALSE if the targer is not on the same line as 炮/砲
		return false;

	if (x == Xcoord && y != Ycoord)                  //if 炮/砲 wants to attack vertically
	{
		SC min, max;
		min = y < Ycoord ? y : Ycoord;
		max = y > Ycoord ? y : Ycoord;
		min++;
		while (min < max)
		{
			for (auto ch : ar)
				if (ch->compare(x, min)) //if a chess is found in between
				{
					found = true;    //set variable "found" as TRUE
					break;           //break the searching loop for the coordinate
				}
			if (found)
				break;                   //break the full searching loop
			min++;
		}

		if (min == max)                          //if the loop is ended due to min==max
			return false;                    //no chess is in between, return FALSE

		min++;                                   //set "min" to the next coordinate
		while (min < max)                        //second search
		{
			for (auto ch : ar)
				if (ch->compare(x, min)) //if the second chess is found in between, return FALSE
					return false;
			min++;
		}
	}

	if (x != Xcoord && y == Ycoord)                  //if 炮/砲 wants to attack horizontally
	{
		SC min, max;                             //similar procedure as above
		min = x < Xcoord ? x : Xcoord;
		max = x > Xcoord ? x : Xcoord;
		min++;
		while (min < max)
		{
			for (auto ch : ar)
				if (ch->compare(min, y))
				{
					found = true;    //set variable "found" as TRUE 
					break;           //break the search loop for the coordinate
				}
			if (found)
				break;                   //break the full search loop
			min++;
		}
		
		if (min == max)                          //if the loop is ended due to min==max
			return false;                    //no chess is in between, return FALSE

		min++;
		while (min < max)                        //similar procedure again
		{
			for (auto ch : ar)
				if (ch->compare(min, y))
					return false;    //if the second chess is found in between, return FALSE
			min++;
		}
	}

	return true;                                     //if only one chess is found in between, return TRUE
}
