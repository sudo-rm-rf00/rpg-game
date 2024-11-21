#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{
private:
	sf::Texture texture;
public:
	sf::Sprite sprite;
public:
	void Initialize(); // <- called once per App start
	void Load(); // <- called once per App start
	void Update(); // <- Once per frame
	void Draw(sf::RenderWindow& window); // <- Once per frame
};