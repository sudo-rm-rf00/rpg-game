#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton() :
    health(100)
{
}

Skeleton::~Skeleton()
{
}

void Skeleton::ChangeHealth(int hp)
{
    health += hp;
    healthText.setString(std::to_string(health));
}

void Skeleton::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Blue);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
}

void Skeleton::Load()
{
    if (font.loadFromFile("Assets/Fonts/arial.ttf"))
    {
        std::cout << "Font loaded!\n";
        healthText.setFont(font);
        healthText.setString(std::to_string(health));
    }
    else
    {
        std::cout << "Font failed to load!\n";
    }

    if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
    {
        std::cout << "Skeleton texture loaded!\n";
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(1600, 700));

        int XIndex = 0;
        int YIndex = 2;

        sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));

        sprite.scale(sf::Vector2f(3, 3));

        boundingRectangle.setSize(
            sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else
        std::cout << "Skeleton texture failed to load!\n";
}

void Skeleton::Update(double deltaTime)
{
    if (health > 0)
    {
        boundingRectangle.setPosition(sprite.getPosition());

        healthText.setPosition(sprite.getPosition());
    }
}

void Skeleton::Draw(sf::RenderWindow& window)
{
    if (health > 0)
    {
        window.draw(sprite);
        window.draw(boundingRectangle);
        window.draw(healthText);
    }
}