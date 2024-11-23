#include "Map.h"
#include <iostream>

Map::Map() :
    totalTilesX(0), totalTilesY(0), totalTiles(0), tiles(nullptr), mapSprites(nullptr)
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
    mapLoader.Load("Assets/Maps/level1.rmap", md);
    mapSprites = new sf::Sprite[md.dataLength];

    if (tileSheetTexture.loadFromFile(md.tilesheet))
    {
        std::cout << "World prison tilesheet loaded!\n";
        totalTilesX = tileSheetTexture.getSize().x / md.tileWidth;
        totalTilesY = tileSheetTexture.getSize().y / md.tileHeight;

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
                tiles[i].position = sf::Vector2i(x * md.tileWidth, y * md.tileHeight);
            }
        }
    }
    else
    {
        std::cout << "World prison tilesheet failed to load!\n";
    }

    for (int y = 0; y < md.mapHeight; y++)
    {
        for (int x = 0; x < md.mapWidth; x++)
        {
            int i = x + y * md.mapWidth;

            int index = md.data[i];

            mapSprites[i].setTexture(tileSheetTexture);

            mapSprites[i].setTextureRect(sf::IntRect(tiles[index].position.x, tiles[index].position.y, md.tileWidth, md.tileHeight));
            mapSprites[i].setScale(sf::Vector2f(md.scaleX, md.scaleY));
            mapSprites[i].setPosition(sf::Vector2f(x * md.tileWidth * md.scaleX, 100 + y * md.tileHeight * md.scaleY));
        }

    }
}

void Map::Update(double deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < md.dataLength; i++)
        window.draw(mapSprites[i]);
}
