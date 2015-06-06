#include "chess.h"
#include <cstdlib>
using std::abs;
using namespace CG;

JiangShuai::JiangShuai(SC x, SC y, const string& nm, color cl): Chess(x, y, nm, cl) {} //use Chess's constructor

bool JiangShuai::move(SC x, SC y, const vector<Chess*>& ar)   //return TRUE if moving to (x,y) is valid, otherwise return FALSE
{
	int Xdif = abs(x - Xcoord);                           //Xdif represents the number of columns to the destination
	int Ydif = abs(y - Ycoord);                           //Ydif represents the number of rows to the destination

	if (Ycoord < 'd' && y >= 'd')                         //if 帅/将 wants to move to row D
		return false;                                 //invalid move, return FALSE
	if (Ycoord > 'g' && y <= 'g')                         //if 帅/将 wants to move to row G
		return false;                                 //return FALSE
	if (x < '3' || x > '5')                               //if 帅/将 wants to move to column 3/7
		return false;                                 //return FALSE
	
	if (Xdif == 1 && Ydif == 0)                           //if 帅/将 moves horizontally by 1 column
		return true;                                  //valid move, return TRUE
	else if (Xdif == 0 && Ydif == 1)                      //if 帅/将 moves vertically by 1 row
		return true;                                  //valid move, return TRUE
	else
		return false;                                 //otherwise return FALSE
}

bool JiangShuai::attack(SC x, SC y, const vector<Chess*>& ar) //the moving method and the attacking method of 帅/将 are the same
{
	return move(x, y, ar);                                //therefore call the move function here
}
