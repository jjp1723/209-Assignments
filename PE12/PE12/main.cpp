// PE12.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "GameLevel.h";

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include <memory>

using namespace std;

//Smart pointer function
void SmartGameLevelPointer()
{
    unique_ptr<GameLevel> smartLevel(new GameLevel("Death Mountain", 3, "Hard"));
    smartLevel->PrintLevel();
}

//Normal pointer function
void NormalGameLevelPointer()
{
    GameLevel* normalLevel = new GameLevel();
    normalLevel->PrintLevel();
}

int main()
{
    SmartGameLevelPointer();
    NormalGameLevelPointer();

    _CrtDumpMemoryLeaks();
}
