#pragma once
class Player
{
	//Private Variables
	private:
		char* name;
		int health;
		int strength;
		int speed;

	//Public Constructors + Methods
	public:
		Player(char* id, int hp, int str, int sp);
		Player();
		~Player();
		void printPlayer();
};

