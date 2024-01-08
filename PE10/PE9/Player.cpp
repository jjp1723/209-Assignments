#include "Player.h"

#include <iostream>
using namespace std;

//Parameterized Constructor
Player::Player(char* id, int hp, int str, int sp)
{
	name = id;
	health = hp;
	strength = str;
	speed = sp;
}

//Default Constructor
Player::Player()
{
	name = new char[10]{ "Unknown" };
	health = 10;
	strength = 10;
	speed = 10;
}

//Destructor
Player::~Player()
{
	delete name;
	name = nullptr;
}

//printPlayer Method
void Player::printPlayer()
{
	//Printing the player's name, health, strength, and speed
	cout << "Player: " << name << endl;
	cout << "Health: " << health << endl;
	cout << "Strength: " << strength << endl;
	cout << "Speed: " << speed << endl;
}
