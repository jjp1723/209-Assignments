#pragma once
#include <string>
#include <iostream>

using namespace std;

class GameLevel
{
	//Private Attributes
	private:
		string name;
		int levelNum;
		string difficulty;
		
	//Public Constructors, Destructor, and Function(s)
	public:
		GameLevel();
		GameLevel(string id, int num, string hard);
		~GameLevel();
		void PrintLevel();
};

