#pragma once
#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>


class Map
{
public:
	void Run();
	void LoadMap(const std::string fileName, sf::Texture &tileTexture);
	void Draw(sf::RenderWindow &window);
	void PrintTileSheet(sf::RenderWindow &window);
	int GetCurrentMap();
	void SetCurrentMap(int i);
	sf::Vector2i GetMapSize();
private:
	static const int TILE_SIZE = 32;
	std::vector<std::vector<sf::Vector2i>> map;
	sf::Sprite tile;
	sf::Texture tileTexture;
	int numCurrentMap;
};
#endif