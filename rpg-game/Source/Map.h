#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "MapLoader.h"
#include "MapData.h"

class Map
{
private:
	sf::Texture tileSheetTexture;
	Tile* tiles;

	MapLoader mapLoader;
	MapData md;

	int totalTiles;

	int totalTilesX;
	int totalTilesY;

	sf::Sprite* mapSprites;

public:
	Map();
	~Map();

	void Initialize();
	void Load();
	void Update(double deltaTime);
	void Draw(sf::RenderWindow& window);
};