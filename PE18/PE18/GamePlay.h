#pragma once
#include <string>
#include <iostream>
#include <thread>
using namespace std;

class GamePlay
{
protected:
	string name;

public:
	GamePlay(string id);
	void Update();
};

