#pragma once
#include <SFML/Graphics.hpp>

class FrameRate
{
private:
    sf::Text deltaTimeText;
    sf::Text frameRateText;
    sf::Font font;
    sf::Time elapsedTime;
    sf::Clock fpsClock;

public:
    int frameCount;

public:
    FrameRate();
    ~FrameRate();

    void Initialize();
    void Load(); 
    void Update(float deltaTime); 
    void Draw(sf::RenderWindow& window); 
};