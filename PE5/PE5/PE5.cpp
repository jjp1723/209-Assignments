// PE5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define SFML_STATIC
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>

#include <iostream>
using namespace std;

int main()
{
    //Creating the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    //Running the program as long as the window is open
    while (window.isOpen())
    {
        //Checking all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            //"close requested" event closes the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // ----- Drawing everything -----

        //Drawing a green circle
        sf::CircleShape circle1 (50);
        circle1.setFillColor(sf::Color(100, 250, 50));
        window.draw(circle1);

        //Drawing a purple circle with an orange outline
        sf::CircleShape circle2(50);
        circle2.setFillColor(sf::Color(150, 50, 250));
        circle2.setOutlineThickness(5);
        circle2.setOutlineColor(sf::Color(250, 150, 100));
        circle2.setPosition(sf::Vector2f(100, 100));
        window.draw(circle2);

        //Drawing a red rectangle
        sf::RectangleShape rect1(sf::Vector2f(120, 50));
        rect1.setFillColor(sf::Color(250, 0, 0));
        rect1.setPosition(sf::Vector2f(20, 300));
        window.draw(rect1);

        //Drawing an orange triangle
        sf::CircleShape triangle(80, 3);
        triangle.setFillColor(sf::Color(250, 150, 100));
        triangle.setPosition(sf::Vector2f(420, 280));
        window.draw(triangle);

        //Drawing a blue square
        sf::CircleShape square(80, 4);
        square.setFillColor(sf::Color(0, 0, 250));
        square.setPosition(sf::Vector2f(380, 30));
        window.draw(square);

        // end the current frame
        window.display();
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
