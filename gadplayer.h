#ifndef GADPLAYER_H_
#define GADPLAYER_H_
#include <string>
using std::string;

class Player
{
public:
	enum stat {gather, attack, defend}; //enumerators for player's choice
private:
	string name;                        //player name
	int energy;                         //player energy
	bool alive;                         //check whether the player is alive
	stat status;                        //player's choice
public:
	Player(string str="null");          //constructor
	void Reset();                       //reset the player to the initial status after each game
	string Getname();                   //get the player's name
	bool Check();                       //check and display whether the player is still alive
	void Show();                        //display player's current energy
	bool Gather();                      //change the status to GATHER, acquire 1 energy
	bool Attack();                      //change the status to ATTACK, cost 1 energy
	bool Defend();                      //change the status to DEFEND, defend an attack
	bool OPCheck(Player&);              //check whether the opponent(system) is still alive
	void Combat(Player&);               //compare the choices of player and system to decide who will be dead
};

#endif
