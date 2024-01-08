// PE4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    //#1, 2, 3 - Creating the string and printing it's length
    char string1[40] = "supercalifragilistic";
    cout << "Length of the string: " << strlen(string1) << endl;
    
    //#4 - Creating the second string and adding on to the end of the first
    char string2[] = "expialidocious";
    strcat_s(string1, string2);
    cout << "Combined strings: " << string1 << endl;

    //#5 - Find out how many times the character "i" is occurs in the combined string
    int count = 0;
    char eye = 'i';
    for (int i = 0; i < strlen(string1); i++)
    {
        if (string1[i] == eye)
        {
            count++;
        }
    }
    cout << "The letter \'i\' is used " << count << " times in the word \"" << string1 << "\"" << endl;
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
