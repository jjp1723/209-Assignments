#include "GameLevel.h"

#include <iostream>

using namespace std;

GameLevel::GameLevel()
{
	name = "Unknown";
	levelNum = 0;
	difficulty = "Unknown";

	cout << "Default GameLevel created." << endl;
}

GameLevel::GameLevel(string id, int num, string hard)
{
	name = id;
	levelNum = num;
	difficulty = hard;

	cout << "Parameterized GameLevel created." << endl;
}

GameLevel::~GameLevel()
{
	cout << "GameLevel destroyed." << endl;
}

void GameLevel::PrintLevel()
{
	cout << "\nLevel name: " << name << endl;
	cout << "Level number: " << levelNum << endl;
	cout << "Level difficulty: " << difficulty << endl;
	cout << endl;
}
