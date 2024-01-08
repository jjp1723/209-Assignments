// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "Item.h"
#include "Knife.h"
#include "Mace.h"
#include "Sword.h"
#include "Axe.h"

using namespace std;

int main()
{
	{
		//Creating four pointers; one for each class
		Knife* knife = new Knife();
		Mace* mace = new Mace();
		Sword* sword = new Sword();
		Axe* axe = new Axe();

		//Creating a vector*<Item> called inventory
		vector<Item*> inventory = vector<Item*>();

		//Adding each item created using the 'push_back' function
		inventory.push_back(knife);
		inventory.push_back(mace);
		inventory.push_back(sword);
		inventory.push_back(axe);

		//Looping through the inventory and calling 'Print()' for each item
		for (int index = 0; index < inventory.size(); index++)
		{
			inventory[index]->Print();
		}

		//Deleting pointers
		delete knife;
		delete mace;
		delete sword;
		delete axe;
		knife = nullptr;
		mace = nullptr;
		sword = nullptr;
		axe = nullptr;
	}

	//Checking for memory leaks
	_CrtDumpMemoryLeaks();
}