// PE16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // ----- Using an 'ofstream' object to create and write a few lines to a text file -----

    ofstream outFile = ofstream("text.txt");

    if (outFile.is_open())
    {
        outFile << "Hello File IO World" << endl;
        outFile << "Hello New Line!  ";
        outFile << "Hello Same Line!";
    }

    outFile.close();



    // ----- Using an 'ifstream' object to read the file back in using binary mode -----

    ifstream inFile = ifstream("text.txt", ios::binary);
    char entire[99];

    if (inFile.is_open())
    {
        //(a) - Reading the file in binary mode
        inFile.seekg(0, ios::end);
        int length = (int)inFile.tellg();
        inFile.seekg(0, ios::beg);

        //(b) - Reading the entire file to a single array
        char* fileContents = new char[length + 1];
        inFile.read(fileContents, length);
        fileContents[length] = 0;

        //(c) - Printing the file's contents to the console window
        cout << fileContents << endl;
    }

    inFile.close();



    /*//Video Lecture Example Code

    * const int OBFUSCATION_KEY = 58205934059;
    string saveData = "Lives: 5, Position: (10, 14), Level: 3";

    for (int i = 0, length = saveData.length(); i < length; i++)
    {
        saveData[i] ^= OBFUSCATION_KEY;
    }

    outFile.open("saveData.txt");
    if (outFile.is_open())
    {
        outFile << saveData;
    }

    outFile.close();



    inFile.open("saveData.txt");
    fileAsString = string(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>());
    inFile.close();

    for (int i = 0, length = fileAsString.length(); i < length; i++)
    {
        fileAsString[i] ^= OBFUSCATION_KEY;
    }

    cout << fileAsString << endl;
    */
}
