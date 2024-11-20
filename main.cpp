#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //-------------------INITIALIZE----------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1600, 900), "RPG Game", sf::Style::Default, settings);
    
    //-------------------INITIALIZE----------------


    //-------------------LOAD----------------
    //-------------------Skeleton----------------
    sf::Texture skeletonTexture;
    sf::Sprite skeletonSprite;

    if (skeletonTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
    {
        std::cout << "Skeleton texture loaded!\n";
        skeletonSprite.setTexture(skeletonTexture);
        skeletonSprite.setPosition(sf::Vector2f(400, 100));

        int XIndex = 0;
        int YIndex = 2;

        skeletonSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
    }
    else
        std::cout << "Skeleton texture failed to load!\n";
    //-------------------Skeleton----------------

    //-------------------Player----------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player texture loaded!\n";
        playerSprite.setTexture(playerTexture);

        int XIndex = 0;
        int YIndex = 0;

        playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
    }
    else
        std::cout << "Player texture failed to load!\n";
    //-------------------Player----------------
    //-------------------LOAD----------------


    // main game loop
    while (window.isOpen())
    {
        //-------------------UPDATE----------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(1, 0));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            playerSprite.setPosition(position + sf::Vector2f(0, 1));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            playerSprite.setPosition(position + sf::Vector2f(0, -1));
        //-------------------UPDATE----------------


        //-------------------DRAW----------------
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.draw(skeletonSprite);
        window.display();
        //-------------------DRAW----------------
    }
    return 0;
}