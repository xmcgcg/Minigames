#include "gadplayer.h"
#include <iostream>
#include <string>
#include <cctype>                //for isalpha(), isupper() and tolower()
#include <cstdlib>               //for rand() and srand()
#include <ctime>                 //for time()
using namespace std;

bool command(Player&, char);     //returns TRUE if the choice is valid, otherwise returns FALSE

inline void clearinput()         //clear input buffer
{
	while (cin.get() != '\n')
		continue;
}

int main()
{
	Player self("Player");       //create player
	Player opponent("Opponent"); //create opponent
	bool selfvalid = false;      //"selfvalid" indicates whether the player's choice is valid
	bool oppovalid = false;      //"oppovalid" indicates whether the opponent's choice is valid
	bool selfalive = true;       //"selfalive" indicates whether the player is alive
	bool oppoalive = true;       //"oppoalive" indicates whether the opponent is alive
	char replay = 'y';           
	
	while (replay == 'y')        //when the game ends, if the player chooses to replay, a new game will start
	{
		for (int i = 1;; i++)    //"i" indicates the round number
		{
			cout << "Round " << i << ":" << endl;             //display current round
			self.Show();                                      //display player's energy
			opponent.Show();                                  //display opponent's energy
			cout << "Enter your choice:" << endl;
			cout << "G: Gather  ";
			cout << "A: Attack  ";                            //player needs to make a choice
			cout << "D: Defend" << endl;

			char choice;                                      //"choice" indicates player's choice
			while (cin >> choice)                             //input "choice"
			{
				if (!cin)                                     //if input fails
				{
					cin.clear();
					clearinput();
					cout << "Please enter again." << endl;    //remind the player to enter a letter
					continue;
				}
				if (!isalpha(choice))                         //if "choice" is not a letter
				{
					clearinput();
					cout << "Please enter a letter." << endl; //remind the player to enter a letter
					continue;
				}

				choice = tolower(choice);                     //convert player's choice to lower case
				selfvalid = command(self, choice);            //check whether player's choice is valid
				if (!selfvalid)                               //if player enters letters other than g/a/d or
				{                                             //player has insufficient energy to attack
					cout << "Sorry, your choice is invalid, ";
					cout << "please enter another letter." << endl;
					continue;
				}
				else
					break;                                    //player's choice is valid, breaks the loop
			}

			oppovalid = false;                                //in order to run the while loop at least once
			while (!oppovalid)
			{
				srand(time(0));                               //use system time as seed
				int oppochoice;
				oppochoice = rand() % 3;                      //"oppochoice" is either 0, 1 or 2
				switch (oppochoice)
				{
					case 0:                                   //0 for GATHER, always valid
						choice = 'g';
						break;
					case 1:                                   //1 for ATTACK, may be invalid
						choice = 'a';
						break;
					case 2:                                   //2 for DEFEND, always valid
						choice = 'd';
				}
				oppovalid = command(opponent, choice);        //check whether the opponent's choice is valid
				if (!oppovalid)                               //only if opponent chooses attack
				{
					cout << "Opponent has insufficient energy";
					cout << ", attack failed." << endl;
				}
			}
			
			self.Combat(opponent);                            //change the alive states based on choices
			selfalive = self.Check();                         //check whether the player is still alive
			oppoalive = opponent.Check();                     //check whether the opponent is still alive
			if (selfalive && oppoalive)                       //if both are alive
			{
				cout << "Next round!" << endl << endl;        //enter next round
			}
			else if (!selfalive)                              //if player is dead
			{
				cout << "Opponent wins!" << endl;             //the opponent wins, game over
				break;
			}
			else                                             //if the opponent is dead
			{
				cout << "Player wins!" << endl;              //player wins, game over
				break;
			}
		}

		cout << "Replay?(y to continue): ";
		cin >> replay;                                       //enter Y/y to replay
		if (!cin)
			cin.clear();
		replay = tolower(replay);                            //convert 'Y' to 'y'
		clearinput();
		cout << endl;
		self.Reset();                                        //reset player's energy to 0
		opponent.Reset();                                    //reset opponent's energy to 0
	}
	return 0;
}

bool command(Player& pl, char ch) //"pl" is either the player or the opponent
{                                 //"ch" is always a letter due to isalpha() check
	bool valid;
	switch (ch)
	{
		case 'g':                 //if ch == 'g'
			cout << pl.Getname() << " chooses GATHER" << endl;
			valid = pl.Gather();  //always valid
			break;
		case 'a':                 //if ch == 'a'
			cout << pl.Getname() << " chooses ATTACK" << endl;
			valid = pl.Attack();  //may be invalid
			break;
		case 'd':                 //if ch == 'd'
			cout << pl.Getname() << " chooses DEFEND" << endl;
			valid = pl.Defend();  //always valid
			break;
		default:                  //if ch is other letter
			valid = false;        //the choice is invalid
	}
	return valid;
}
