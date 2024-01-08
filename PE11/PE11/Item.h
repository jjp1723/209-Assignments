#pragma once

#include <string>
using namespace std;

struct Item
{
	//Protected Variables
	protected:
		string name;
		int damage;
		int weight;

	//Public Constructor + Method
	public:
		Item();
		void Print();
};

