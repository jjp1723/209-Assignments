// snake.cpp : This file contains function definitions

#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include <iostream>
using namespace std;
using namespace sf;



// ----- Function Definitions -----



//display Function
void display(b2Vec2 target, b2Body* snake)
{
	cout << "Target: (" << target.x << ", " << target.y << ")";
	cout << "--- Snake: (" << snake->GetPosition().x << ", " << snake->GetPosition().y << ")" << endl;
}



//applyForces Function
void applyForces(char key, b2Body* snake)
{
    b2Vec2 force;
    switch (key)
    {
    case 'w':
        force = b2Vec2(0.0f, 50.0f);
        snake->ApplyForceToCenter(force, true);
        break;

    case 's':
        force = b2Vec2(0.0f, -20.0f);
        snake->ApplyForceToCenter(force, true);
        break;

    case 'a':
        force = b2Vec2(-10.0f, 0.0f);
        snake->ApplyForceToCenter(force, true);
        break;

    case 'd':
        force = b2Vec2(10.0f, 0.0f);
        snake->ApplyForceToCenter(force, true);
        break;
    }
}


//moveTarget Function
void moveTarget(b2Vec2* target)
{
    float x = float(rand()) / float(RAND_MAX) * 10.0 - 5.0;
    float y = float(rand()) / float(RAND_MAX) * 10.0 - 5.0;
    *target = b2Vec2(x, y);
}