// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "hangman.h"

using namespace std;

int main()
{
    // ----- Declaring variables -----

    //'play' determines if the game continues
    bool play = true;

    //The word the user will guess
    char word[] = "racecar";


    //'guessedRight' and 'guessedWrong' keep track of correctly and incorrectly guessed letters
    char guessedRight[99] = "";
    char guessedWrong[99] = "";

    //'wrongGuesses' keeps track of how many wrong guess there were
    int wrongGuesses = 0;

    //'guess' and 'found' will be used to determine if the user guesses a letter in the word
    char guess[100];
    bool found = false;

    //Game loop
    while (true)
    {
        //Displaying the gallows
        showGallows(wrongGuesses);
        showSolveDisplay(word, guessedRight, guessedWrong);

        //Having the user guess a letter
        cout << "Please guess a letter" << endl;
        cin.getline(guess, 2);

        //Checking if the letter is found within the word
        found = false;
        for (int i = 0; i < strlen(word); i++)
        {
            if (guess[0] == word[i])
            {
                found = true;
                break;
            }
        }

        //If the letter was found, it is added to the list of correct guesses, if not, it is added to the list of incorrect guesses.
        if (found)
        {
            strcat_s(guessedRight, guess);
        }
        if (!found)
        {
            strcat_s(guessedWrong, guess);
            wrongGuesses++;
        }

        //Searching the word for unguessed letters
        bool allFound = true;
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

            //If the corresponding letter isn't found, the game doesn't end
            if (!found)
            {
                allFound = false;
            }
        }

        //If all the letters have been guessed, the game ends
        if (allFound)
        {
            showGallows(wrongGuesses);
            showSolveDisplay(word, guessedRight, guessedWrong);
            cout << "\nCongratulations, you guessed the word!" << endl;
            break;
        }

        //If the user is out of guesses, the game ends
        if (wrongGuesses >= 6)
        {
            showGallows(wrongGuesses);
            showSolveDisplay(word, guessedRight, guessedWrong);
            cout << "Too bad, you ran out of guesses!" << endl;
            break;
        }
    }

    cout << "Play again sometime!" << endl;

    return 0;
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
