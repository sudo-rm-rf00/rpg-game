#pragma once
#include <SFML/Graphics.hpp>

class Map
{
private:
	sf::Texture tileSheetTexture;
	const static int spritesSize = 10;
	sf::Sprite sprites[spritesSize];

	int tileWidth;
	int tileHeight;

	int totalTilesX;
	int totalTilesY;

public:
	Map();
	~Map();

	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};