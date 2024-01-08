// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

//To make my game unique, I added audio in the form of background music,
// sound effects that play when you hit the target, and a sound that plays upon finishing the game
//
//The audio is loaded on lines 174-201, and the sound effect and victory sound are played on lines 294 and 317 respectively

#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include <conio.h>
#include <cmath>
#include <string>

using namespace std;
using namespace sf;

#include "snake.h"
#define esc 27

int main()
{
    {
        // ----- Setting core variables to keep track of the user's score -----

        //'hit' variable keeps track of how many targets have been hit
        int hit = 0;

        //'keys' variable keeps track of how many keys have been pressed (not counting holding a key)
        int keys = 0;

        //'score' will be altered as the game progresses to represent the player's score
        int score = 1000;



        // ----- Creating physics world -----
        b2Vec2 gravity(0.0f, -4.9f);
        b2World world(gravity);



        // ----- Creating walls around the world -----

        //Creating horizonBox to use when creating the top and bottom walls
        b2PolygonShape horizonBox;
        horizonBox.SetAsBox(5.0f, 1.0f);

        //Creating vertBox to use when creating the left and right walls
        b2PolygonShape vertBox;
        vertBox.SetAsBox(1.0f, 5.0f);

        //Creating the top wall around the world
        b2BodyDef topWallDef;
        topWallDef.position.Set(5.0f, 11.0f);
        b2Body* topWall = world.CreateBody(&topWallDef);
        topWall->CreateFixture(&horizonBox, 0.0f);

        //Creating the bottom wall around the world
        b2BodyDef bottomWallDef;
        bottomWallDef.position.Set(5.0f, -1.0f);
        b2Body* bottomWall = world.CreateBody(&bottomWallDef);
        bottomWall->CreateFixture(&horizonBox, 0.0f);

        //Creating the left wall around the world
        b2BodyDef leftWallDef;
        leftWallDef.position.Set(-1.0f, 5.0f);
        b2Body* leftWall = world.CreateBody(&leftWallDef);
        leftWall->CreateFixture(&vertBox, 0.0f);

        //Creating the right wall around the world
        b2BodyDef rightWallDef;
        rightWallDef.position.Set(11.0f, 5.0f);
        b2Body* rightWall = world.CreateBody(&rightWallDef);
        rightWall->CreateFixture(&vertBox, 0.0f);



        // ----- Creating the snake -----
        b2BodyDef snakeDef;
        snakeDef.type = b2_dynamicBody;
        snakeDef.position.Set(5.0f, 5.0f);
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
        float x = float(rand()) / float(RAND_MAX) * 10.0;
        float y = float(rand()) / float(RAND_MAX) * 10.0;
        b2Vec2 target(x, y);



        // ----- Creating the window -----
        RenderWindow window(VideoMode(750, 750), "Graphical Snake");



        // ----- Creating the shapes to be dispayed in the window -----

        //The snake
        CircleShape snakeHead (25);
        snakeHead.setFillColor(Color(100, 250, 50));
        float snakeX = 100 + snake->GetPosition().x * 50;
        float snakeY = 600 - snake->GetPosition().y * 50;
        snakeHead.setPosition(Vector2f(snakeX, snakeY));

        //The target
        CircleShape targetCircle (25);
        targetCircle.setFillColor(Color(250, 0, 0));
        float targetX = 100 + x * 50;
        float targetY = 600 - y * 50;
        targetCircle.setPosition(Vector2f(targetX, targetY));

        //The top rectangle
        RectangleShape topRect(Vector2f(800, 125));
        topRect.setFillColor(Color(0, 0, 250));

        //The bottom rectangle
        RectangleShape bottomRect(Vector2f(800, 125));
        bottomRect.setFillColor(Color(0, 0, 250));
        bottomRect.setPosition(Vector2f(0, 625));

        //The left rectangle
        RectangleShape leftRect(Vector2f(125, 800));
        leftRect.setFillColor(Color(0, 0, 250));

        //The right rectangle
        RectangleShape rightRect(Vector2f(125, 800));
        rightRect.setFillColor(Color(0, 0, 250));
        rightRect.setPosition(Vector2f(625, 0));



        // ----- Loading font -----
        Font font;
        if (!font.loadFromFile("Roboto-Medium.ttf"))
        {
            cout << "Error loading font file" << endl;
        }

        // ----- Providing instructions to the user -----
        Text topText;
        topText.setFont(font);
        topText.setString("Welcome to Graphical Snake!\tHit 10 targets to win!\nUse WASD to move.\nUse as few inputs as possible to get a higher score.");

        Text bottomText;
        bottomText.setFont(font);
        string hitString = to_string(hit);
        bottomText.setString("Targets Hit: " + hitString);
        bottomText.setPosition(Vector2f(0, 635));



        // ----- Loading music and sounds -----

        //Music
        Music music;
        if (!music.openFromFile("dr-mario-fever-orchestral-cover.wav"))
        {
            cout << "Error loading music mp3" << endl;
        }
        music.setVolume(50.0f);
        music.play();

        //Sound effect
        SoundBuffer buffer;
        if (!buffer.loadFromFile("dk-barrel-jump.wav"))
        {
            cout << "Error loading sound effect" << endl;
        }
        Sound sound;
        sound.setBuffer(buffer);

        //Victory cheering sound
        SoundBuffer winBuffer;
        if (!winBuffer.loadFromFile("children-cheering.wav"))
        {
            cout << "Error loading victory cheering sound" << endl;
        }
        Sound winSound;
        winSound.setBuffer(winBuffer);



        // ----- Creating while loop to keep running until the player hits ESC or hits two targets -----
        b2Vec2 force;
        Clock deltaClock;
        Time deltaTime;

        //This boolean will be used to pause the game on the final frame until the user exits
        bool finished = false;

        while (window.isOpen())
        {
            //Updating the clock and deltatime
            deltaTime = deltaClock.getElapsedTime();
            deltaClock.restart();
            world.Step(deltaTime.asSeconds(), 6, 2);

            //Checking all the window's events that were triggered since the last iteration of the loop
            Event event;
            while (window.pollEvent(event))
            {
                //"close requested" event closes the window
                if (event.type == Event::Closed)
                    window.close();
            }

            //Clear the window with black color
            window.clear(sf::Color::Black);

            //Updating the snakeHead's position
            snakeX = 100 + snake->GetPosition().x * 50;
            snakeY = 600 - snake->GetPosition().y * 50;
            snakeHead.setPosition(Vector2f(snakeX, snakeY));



            // ----- Drawing everything -----
            window.draw(topRect);
            window.draw(bottomRect);
            window.draw(leftRect);
            window.draw(rightRect);
            window.draw(snakeHead);
            window.draw(targetCircle);
            window.draw(topText);
            window.draw(bottomText);



            // ----- Checking for inputs as long as the user hasn't already won -----
            if (hit < 10)
            {
                //Every frame the user holds one of the four main keys (WASD), their score decrements by 1 point
                if (Keyboard::isKeyPressed(Keyboard::W))
                {
                    applyForces('w', snake);
                    keys++;
                    score -= 1;
                }
                if (Keyboard::isKeyPressed(Keyboard::A))
                {
                    applyForces('a', snake);
                    keys++;
                    score -= 1;
                }
                if (Keyboard::isKeyPressed(Keyboard::S))
                {
                    applyForces('s', snake);
                    keys++;
                    score -= 1;
                }
                if (Keyboard::isKeyPressed(Keyboard::D))
                {
                    applyForces('d', snake);
                    keys++;
                    score -= 1;
                }
            }

            //Pressing 'esc' closes the window
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }
            

            //Checking the distance between the snake and the target, and calling the 'moveTarget' function accordingly
            if (sqrtf(powf(target.x - snake->GetPosition().x, 2.0f) + powf(target.y - snake->GetPosition().y, 2.0f)) < 1.0f)
            {
                moveTarget(&target);

                //Playing a sound the effect when the player hits the target
                sound.play();

                //Updating the amount of targets hit and score, and printing the hit count to the user
                hit++;
                score += 500;
                hitString = to_string(hit);
                bottomText.setString("Targets Hit: " + hitString);

                //Updating the displayed target in the window
                targetX = 100 + target.x * 50;
                targetY = 600 - target.y * 50;
                targetCircle.setPosition(Vector2f(targetX, targetY));
            }

            //If the user hits 5 targets, the bottom text is changed to display such, as well as the user's final score
            if (hit == 10)
            {
                hitString = to_string(hit);
                string scoreString = to_string(score);
                bottomText.setString("Targets Hit: " + hitString + "\tYour Final Score: " + scoreString + "\n\nTo exit, press 'esc'.");
                hit++;

                //Playing the victory sound
                winSound.play();
            }

            //Making negative scores impossible
            if (score < 0)
            {
                score = 0;
            }

            //Dispaly Function
            //display(target, snake);

            //Ending the current frame
            window.display();
        }
    }

    // ----- Deleting pointers -----
    _CrtDumpMemoryLeaks();
}