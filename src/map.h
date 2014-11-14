#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>


class Map
{
public:
	void Run();
	void LoadMap(const std::string& fileName);
	void DrawMap(sf::RenderWindow &window);
private:
	static const int TILE_SIZE = 32;
	std::vector<std::vector<sf::Vector2i>> map;
	sf::Sprite tile;
	sf::Texture tileTexture;
};



