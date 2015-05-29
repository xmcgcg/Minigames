#include "chess.h"
#include <iostream>
#include <cctype>
#include <set>
using namespace std;

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
	vector<Chess*> chesses;
	multiset<string> RedDeadChess, BlackDeadChess;
	string NewDead;
	color down;
	SC replay = 'y';
	while (replay == 'y')
	{
		SC choice;
		cout << "Choose your color (R for red/B for black): ";
		while (true)
		{
			input(choice);

			switch (choice)
			{
			case 'r':
				down = red;
				break;
			case 'b':
				down = black;
				break;
			default:
				cout << "Please enter either R or B: ";
				continue;
			}
			cout << endl;
			break;
		}

		SC red1, red3, red4;
		SC black1, black3, black4;
		if (down == red)
		{
			red1 = 'j';
			red3 = 'h';
			red4 = 'g';
		}
		else
		{
			red1 = 'a';
			red3 = 'c';
			red4 = 'd';
		}
		black1 = static_cast<SC> (203 - red1);
		black3 = static_cast<SC> (203 - red3);
		black4 = static_cast<SC> (203 - red4);

		if (true)
		{
			Chess* RedLeftJu = new Ju('1', red1, "车", red);
			Chess* RedRightJu = new Ju('9', red1, "车", red);
			Chess* BlackLeftJu = new Ju('1', black1, "車", black);
			Chess* BlackRightJu = new Ju('9', black1, "車", black);
			
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

			chesses.emplace_back(RedShuai);
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

		Chess* selected = nullptr;
		bool found = false;
		bool proceed = true;
		display(chesses, RedDeadChess, BlackDeadChess);

		while (true)
		{
			SC x, y;

			do
			{
				cout << "Red player, please enter the Y coordinate of the chess you want to move: ";
				do
				{
					input(y);
				} while (checkY(y));

				cout << "Red player, please enter the X coordinate of the chess you want to move: ";
				do
				{
					input(x);
				} while (checkX(x));

				found = false;
				for (auto ch : chesses)
				{
					if (ch->compare(x, y))
					{
						if (ch->GetSide() == red)
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
				cout << "Red player, please enter the Y coordinate of the destination: ";
				do
				{
					input(y);
				} while (checkY(y));

				cout << "Red player, please enter the X coordinate of the destination: ";
				do
				{
					input(x);
				} while (checkX(x));

				found = false;
				for (auto ch : chesses)
				{
					if (ch->compare(x, y))
					{
						if (ch->GetSide() == red)
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
							else
								proceed = selected->attack(x, y, chesses);
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
					for (auto iter = chesses.begin(); iter != chesses.end(); iter++)
					{
						if ((*iter)->GetX() == x && (*iter)->GetY() == y)
						{
							NewDead = (*iter)->GetName();
							BlackDeadChess.insert(NewDead);
							selected->displayAttack(**iter);
							delete *iter;
							*iter = nullptr;
							chesses.erase(iter);
							break;
						}
					}
				}
			} while (!proceed);

			selected = nullptr;
			display(chesses, RedDeadChess, BlackDeadChess);
			if (NewDead == "将")
			{
				cout << "Game over. Red wins.\a" << endl << endl;
				break;
			}

			do
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
							else
								proceed = selected->attack(x, y, chesses);
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
			} while (!proceed);

			selected = nullptr;
			display(chesses, RedDeadChess, BlackDeadChess);
			if (NewDead == "帅")
			{
				cout << "Game over. Black wins.\a" << endl << endl;
				break;
			}
		}
		
		cout << "Replay?(Enter Y to replay): ";
		input(replay);
	}
	return 0;
}
