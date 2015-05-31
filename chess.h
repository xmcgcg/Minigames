#ifndef CHESS_H_
#define CHESS_H_
#include <string>
#include <vector>
using std::string;
using std::vector;

typedef signed char SC;

enum color { red, black };                           //enumerators for colors of players

class Chess                                          //abstract base class
{
protected:
	color side;                                      //color of chess
	string name;                                     //name of chess
	SC Xcoord;                                       //X-coordinate of chess on the chess board
	SC Ycoord;                                       //Y-coordinate of chess on the chess board
public:
	Chess() = default;                               //use default constructor
	Chess(SC, SC, const string&, color);             //constructor with 4 parameters

	color GetSide() const { return side; }           //functions returning protected members
	string GetName() const { return name; }
	SC GetX() const { return Xcoord; }
	SC GetY() const { return Ycoord; }

	bool check(SC, SC) const;                        //check whether the set of coordinates are out of board
	bool compare(SC, SC) const;                      //check whether there is a chess on this position
	bool JS_DoNotMeet(SC, SC, vector<Chess*>) const; //chech whether 将 and 帅 will meet each other

	virtual bool move(SC, SC, vector<Chess*>) = 0;   //check whether the chess can move to this position
	virtual bool attack(SC, SC, vector<Chess*>) = 0; //check whether the chess can attack enemy chess at this pos
	void displayMove(SC, SC);                        //display the move information if moving is successful
	void displayAttack(Chess&);                      //display the attack information if attacking is successful

	virtual ~Chess() = default;                      //virtual default destructor
};

class Ju: public Chess                               //derived class for chess 车
{
public:
	Ju() = default;                                  //default constructor
	Ju(SC, SC, const string&, color);                //constructor with 4 parameters

	virtual bool move(SC, SC, vector<Chess*>);       //specific move function for 车
	virtual bool attack(SC, SC, vector<Chess*>);     //specific attack function for 车

	virtual ~Ju() = default;                         //virtual default destructor
};

class Ma: public Chess                               //derived class for chess 马
{
public:
	Ma() = default;
	Ma(SC, SC, const string&, color);

	virtual bool move(SC, SC, vector<Chess*>);
	virtual bool attack(SC, SC, vector<Chess*>);

	virtual ~Ma() = default;
};

class Xiang: public Chess                            //derived class for chess 相(red)/象(black)
{
public:
	Xiang() = default;
	Xiang(SC, SC, const string&, color);
	
	bool move(SC, SC, vector<Chess*>);
	bool attack(SC, SC, vector<Chess*>);

	~Xiang() = default;
};

class Shi: public Chess                              //derived class for chess 仕(red)/士(black)
{
public:
	Shi() = default;
	Shi(SC, SC, const string&, color);

	bool move(SC, SC, vector<Chess*>);
	bool attack(SC, SC, vector<Chess*>);

	~Shi() = default;
};

class Pao: public Chess                              //derived class for chess 炮(red)/砲(black)
{
public:
	Pao() = default;
	Pao(SC, SC, const string&, color);

	bool move(SC, SC, vector<Chess*>);
	bool attack(SC, SC, vector<Chess*>);

	~Pao() = default;
};

class BingZu: public Chess                           //derived class for chess 兵(red)/卒(black)
{
public:
	BingZu() = default;
	BingZu(SC, SC, const string&, color);

	bool move(SC, SC, vector<Chess*>);
	bool attack(SC, SC, vector<Chess*>);

	~BingZu() = default;
};

class JiangShuai: public Chess                       //derived class for chess 帅(red)/将(black)
{
public:
	JiangShuai() = default;
	JiangShuai(SC, SC, const string&, color);

	bool move(SC, SC, vector<Chess*>);
	bool attack(SC, SC, vector<Chess*>);

	~JiangShuai() = default;
};

#endif
