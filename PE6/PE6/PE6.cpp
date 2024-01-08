// PE6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>

using namespace std;

//'generateRandom' Method
void generateRandom(int numberOfRandoms)
{
    //Seeding a random
    srand(time(NULL));

    //Generating a number of random values
    for (int i = 1; i < numberOfRandoms + 1; i++)
    {
        cout << "Iteration count: " << i + 1 << endl;
        int random = rand();
        cout << "Random value: " << rand() << "\n" << endl;
    }
}

//'reverseString' Method - Doesn't work due to newString not getting new values assigned properly
char* reverseString(char inputString[])
{
    char newString[256] = "";
    int length = strlen(inputString);
    for (int i = 0; i < length; i++)
    {
        char c = inputString[i];
        newString[length - i] = c;
    }
    strcpy_s(inputString, 128, newString);
    return inputString;

}

int main()
{
    //Part 1 - Generating random numbers
    generateRandom(30);

    //Part 2 - Using the debugger on 'reverseString'
    char string[256] = "";
    cout << "Enter a string." << endl;
    cin.getline(string, 255);
    reverseString(string);
    cout << "Reversed string: " << string << endl;
    //It doesn't print the reversed string properly because when the 'reverseString' method tries to
    // store the char 'c' at the index 'length-i' in 'newString', nothing is stored.
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
