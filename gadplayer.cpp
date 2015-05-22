#include "stdafx.h"
#include "gadplayer.h"
#include <iostream>
#include <string>
using namespace std;

//constructor
Player::Player(string str)
{
	name = str;
	energy = 0;
	alive = true;
	status = gather;
}

//check whether the player is still alive
//returns TRUE if alive, otherwise returns FALSE
bool Player::Check()                                       
{
	if (alive)
	{
		cout << name << " is still alive!" << endl;
		return true;
	}
	else
	{
		cout << name << " is dead." << endl;
		return false;
	}
}

//displays current energy amount
void Player::Show()
{
	cout << name << "'s current Energy: " << energy << endl;
}

//reset the status to the initial state after a game
void Player::Reset()
{
	energy = 0;
	alive = true;
}

//returns the name of player
string Player::Getname()
{
	return name;
}

//switch the status to GATHER
//since gather will always be successful, the function always returns TRUE
bool Player::Gather()
{
	status = gather;                                                        //Switch status to GATHER
	energy++;                                                               //Acquire 1 energy
	return true;
}

//try to switch the status to ATTACK
//returns TRUE is the attack is successful, otherwise returns FALSE
bool Player::Attack()
{
	if (energy)                                                             //Check the energy amount
	{
		status = attack;                                                    //Switch status to ATTACK
		energy--;                                                           //Cost 1 energy
		return true;
	}
	else                                                                    //Insufficient energy
	{
		cout << "Not enough energy, please choose another option." << endl; //Attack fails
		return false;
	}
}

//switch the status to DEFEND
//since defend will always be successful, the function always returns TRUE
bool Player::Defend()
{
	status = defend;                                                        //Switch status to DEFEND
	return true;
}

//check whether the opponent is still alive
//returns TRUE if alive, otherwise returns FALSE
bool Player::OPCheck(Player& pl)
{
	if (pl.alive)
	{
		cout << "The opponent is still alive!" << endl;
		return true;
	}
	else
	{
		cout << "The opponent is dead." << endl;
		return false;
	}
}

//if one chooses ATTACK and the other chooses GATHER, game over
void Player::Combat(Player& pl)
{
	if ((status == attack) && (pl.status == gather))
		pl.alive = false;
	else if ((status == gather) && (pl.status == attack))
		alive = false;
}
