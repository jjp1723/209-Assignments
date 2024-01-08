// PE13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;



// ----- Methods -----

//itaerativeHands Method - Uses iteration to find the total number of hands in a row with 'n' seats
int iterativeHands(int n)
{
    int total = 0;
    
    //Using a 'for-loop' to iterate through each seat in the row
    for (int seat = 1; seat < n + 1; seat++)
    {
        //If the current seat is odd, the total amount of hands increases by 3
        if (seat % 2 == 1)
        {
            total += 3;
        }

        //If the current seat is even, the total amount of hands increases by 4
        else
        {
            total += 4;
        }
    }

    //Returning the total
    return total;
}



//recursiveHands Method - Uses recursion to find the total number of hands in a row with 'n' seats
int recursiveHands(int n, int seat)
{
    int total = 0;

    //If the current seat is odd, the total amount of hands increases by 3
    if (seat % 2 == 1)
    {
        total += 3;
    }

    //If the current seat is even, the total amount of hands increases by 4
    else
    {
        total += 4;
    }



    //If this is the last seat in the row, this is the base case; the method is no longer called recursively
    if (seat == n)
    {
        return total;
    }

    //The method continues to call itself recursively to reach the base case
    else
    {
        return (total + recursiveHands(n, seat + 1));
    }
}



//formulaHands Method - Uses a formula to find the total number of hands in a row with 'n' seats
int formulaHands(int n)
{
    //Calculating the total number of even and odd seats and multipling said number by the corresponding amount of hands
    // and returning the total

    return (ceil(n / 2) * 3 + floor(n / 2) * 4);
}



// ----- BONUS -----
// knightPath Method - Doesn't function completely, but at least it functions at all
void knightPath(int x, int y, bool visited[8][8])
{
    bool cont = true;
    char pause = ' ';

    while (cont)
    {
        cout << "Knight's current position: (" << x << ", " << y << ")" << endl;

        //Checking if the knight can move up 2 spaces and that it hasn't already visited the spaces it can move to
        if (y + 2 < 8 && ((x - 1 > -1 || x + 1 < 8) && (!visited[x - 1][y + 2] || !visited[x + 1][y + 2])))
        {
            cout << "Moving up" << endl;
            //Checking if the knight can move left 1 space
            if (x - 1 > -1 )
            {
                //Checking is the night has already visited the space, if not it moves there
                if (!visited[x - 1][y + 2])
                {
                    y += 2;
                    x -= 1;
                }
                else
                {
                    cout << "(" << x - 1 << ", " << y + 2 << ")" << " has been visited already" << endl;
                    cont = false;
                }
            }

            //Checking if the knight can move right 1 space
            else if (x + 1 < 8)
            {
                if (!visited[x + 1][y + 2])
                {
                    y += 2;
                    x += 1;
                }
                else
                {
                    cout << "(" << x + 1 << ", " << y + 2 << ")" << " has been visited already" << endl;
                    cont = false;
                }
            }
        }

        //Checking if the knight can move down 2 spaces and that it hasn't already visited the spaces it can move to
        else if (y - 2 > -1 && ((x - 1 > -1 || x + 1 < 8) && (!visited[x - 1][y - 2] || !visited[x + 1][y - 2])))
        {
            cout << "Moving down" << endl;
            //Checking if the knight can move left 1 space
            if (x - 1 > -1)
            {
                //Checking is the night has already visited the space, if not it moves there
                if (!visited[x - 1][y - 2])
                {
                    y -= 2;
                    x -= 1;
                }
                else
                {
                    cout << "(" << x - 1 << ", " << y - 2 << ")" << " has been visited already" << endl;
                    cont = false;
                }
            }

            //Checking if the knight can move right 1 space
            else if (x + 1 < 8)
            {
                if (!visited[x + 1][y - 2])
                {
                    y -= 2;
                    x += 1;
                }
                else
                {
                    cout << "(" << x + 1 << ", " << y - 2 << ")" << " has been visited already" << endl;
                    cont = false;
                }
            }
        }

        //Checking if the knight can move right 2 spaces and that it hasn't already visited the spaces it can move to
        else if (x + 2 < 8 && ((y - 1 > -1 || y + 1 < 8) && (!visited[x + 2][y - 1] || !visited[x + 2][y + 1])))
        {
            cout << "Moving right" << endl;
            //Checking if the knight can move down 1 space
            if (y - 1 > -1)
            {
                //Checking is the night has already visited the space, if not it moves there
                if (!visited[x + 2][y - 1])
                {
                    y -= 1;
                    x += 2;
                }
                else
                {
                    cout << "(" << x + 2 << ", " << y - 1 << ")" << " has been visited already" << endl;
                    cont = false;
                }
            }

            //Checking if the knight can move right 1 space
            else if (y + 1 < 8)
            {
                if (!visited[x + 2][y + 1])
                {
                    y += 1;
                    x += 2;
                }
                else
                {
                    cout << "(" << x + 2 << ", " << y + 1 << ")" << " has been visited already" << endl;
                    cont = false;
                }
            }
        }

        //Checking if the knight can move left 2 spaces and that it hasn't already visited the spaces it can move to
        else if (x - 2 > -1 && ((y - 1 > -1 || y + 1 < 8) && (!visited[x - 2][y - 1] || !visited[x - 2][y + 1])))
        {
            cout << "Moving left" << endl;
            //Checking if the knight can move down 1 space
            if (y - 1 > -1)
            {
                //Checking is the night has already visited the space, if not it moves there
                if (!visited[x - 2][y - 1])
                {
                    y -= 1;
                    x -= 2;
                }
                else
                {
                    cout << "(" << x - 2 << ", " << y - 1 << ")" << " has been visited already" << endl;
                    cont = false;
                }
            }

            //Checking if the knight can move right 1 space
            else if (y + 1 < 8)
            {
                if (!visited[x - 2][y + 1])
                {
                    y += 1;
                    x -= 2;
                }
                else
                {
                    cout << "(" << x - 2 << ", " << y + 1 << ")" << " has been visited already" << endl;
                    cont = false;
                }
            }
        }

        else
        {
            cout << "Can't move" << endl;
            cont = false;
        }

        //Marking the current space as visited
        visited[x][y] = true;

        //cin >> pause;
    }
}




// ----- Main Method -----

int main()
{
    //Setting the number of seats
    int n = 10;

    //iterativeHands
    cout << "Iterative Method - Total number of hands in a row with " << n << " seats: " << iterativeHands(n) << endl;

    //recursiveHands
    cout << "Recursive Method - Total number of hands in a row with " << n << " seats: " << recursiveHands(n, 1) << endl;

    //formulaHands
    cout << "Formulaic Method - Total number of hands in a row with " << n << " seats: " << formulaHands(n) << endl;



    //BONUS - knightPath
    //Creating the 2D array
    bool chessboard[8][8];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            chessboard[i][j] = false;
        }
    }

    chessboard[0][2] = true;

    cout << "\n\n\nBONUS - Printing the path of a Knight on a chessboard starting at (0, 2)" << endl;

    knightPath(0, 2, chessboard);
}
