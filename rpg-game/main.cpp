#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "Skeleton.h"
#include "FrameRate.h"

int main()
{
    //-------------------INITIALIZE----------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    FrameRate frameRate;
    
    //-------------------INITIALIZE----------------
    frameRate.Initialize();
   
    //-------------------INITIALIZE----------------
    Player player;
    Skeleton skeleton;
    player.Initialize();
    skeleton.Initialize();
    //-------------------INITIALIZE----------------

    //-------------------LOAD----------------
    frameRate.Load();
    player.Load();
    skeleton.Load();
    //-------------------LOAD----------------

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time deltaTimeTimer = clock.restart();
        float deltaTime = deltaTimeTimer.asMilliseconds();

        frameRate.Update(deltaTime);
        //-------------------UPDATE----------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

        skeleton.Update(deltaTime);
        player.Update(deltaTime, skeleton, mousePosition);

        //-------------------UPDATE----------------

        //-------------------DRAW----------------
        window.clear(sf::Color::Black);
        player.Draw(window);
        skeleton.Draw(window);
        frameRate.Draw(window);
        window.display();
        //-------------------DRAW----------------
    }
    return 0;
}