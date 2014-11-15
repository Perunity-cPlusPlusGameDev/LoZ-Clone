#include "map.h"

void Map::Run()
{

}
void Map::LoadMap(const std::string& fileName)
{
	if(!tileTexture.loadFromFile("Textures/RPGpack_sheet.png")){
		std::cout << "Map texture file cannot be found!" << std::endl;
	}
	tile.setTexture(tileTexture);

	std::cout << "Loading Map...." << std::endl;
	std::fstream openFile(fileName);
	std::vector<sf::Vector2i> tempMap;
	tempMap.clear();
	map.clear();

	if (openFile.is_open())
	{
		while (!openFile.eof())
		{
			std::string line, value;
			std::getline(openFile, line);
			std::stringstream stream(line);
			while (std::getline(stream, value, ' '))
			{
				/*if (value.length() == 2)
				{
					int x = atoi(value.substr(0, 1).c_str());
					int y = atoi(value.substr(1, 2).c_str());

					tempMap.push_back(sf::Vector2i(x, y));
				}
				else*/
				if (value.length() == 4)
				{
					int x = atoi(value.substr(0, 2).c_str());
					int y = atoi(value.substr(2, 4).c_str());

					tempMap.push_back(sf::Vector2i(x, y));
				}
			}

			if (tempMap.size() > 0)
			{
				map.push_back(tempMap);
				tempMap.clear();
			}
		}
	}
	std::cout << "Map Loaded!" << std::endl;
}

void Map::Draw(sf::RenderWindow &window)
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			tile.setPosition(j * TILE_SIZE, i * TILE_SIZE);
			tile.setTextureRect(sf::IntRect(map[i][j].x * TILE_SIZE, map[i][j].y * TILE_SIZE, TILE_SIZE, TILE_SIZE));
			window.draw(tile);
		}
	}
}
void Map::PrintTileSheet(sf::RenderWindow &window)
{
	if(!tileTexture.loadFromFile("Textures/RPGpack_sheet.png")){
		std::cout << "Texture file cannot be found!" << std::endl;
	}
	tile.setTexture(tileTexture);
	for (int i = 0; i < map.size(); i++)//y
	{
		for (int j = 0; j < map[0].size(); j++)//x
		{
			tile.setPosition(j * TILE_SIZE, i * TILE_SIZE);
			tile.setTextureRect(sf::IntRect(j* TILE_SIZE, i* TILE_SIZE, TILE_SIZE, TILE_SIZE));
			window.draw(tile);
		}
	}
}
sf::Vector2i Map::GetMapSize()
{
	return sf::Vector2i(map[0].size(),map.size());
}