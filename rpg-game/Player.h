#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"

class Player
{
private:
	sf::Texture texture;

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed;
	float playerSpeed;

	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;
public:
	sf::Sprite sprite;

public:
	Player();
	~Player();

	void Initialize(); // <- called once per App start
	void Load(); // <- called once per App start
	void Update(float deltaTime, Skeleton& skeleton); // <- Once per frame
	void Draw(sf::RenderWindow& window); // <- Once per frame
};