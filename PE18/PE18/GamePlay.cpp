#include "GamePlay.h"

GamePlay::GamePlay(string id)
{
	name = id;
}

void GamePlay::Update()
{
	this_thread::sleep_for(1s);

	for (int count = 1; count < 11; count++)
	{
		cout << name << ": " << count << "0% Complete" << endl;
	}
}
