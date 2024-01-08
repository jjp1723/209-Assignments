#include "Test.h"

//Default Constructor
Test::Test()
{
	number = 0;
}

//Parameterized Constructor
Test::Test(int num)
{
	number = num;
}

//Friend ostream operator
ostream& operator<<(ostream& ostr, Test const& rightSide)
{
	ostr << rightSide.number;
	return ostr;
}
