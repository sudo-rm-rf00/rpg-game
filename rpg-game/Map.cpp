#include "Map.h"
#include <iostream>

Map::Map() :
    tileWidth(16), tileHeight(16), totalTilesX(0), totalTilesY(0), totalTiles(0)
{
}

Map::~Map()
{
}

void Map::Initialize()
{
}

void Map::Load()
{
    if (tileSheetTexture.loadFromFile("../Assets/World/Prison/tilesheet.png"))
    {
        std::cout << "World prison tilesheet loaded!\n";
        totalTilesX = tileSheetTexture.getSize().x / tileWidth;
        totalTilesY = tileSheetTexture.getSize().y / tileHeight;

        totalTiles = totalTilesX * totalTilesY;

        tiles = new Tile[totalTiles];

        for (size_t y = 0; y < totalTilesY; y++)
        {
            for (size_t x = 0; x < totalTilesX; x++)
            {
                int i = x + y * totalTilesX;
                if (i >= totalTiles)
                {
                    std::cerr << "Index out of range: " << i << " >= " << totalTiles << "\n";
                    continue;
                }
                tiles[i].id = i;
                tiles[i].position = sf::Vector2i(x * tileWidth, y * tileHeight);
            }
        }
    }
    else
    {
        std::cout << "World prison tilesheet failed to load!\n";
    }

    for (int y = 0; y < 2; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            int i = x + y * 3;

            int index = mapNumbers[i];

            mapSprites[i].setTexture(tileSheetTexture);

            mapSprites[i].setTextureRect(sf::IntRect(tiles[index].position.x, tiles[index].position.y, tileWidth, tileHeight));
            mapSprites[i].setScale(sf::Vector2f(5, 5));
            mapSprites[i].setPosition(sf::Vector2f(x * 16 * 5, 100 + y * 16 * 5));
        }

    }
}

void Map::Update(double deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < 6; i++)
        window.draw(mapSprites[i]);
}
