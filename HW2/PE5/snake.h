// snake.h : This file contains function declarations

#pragma once
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include <iostream>
using namespace std;
using namespace sf;



// ----- Declaring Functions -----

void display(b2Vec2 target, b2Body* snake);
void applyForces(char key, b2Body* snake);
void moveTarget(b2Vec2* target);