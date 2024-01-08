#include "Fighter.h"

#include <iostream>
using namespace std;

//Parameterized Constructor - Passes values to Player's parameterized constructor and assigns value to 'skill'
Fighter::Fighter(char* id, char* sk, int hp, int str, int sp) : Player(id, hp, str, sp)
{
	skill = sk;
}

//Default Constructor - Calls Player's default constructor and assigns default value to 'skill'
Fighter::Fighter() : Player()
{
	skill = new char[10]{ "Unknown" };
}

//Destructor - Call's Player's destructor and deletes 'skill' pointer
Fighter::~Fighter()
{
	Player::~Player();
	delete skill;
	skill = nullptr;
}

//printFighter - Calls 'printPlayer()' and prints value for 'skill'
void Fighter::printFighter()
{
	Player::printPlayer();
	cout << "Weapon Skill: " << skill << endl;
	cout << endl;
}
