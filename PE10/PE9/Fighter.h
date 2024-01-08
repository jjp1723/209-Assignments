#pragma once
#include "Player.h"
class Fighter : public Player
{
    //Private Variable
    private:
        char* skill;

    //Public Constructors + Method
    public:
        Fighter(char* id, char* sk, int hp, int str, int sp);
        Fighter();
        ~Fighter();
        void printFighter();
};

