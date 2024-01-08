// PE18.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "NumberPrinter.h"
#include "GamePlay.h"
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <string>
using namespace std;

int main()
{
    // ----- Part 1 -----

    /*
    //For loop runs 10 times, creating a new NumberPrinter object and its Print() method
    for (int count = 0; count < 10; count++)
    {
        NumberPrinter printer = NumberPrinter(5);
        printer.Print();
    }
    */

    //Creating a thread object and passing in the NumberPrinter's Print() method as the parameter
    mutex mtx;
    vector<thread*> printerThreads;
    NumberPrinter printer = NumberPrinter(5);

    //Using 50 threads, each of which prints 50 numbers
    for (int count = 0; count < 50; count++)
    {
        printerThreads.push_back(new thread(&NumberPrinter::Print, printer, &mtx));
    }

    for (int index = 0; index < 50; index++)
    {
        printerThreads[index]->join();
        delete printerThreads[index];
    }



    // ----- Part 2 -----

    //Creating 5 unique GamePlay Objects
    GamePlay physics = GamePlay("Physics");
    GamePlay controls = GamePlay("Controls");
    GamePlay lighting = GamePlay("Lighting");
    GamePlay textures = GamePlay("Textures");
    GamePlay pathfinding = GamePlay("Pathfinding");

    //Creating a vector<thread*> to hold the threads
    vector<thread*> gamePlayThreads;

    //Adding 5 new thread objects to the vector<thread*>
    gamePlayThreads.push_back(new thread(&GamePlay::Update, physics));
    gamePlayThreads.push_back(new thread(&GamePlay::Update, controls));
    gamePlayThreads.push_back(new thread(&GamePlay::Update, lighting));
    gamePlayThreads.push_back(new thread(&GamePlay::Update, textures));
    gamePlayThreads.push_back(new thread(&GamePlay::Update, pathfinding));

    //Joining the threads to make them finish before the main thread
    gamePlayThreads[0]->join();
    gamePlayThreads[1]->join();
    gamePlayThreads[2]->join();
    gamePlayThreads[3]->join();
    gamePlayThreads[4]->join();

    cout << "Update Complete!\tTime to Draw" << endl;
}
