#include "chess.h"
#include <iostream>
#include <cctype>
using std::cout;
using std::endl;
using std::toupper;
using namespace CG;

Chess::Chess(SC x, SC y, const string& nm, color cl)     //Constructor with 4 parameters
{
	Xcoord = x;
	Ycoord = y;
	name = nm;
	side = cl;
}

bool Chess::check(SC x, SC y) const                      //check whether the coordinates are within the chess board
{                                                        //returns FALSE if the coordinates are out of bound
	bool inbound = true;
	if (x < '1' || x > '9')                          //X-coordinate should be between 1 and 9 (inclusive)
	{
		cout << "X-coordinate is out of bound." << endl;
		inbound = false;
	}
	if (y < 'a' || y > 'j')                          //Y-coordinate should be between a and j (inclusive)
	{
		cout << "Y-coordinate is out of bound." << endl;
		inbound = false;
	}
	return inbound;
}

bool Chess::compare(SC x, SC y) const                    //check whether there is a chess at (x, y)
{
	if (Xcoord == x && Ycoord == y)
		return true;
	else
		return false;
}

bool Chess::JS_DoNotMeet(SC x, SC y, const vector<Chess*>& ar) const        //check whether 帅 and 将 will meet each other
{                                                             //return TRUE if they do not meet, otherwise return FALSE
	if (name == "帅")                                     //if the chess itself is 帅
	{
		for (auto jiang : ar)                         //iterate through the container of pointers
		{
			if (jiang->GetName() == "将" && jiang->GetX() == x) //if 将 is at the same column as 帅
			{
				SC Yjiang = jiang->GetY();                  //get 将's Y-coordinate
				SC min = Ycoord < Yjiang ? Ycoord : Yjiang; //min represents the lower Y-coordinate
				SC max = Ycoord > Yjiang ? Ycoord : Yjiang; //max represents the higher Y-coordinate
				min++;                        //+1 to min since the search range is not inclusive for the ends
				for (; min < max; min++)      //check every position between 帅 and 将
					for (auto ch : ar)    //iterate through the container again
						if (ch->compare(x, min))    //if there is one other chess in between
							return true;        //return TRUE as 帅 and 将 do not meet each other
				return false;                               //if no chess is found in between, return FALSE
			}
		}
		return true;                                                //if 帅 and 将 is not in the same column, return TRUE
	}
	else if (name == "将")                           //if the chess itself is 将
	{
		for (auto shuai : ar)                    //iterate through the container of pointers
		{
			if (shuai->GetName() == "帅" && shuai->GetX() == x) //if 帅 is at the same column as 将
			{
				SC Yshuai = shuai->GetY();                  //similar procedure as above
				SC min = Ycoord < Yshuai ? Ycoord : Yshuai;
				SC max = Ycoord > Yshuai ? Ycoord : Yshuai;
				min++;
				for (; min < max; min++)
					for (auto ch : ar)
						if (ch->compare(x, min))
							return true;        //return TRUE as 将 and 帅 do not meet each other
				return false;                               //if no chess is found in between, return FALSE
			}
		}
		return true;                                                //if 将 and 帅 is not in the same column, return TRUE
	}
	else                                             //if the chess is neither 帅 nor 将
	{
		for (auto ch1 : ar)                      //search for 帅
		{
			if (ch1->GetName() == "帅")
			{
				for (auto ch2 : ar)      //search for 将
				{
					if (ch2->GetName() == "将")
					{
						if (ch1->GetX() == ch2->GetX())  //if 帅 and 将 is in the same column
						{
							SC y1 = ch1->GetY();     //similar procedure again
							SC y2 = ch2->GetY();
							SC min = y1 < y2 ? y1 : y2;
							SC max = y1 > y2 ? y1 : y2;
							min++;
							for (; min < max; min++)
								for (auto ch : ar)
									if (ch->compare(x, min))
										return true;     //return TRUE as 帅 and 将 do not meet each other
							return false;                            //if no chess is found in between, return FALSE
						}
						else
							return true;                             //if 将 and 帅 is not in the same column, return TRUE
					}
				}
			}
		}
	}
	return true;                                 //this return statement is just for WARNING not to appear
}

void Chess::displayMove(SC x, SC y)                  //display and execute movement if it is valid
{
	Xcoord = x;                                  //change the X-coordinate to parameter x
	Ycoord = y;                                  //change the Y-coordinate to parameter y
	y = toupper(y);                              //change y to upper case
	cout << name << " has moved to coordinate ";
	cout << y << x << "." << endl << endl;       //display the movement information
}

void Chess::displayAttack(Chess& ch)                     //display and execute attacking if it is valid
{
	Xcoord = ch.Xcoord;                              //change the X-coordinate to the X-coordinate of enemy chess
	Ycoord = ch.Ycoord;                              //change the Y-coordinate to the Y-coordinate of enemy chess
	SC tempY = toupper(Ycoord);                      //create a local variable in Y-coordinate's upper case form
	cout << name << " has moved to coordinate " << tempY << ch.Xcoord;
	cout << " and eats " << ch.name << endl << endl; //display the attacking information
}
