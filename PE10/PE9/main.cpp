// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "Player.h"
#include "Fighter.h"

using namespace std;

int main()
{
	//Creating two fighters; one using the parameterized constructor and one using the default constructor
	Fighter paramFighter = Fighter(new char [5]{ "John" }, new char[6]{ "Flame" }, 18, 18, 18);
	Fighter defaultFighter = Fighter();

	//Printing out both fighters
	paramFighter.printFighter();
	defaultFighter.printFighter();

	//Deleting both fighters
	paramFighter.~Fighter();
	defaultFighter.~Fighter();

	//Checking for memory leaks
	_CrtDumpMemoryLeaks();
}