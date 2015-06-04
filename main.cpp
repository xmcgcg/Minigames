#include "chess.h"
#include <iostream>
#include <cctype>
#include <set>
using std::cin;
using std::cout;
using std::endl;
using std::isupper;
using std::tolower;
using std::multiset;
using namespace CG;

//function prototypes
string tabchar(SC, SC);
void display(vector<Chess*>, multiset<string>, multiset<string>);
bool checkX(SC);
bool checkY(SC);

//clear all the characters in the input stream
inline void clearinput()
{
	while (cin.get() != '\n')
		continue;
}

//check whether the input fails and convert all upper case input to lower case
inline void input(SC& target)
{
	while (true)
	{
		cin >> target;
		if (!cin)
		{
			cin.clear();
			clearinput();
			cout << "Input invalid, please enter again: ";
			continue;
		}
		clearinput();
		if (isupper(target))
			target = tolower(target);
		break;
	}
}

int main()
{
	vector<Chess*> chesses;                        //vector container storing pointers to Chess objects
	multiset<string> RedDeadChess, BlackDeadChess; //these multiset containers store the names of dead chesses
	string NewDead;                                //this represents the name of the new dead chess
	color down;
	SC replay = 'y';
	while (replay == 'y')                          //the game cycle
	{
		SC choice;                             //this indicates the choice of player's side
		cout << "Choose your color (R for red/B for black): ";
		while (true)                           //loop for inputting choice
		{
			input(choice);

			switch (choice)
			{
			case 'r':
				down = red;            //enter R to make the bottom side RED
				break;
			case 'b':
				down = black;          //enter B to make the bottom side BLACK
				break;
			default:
				cout << "Please enter either R or B: ";
				continue;              //other choices are not accepted
			}
			cout << endl;
			break;
		}

		SC red1, red3, red4;                   //represents the 1st/3rd/4th row of the RED side respectively
		SC black1, black3, black4;             //represents the 1st/3rd/4th row of the BLACK side respectively
		if (down == red)                       //if RED is at the bottom
		{
			red1 = 'j';
			red3 = 'h';
			red4 = 'g';
		}
		else                                   //if BLACK is at the bottom
		{
			red1 = 'a';
			red3 = 'c';
			red4 = 'd';
		}
		black1 = static_cast<SC> (203 - red1); //if red1='j', black1='a', and vice versa
		black3 = static_cast<SC> (203 - red3);
		black4 = static_cast<SC> (203 - red4);

		if (true) //initializing Chess objects, the if statement is for the convenience to fold this part
		{
			Chess* RedLeftJu = new Ju('1', red1, "车", red);        //create these objects on heap
			Chess* RedRightJu = new Ju('9', red1, "车", red);
			Chess* BlackLeftJu = new Ju('1', black1, "車", black);  //use traditional Chinese characters
			Chess* BlackRightJu = new Ju('9', black1, "車", black); //to differentiate RED and BLACK 车/马
			
			Chess* RedLeftMa = new Ma('2', red1, "马", red);
			Chess* RedRightMa = new Ma('8', red1, "马", red);
			Chess* BlackLeftMa = new Ma('2', black1, "馬", black);
			Chess* BlackRightMa = new Ma('8', black1, "馬", black);

			Chess* RedLeftXiang = new Xiang('3', red1, "相", red);
			Chess* RedRightXiang = new Xiang('7', red1, "相", red);
			Chess* BlackLeftXiang = new Xiang('3', black1, "象", black);
			Chess* BlackRightXiang = new Xiang('7', black1, "象", black);

			Chess* RedLeftShi = new Shi('4', red1, "仕", red);
			Chess* RedRightShi = new Shi('6', red1, "仕", red);
			Chess* BlackLeftShi = new Shi('4', black1, "士", black);
			Chess* BlackRightShi = new Shi('6', black1, "士", black);

			Chess* RedShuai = new JiangShuai('5', red1, "帅", red);
			Chess* BlackJiang = new JiangShuai('5', black1, "将", black);

			Chess* RedLeftPao = new Pao('2', red3, "炮", red);
			Chess* RedRightPao = new Pao('8', red3, "炮", red);
			Chess* BlackLeftPao = new Pao('2', black3, "砲", black);
			Chess* BlackRightPao = new Pao('8', black3, "砲", black);

			Chess* Red1stBing = new BingZu('1', red4, "兵", red);
			Chess* Red2ndBing = new BingZu('3', red4, "兵", red);
			Chess* Red3rdBing = new BingZu('5', red4, "兵", red);
			Chess* Red4thBing = new BingZu('7', red4, "兵", red);
			Chess* Red5thBing = new BingZu('9', red4, "兵", red);
			Chess* Black1stZu = new BingZu('1', black4, "卒", black);
			Chess* Black2ndZu = new BingZu('3', black4, "卒", black);
			Chess* Black3rdZu = new BingZu('5', black4, "卒", black);
			Chess* Black4thZu = new BingZu('7', black4, "卒", black);
			Chess* Black5thZu = new BingZu('9', black4, "卒", black);

			chesses.emplace_back(RedShuai);         //add these pointers to the vector container
			chesses.emplace_back(BlackJiang);

			chesses.emplace_back(RedLeftJu);
			chesses.emplace_back(RedRightJu);
			chesses.emplace_back(BlackLeftJu);
			chesses.emplace_back(BlackRightJu);

			chesses.emplace_back(RedLeftMa);
			chesses.emplace_back(RedRightMa);
			chesses.emplace_back(BlackLeftMa);
			chesses.emplace_back(BlackRightMa);

			chesses.emplace_back(RedLeftXiang);
			chesses.emplace_back(RedRightXiang);
			chesses.emplace_back(BlackLeftXiang);
			chesses.emplace_back(BlackRightXiang);

			chesses.emplace_back(RedLeftShi);
			chesses.emplace_back(RedRightShi);
			chesses.emplace_back(BlackLeftShi);
			chesses.emplace_back(BlackRightShi);

			chesses.emplace_back(RedLeftPao);
			chesses.emplace_back(RedRightPao);
			chesses.emplace_back(BlackLeftPao);
			chesses.emplace_back(BlackRightPao);

			chesses.emplace_back(Red1stBing);
			chesses.emplace_back(Red2ndBing);
			chesses.emplace_back(Red3rdBing);
			chesses.emplace_back(Red4thBing);
			chesses.emplace_back(Red5thBing);
			chesses.emplace_back(Black1stZu);
			chesses.emplace_back(Black2ndZu);
			chesses.emplace_back(Black3rdZu);
			chesses.emplace_back(Black4thZu);
			chesses.emplace_back(Black5thZu);
		}

		Chess* selected = nullptr;           //"selected" represents the current selected chess
		bool found = false;                  //"found" represents whether a chess is found during iteration
		bool proceed = true;                 //"proceed" represents whether the current phase can be over
		display(chesses, RedDeadChess, BlackDeadChess); //display the chess board

		while (true)                         //only GAME OVER can break this loop
		{
			SC x, y;                     //X/Y coordinates

			do                           //RED's turn
			{
				cout << "Red player, please enter the Y coordinate of the chess you want to move: ";
				do
				{
					input(y);    //input the Y-coordinate
				} while (checkY(y)); //check whether it is out of bound

				cout << "Red player, please enter the X coordinate of the chess you want to move: ";
				do
				{
					input(x);    //input the X-coordinate
				} while (checkX(x)); //check whether it is out of bound

				found = false;       //no chess has been found yet
				for (auto ch : chesses)           //search for any chess at this position
				{
					if (ch->compare(x, y))
					{
						if (ch->GetSide() == red) //if the chess is RED
						{
							selected = ch;    //it is successfully selected
							cout << "You have selected " << ch->GetName() << "." << endl << endl;
							found = true;     //set "found" to TRUE since a chess is found
							proceed = true;   //set "proceed" to TRUE since this phase is over
							break;            //break the search loop
						}
						else                      //if the chess is BLACK
						{
							cout << "You have selected an enemy chess, ";
							cout << "please enter another set of coordinates." << endl << endl;
							found = true;     //a chess is found
							proceed = false;  //but it's an enemy chess, cannot proceed
							break;            //break the search loop
						}
					}
				}
				if (!found)                               //if no chess is found
				{
					cout << "It is empty here, ";
					cout << "please enter another set of coordinates." << endl << endl;
					proceed = false;                  //cannot proceed
				}
			} while (!proceed);                               //continue the loop if proceed=FALSE

			do                            //now enter the coordinates of the destination
			{
				cout << "Red player, please enter the Y coordinate of the destination: ";
				do                    //the same checking process
				{
					input(y);
				} while (checkY(y));

				cout << "Red player, please enter the X coordinate of the destination: ";
				do
				{
					input(x);
				} while (checkX(x));

				found = false;        //reset "found" to FALSE
				for (auto ch : chesses)           //search for any chess at this position
				{
					if (ch->compare(x, y))    //if a chess is found
					{
						if (ch->GetSide() == red) //if a friendly chess is found
						{
							cout << "There is a chess of your own on that position, ";
							cout << "please enter another set of coordinates." << endl << endl;
							found = true;     //a chess is found
							proceed = false;  //you cannot attack your own chess
							break;            //break the search loop
						}
						else
						{
							found = true;     //if an enemy chess is found
							proceed = selected->JS_DoNotMeet(x, y, chesses);
							if (!proceed)     //if 帅 and 将 will meet each other
							{
								cout << "Jiang and Shuai will meet each other if you move, ";
								cout << "please enter another set of coordinates." << endl << endl;
							}
							break;
						}
					}
				}

				if (!found)                //if no chess is found
				{                          //check whether the chess can move to that position
					proceed = selected->move(x, y, chesses);
					if (proceed)       //if the chess can move to there
						proceed = selected->JS_DoNotMeet(x, y, chesses);
					else               //if the move is invalid, enter another set of coordinates
					{
						cout << "Unable to move to that position, ";
						cout << "Please enter another set of coordinates." << endl << endl;
						continue;  //go to the beginning of this do-while loop
					}

					if (proceed)       //if 帅 and 将 will not meet each other
						selected->displayMove(x, y); //display and execute the move command
					else               //otherwise another set of coordinates has to be entered
					{
						cout << "Jiang and Shuai will meet each other if you move, ";
						cout << "please enter another set of coordinates." << endl << endl;
					}
				}
				else if (found && proceed) //if 帅 and 将 will not meet each other after attack
				{
					proceed = selected->attack(x, y, chesses); //call the attack function to check validity
					if (proceed)       //if the attack is valid
					{                  //iterate through the vector container
						for (auto iter = chesses.begin(); iter != chesses.end(); iter++)
						{          //search for the chess at that position
							if ((*iter)->GetX() == x && (*iter)->GetY() == y)
							{
								NewDead = (*iter)->GetName();    //get the name of dead chess
								BlackDeadChess.insert(NewDead);  //insert it into dead chesses
								selected->displayAttack(**iter); //display and execute the attack command
								delete *iter;                    //free the memory allocated
								*iter = nullptr;                 //set the pointer value to nullptr
								chesses.erase(iter);             //delete this pointer from the container
								break;                           //break the search loop
							}
						}
					}
					else               //if the attack is invalid
					{                  //display information and continue the loop
						cout << "Unable to attack the chess at that position, ";
						cout << "please enter another set of coordinates." << endl << endl;
					}
				}
			} while (!proceed);                             //continue the loop if proceed=FALSE

			selected = nullptr;                             //RED's turn is over, no chess is selected
			display(chesses, RedDeadChess, BlackDeadChess); //display the chess board after RED's turn
			if (NewDead == "将")                            //if 将 is eaten
			{
				cout << "Game over. Red wins.\a" << endl << endl;
				break;                                  //GAME OVER, break the loop
			}

			do                                              //now it is BLACK's turn, similar to RED's turn
			{
				cout << "Black player, please enter the y coordinate of the chess you want to move: ";
				do
				{
					input(y);
				} while (checkY(y));

				cout << "Black player, please enter the X coordinate of the chess you want to move: ";
				do
				{
					input(x);
				} while (checkX(x));

				found = false;
				for (auto ch : chesses)
				{
					if (ch->compare(x, y))
					{
						if (ch->GetSide() == black)
						{
							selected = ch;
							cout << "You have selected " << ch->GetName() << "." << endl << endl;
							found = true;
							proceed = true;
							break;
						}
						else
						{
							cout << "You have selected an enemy chess, ";
							cout << "please enter another set of coordinates." << endl << endl;
							found = true;
							proceed = false;
							break;
						}
					}
				}
				if (!found)
				{
					cout << "It is empty here, ";
					cout << "please enter another set of coordinates." << endl << endl;
					proceed = false;
					continue;
				}
			} while (!proceed);

			do
			{
				cout << "Black player, please enter the Y coordinate of the destination: ";
				do
				{
					input(y);
				} while (checkY(y));

				cout << "Black player, please enter the X coordinate of the destination: ";
				do
				{
					input(x);
				} while (checkX(x));

				found = false;
				for (auto ch : chesses)
				{
					if (ch->compare(x, y))
					{
						if (ch->GetSide() == black)
						{
							cout << "There is a chess of your own on that position, ";
							cout << "please enter another set of coordinates." << endl << endl;
							found = true;
							proceed = false;
							break;
						}
						else
						{
							found = true;
							proceed = selected->JS_DoNotMeet(x, y, chesses);
							if (!proceed)
							{
								cout << "Jiang and Shuai will meet each other if you move, ";
								cout << "please enter another set of coordinates." << endl << endl;
							}
							break;
						}
					}
				}

				if (!found)
				{
					proceed = selected->move(x, y, chesses);
					if (proceed)
						proceed = selected->JS_DoNotMeet(x, y, chesses);
					else
					{
						cout << "Unable to move to that position, ";
						cout << "Please enter another set of coordinates." << endl << endl;
						continue;
					}

					if (proceed)
						selected->displayMove(x, y);
					else
					{
						cout << "Jiang and Shuai will meet each other if you move, ";
						cout << "please enter another set of coordinates." << endl << endl;
					}
				}
				else if (found && proceed)
				{
					proceed = selected->attack(x, y, chesses);
					if (proceed)
					{
						for (auto iter = chesses.begin(); iter != chesses.end(); iter++)
						{
							if ((*iter)->GetX() == x && (*iter)->GetY() == y)
							{
								NewDead = (*iter)->GetName();
								RedDeadChess.insert(NewDead);
								selected->displayAttack(**iter);
								delete *iter;
								*iter = nullptr;
								chesses.erase(iter);
								break;
							}
						}
					}
					else
					{
						cout << "Unable to attack the chess at that position, ";
						cout << "please enter another set of coordinates." << endl << endl;
					}
				}
			} while (!proceed);

			selected = nullptr;                             //BLACK's turn is over, no chess is selected
			display(chesses, RedDeadChess, BlackDeadChess); //display the chess board again
			if (NewDead == "帅")                            //if 帅 is eaten
			{
				cout << "Game over. Black wins.\a" << endl << endl;
				break;                                  //GAME OVER, break the loop
			}
		}                                                       //otherwise another RED's turn begins
		
		for (auto iter = chesses.begin(); iter != chesses.end(); iter++)
		{
			delete *iter;                                   //free the memory of the undead chesses
			*iter = nullptr;                                //set the members' value as nullptr
		}
		chesses.clear();                                        //clear the vector container
		
		cout << "Replay?(Enter Y to replay): ";                 //enter Y/y to replay
		input(replay);
	}
	return 0;                                                       //otherwise quit the program
}
