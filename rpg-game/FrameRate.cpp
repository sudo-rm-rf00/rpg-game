#include "FrameRate.h"
#include <iostream>

FrameRate::FrameRate() :
    frameCount(0)
{
}

FrameRate::~FrameRate()
{
}

void FrameRate::Initialize()
{
    sf::Text deltaTimeText;
    sf::Text frameRateText;
    sf::Font font;
}

void FrameRate::Load()
{
    if (font.loadFromFile("../Assets/Fonts/arial.ttf"))
    {
        std::cout << "Font loaded!\n";
        frameRateText.setFont(font);
        deltaTimeText.setFont(font);
    }
    else
    {
        std::cout << "Font failed to load!\n";
    }
}

void FrameRate::Update(double deltaTime)
{
    frameCount++;

    elapsedTime += fpsClock.restart();
    if (elapsedTime.asSeconds() >= 1.0f) {
        float fps = frameCount / elapsedTime.asSeconds();
        std::string fpsCounter;
        fpsCounter = "FPS: " + std::to_string(static_cast<int>(std::round(fps))) + "  FrameTime: " + std::to_string(static_cast<int>(std::round(deltaTime)));
        frameRateText.setString(fpsCounter);

        frameCount = 0;
        elapsedTime = sf::Time::Zero;
    }
}

void FrameRate::Draw(sf::RenderWindow& window)
{
    window.draw(frameRateText);
}
