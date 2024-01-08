#pragma once
#include <iostream>
using namespace std;

class Test
{
	//Private Data
	private:
		int number;

	//Public Data
	public:
		//Friend ostream operator
		friend ostream& operator<<(ostream& ostr, Test const& rightSide);

		//Default Constructor
		Test();

		//Parameterized Constructor
		Test(int num);
};

