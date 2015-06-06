#include "chess.h"
#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::multiset;
using namespace CG;

//if no chess takes the position (x,y), a tabular character will be displayed
string tabchar(SC x, SC y)             //returns a tabular character
{
	switch (y)
	{
	case 'a':
	case 'f':
		switch (x)
		{
		case '1':
			return "┌";    //display ┌ for A1 and F1
		case '9':
			return "┐";    //display ┐ for A9 and F9
		default:
			return "┬";    //display ┬ for Ax and Fx (except for A1/A9/F1/F9)
		}
	case 'e':
	case 'j':
		switch (x)
		{
		case '1':
			return "└";    //display └ for E1 and J1
		case '9':
			return "┘";    //display ┘ for E9 and J9
		default:
			return "┴";    //display ┴ for Ex and Jx (except for E1/E9/J1/J9)
		}
	default:
		switch (x)
		{
		case '1':
			return "├";    //display ├ for B1/C1/D1/G1/H1/I1
		case '9':
			return "┤";    //display ┤ for B9/C9/D9/G9/H9/I9
		default:
			return "┼";    //display ┼ for other coordinates
		}
	}
}

//display the chess board, rd/bd represent the eaten chesses for the red/black side
void display(const vector<Chess*>& ar, const multiset<string>& rd, const multiset<string>& bd)
{
	string checker[10][9];    //create a 2D array (10 rows, 9 columns)
	int i, j;                 //i/j are used for the FOR loop
	SC x, y;                  //x/y represents the corresponding coordinates of i/j
	for (i = 0; i < 10; i++)  //row number = i+1
	{
		y = static_cast<SC> (i + 97);           //if i=0, y='a'; if i=9, y='j'
		for (j = 0; j < 9; j++)
		{
			x = static_cast<SC> (j + 49);   //if j=0, x='1'; if j=8, x='9'
			checker[i][j] = tabchar(x, y);  //use the tabular character first
			for (auto ch : ar)              //iterate through the vector container
			{
				if (ch->compare(x, y))  //if a chess is found
				{                       //change the tabular character to the chess name
					checker[i][j] = ch->GetName();
					break;          //break the search loop
				}
			}
		}
	}

	cout << "   １２３４５６７８９" << endl;        //display X-axis(using full-width numbers)
	for (i = 0; i < 10; i++)
	{
		y = static_cast<SC>(i + 65);            //now if i=0, y='A'; if i=9, y='J'
		cout << " " << y << " ";                //display Y-axis
		for (j = 0; j < 9; j++)
			cout << checker[i][j];          //display either tabular character or chess name
		cout << endl;
	}

	cout << "Dead chesses for the red side:" << endl;            //display red player's dead chesses
	for (auto ch : rd)                                           //iterate through the multiset container rd
		cout << ch;
	cout << endl << "Dead chesses for the black side:" << endl;  //display black player's dead chesses
	for (auto ch : bd)                                           //iterate through the multiset container bd
		cout << ch;
	cout << endl << endl;
}
