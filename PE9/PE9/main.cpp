// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "Player.h"

using namespace std;

int main()
{
	//Creating four players; two on the stack and two on the heap
	Player player1 = Player();
	Player player2 = Player(new char[5]{ "John" }, 19, 19, 7);
	Player* player3 = new Player();
	Player* player4 = new Player(new char[6]{ "Chris" }, 17, 21, 6);

	//Printing out all four players
	player1.printPlayer();
	player2.printPlayer();
	player3->printPlayer();
	player4->printPlayer();

	//Deleting all four players
	player1.~Player();
	player2.~Player();
	player3->~Player();
	player4->~Player();
	delete player3;
	delete player4;
	player3 = nullptr;
	player4 = nullptr;

	_CrtDumpMemoryLeaks();
}