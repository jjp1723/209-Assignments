#include <stdio.h>

//Calculating how many seconds there are in December
int seconds = 31 * 24 * 60 * 60;

//Calculating the area of a circle with radius 6.2
double area = 6.2 * 6.2 * 3.14159;

//Divide integers to determine how integer division works
double division = 5 / 2;

//Main method
int main()
{
	//Print "Hello World."
	printf("Hello World.\n");

	//Print # of seconds in December
	printf("There are %i seconds in the month of December\n", seconds);

	//Print area of a circle with a radius of 6.2
	printf("The area of a circle with a radius of 6.2 is %f\n", area);

	//Print the result of a division
	printf("The division of 5/2 is truncated to %f by C++\n", division);
}
