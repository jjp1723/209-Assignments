#include "Item.h"

#include <iostream>
using namespace std;

//Default Constructor
Item::Item()
{
	name = "Something";
	damage = 0;
	weight = 0;
}

//Print Function
void Item::Print()
{
	cout << "Name: " << name << endl;
	cout << "Damage: " << damage << endl;
	cout << "Weight: " << weight << endl;
	cout << endl;
}
