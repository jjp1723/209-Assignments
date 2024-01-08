// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
using namespace sf;

#include "snake.h"
#define esc 27

int main()
{
    {
        // ----- Introducing the game and contols to the user -----
        cout << "Welcome to Gravity Snake" << endl;
        cout << "Use the WASD keys to move" << endl;
        cout << "Hit the target five times to win!" << endl;
        cout << "If it's too challenging, press 'ESC' to quit" << endl;
        cout << "\nPress any key to continue\n\n" << endl;
        cin.get();

        //'hit' variable keeps track of how many targets have been hit
        int hit = 0;

        //'keys' variable keeps track of how many keys have been pressed (not counting holding a key)
        int keys = 0;

        //'lastKey' stores the last key pressed so that holding a key doesn't count as pressing it many times
        char lastKey = ' ';

        //'score' will be altered as the game progresses to represent the player's score
        int score = 1000;



        // ----- Creating physics world -----
        b2Vec2 gravity(0.0f, -9.8f);
        b2World world(gravity);



        // ----- Creating walls around the world -----

        //Creating horizonBox to use when creating the top and bottom walls
        b2PolygonShape horizonBox;
        horizonBox.SetAsBox(5.0f, 1.0f);

        //Creating vertBox to use when creating the left and right walls
        b2PolygonShape vertBox;
        vertBox.SetAsBox(1.0f, 5.0f);

        //Creating the bottom wall around to world
        b2BodyDef bottomWallDef;
        bottomWallDef.position.Set(0.0f, -6.5f);
        b2Body* bottomWall = world.CreateBody(&bottomWallDef);
        bottomWall->CreateFixture(&horizonBox, 0.0f);

        //Creating the top wall around to worldss
        b2BodyDef topWallDef;
        topWallDef.position.Set(0.0f, 6.5f);
        b2Body* topWall = world.CreateBody(&topWallDef);
        topWall->CreateFixture(&horizonBox, 0.0f);

        //Creating the left wall around the world
        b2BodyDef leftWallDef;
        leftWallDef.position.Set(-6.5f, 0.0f);
        b2Body* leftWall = world.CreateBody(&leftWallDef);
        leftWall->CreateFixture(&vertBox, 0.0f);

        //Creating the right wall around the world
        b2BodyDef rightWallDef;
        rightWallDef.position.Set(6.5f, 0.0f);
        b2Body* rightWall = world.CreateBody(&rightWallDef);
        rightWall->CreateFixture(&vertBox, 0.0f);



        // ----- Creating the snake -----
        b2BodyDef snakeDef;
        snakeDef.type = b2_dynamicBody;
        snakeDef.position.Set(0.0f, 3.0f);
        b2Body* snake = world.CreateBody(&snakeDef);

        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(0.5f, 0.5f);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        snake->CreateFixture(&fixtureDef);



        // ----- Creating the target -----
        srand(time(NULL));
        rand();
        float x = float(rand()) / float(RAND_MAX) * 10.0 - 5.0;
        float y = float(rand()) / float(RAND_MAX) * 10.0 - 5.0;
        b2Vec2 target(x, y);



        // ----- Creating while loop to keep running until the player hits ESC or hits two targets -----
        bool running = true;
        b2Vec2 force;
        Clock deltaClock;
        Time deltaTime;
        while (running)
        {
            deltaTime = deltaClock.getElapsedTime();
            deltaClock.restart();
            world.Step(deltaTime.asSeconds(), 6, 2);

            //Checking for keypresses, and calling the 'applyForces' function accordingly
            if (_kbhit())
            {
                if (_getch() == esc)
                {
                    running = false;
                    cout << "\n\nGiving up?  I guess that's okay." << endl;
                    break;
                }

                applyForces(_getch(), snake);

                //Updating the player's score based on key presses that change the snake's direction
                if (_getch() != lastKey)
                {
                    lastKey = _getch();
                    keys++;
                    score -= 25;
                }
            }

            //Checking the distance between the snake and the target, and calling the 'moveTarget' function accordingly
            if (sqrtf(powf(target.x - snake->GetPosition().x, 2.0f) + powf(target.y - snake->GetPosition().y, 2.0f)) < 1.0f)
            {
                moveTarget(&target);
                hit++;
                score += 200;
            }

            //Dispaly Function
            display(target, snake);

            if (hit >= 5)
            {
                running = false;
                cout << "\n\nYou hit the target all five times, good job!" << endl;;
            }
        }

        cout << "You changed the snake's direction " << keys << " times and hit " << hit << " targets, giving you the final score of:\n" << score << endl;
        cin.get();
    }

    // ----- Deleting pointers -----
    _CrtDumpMemoryLeaks();
}