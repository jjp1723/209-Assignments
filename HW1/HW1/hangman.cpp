#include <iostream>
#include "hangman.h"

using namespace std;

// ----- 'showGallows' Function -----
void showGallows(int wrongGuesses)
{
    cout << "________" << endl;
    cout << "|      |" << endl;

    //Adding the head for 1 wrong guess
    if (wrongGuesses > 0)
    {
        cout << "|      O" << endl;
    }
    else
    {
        cout << "|" << endl;
    }

    //Adding the neck/torso for 2 wrong guesses
    if (wrongGuesses > 1)
    {
        //Adding one arm for 3 wrong guesses
        if (wrongGuesses > 2)
        {
            //Adding the other arm for 4 wrong guesses
            if (wrongGuesses > 3)
            {
                cout << "|     /|\\" << endl;
            }
            else
            {
                cout << "|     /|" << endl;
            }
        }
        else
        {
            cout << "|      |" << endl;
        }
    }
    else
    {
        cout << "|" << endl;
    }

    //Adding one leg for 5 wrong guesses
    if (wrongGuesses > 4)
    {
        //Adding the last leg for 6 wrong guesses
        if (wrongGuesses > 5)
        {
            cout << "|     / \\" << endl;
        }
        else
        {
            cout << "|     /" << endl;
        }
    }
    else
    {
        cout << "|" << endl;
    }

    cout << "|" << endl;
    cout << "|" << endl;
    cout << "\nWrong guesses remaining: " << 6 - wrongGuesses << endl;
}



// ----- 'showSolveDisplay' Function -----

void showSolveDisplay(char word[], char guessedRight[], char guessedWrong[])
{
    //Displaying the incorrect guesses
    cout << "\nIncorrect guesses: ";
    for (int j = 0; j < strlen(guessedWrong); j++)
    {
        cout << guessedWrong[j] << " ";
    }
    cout << "\n";

    //Displaying the correct guesses in their corresponding positions
    for (int i = 0; i < strlen(word); i++)
    {
        bool found = false;

        //Searching the correct guesses to see which guess corresponds to the current index of the word
        for (int j = 0; j < strlen(guessedRight); j++)
        {
            if (word[i] == guessedRight[j])
            {
                found = true;
            }
        }

        //If the corresponding letter is found, it is displayed, otherwise a blank space is displayed
        if (found)
        {
            cout << word[i] << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
}