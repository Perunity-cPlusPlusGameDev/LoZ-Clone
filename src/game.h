#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"
#include "gameMenu.h"

class Game
{
public:
	void Run();
private:
	static const int TILE_SIZE = 32;
	void Update();
	void Render();
	void ProcessEvents();
	void ProcessInput();
	void LoadMap(const std::string& fileName);
	void DrawMap();
	std::vector<std::vector<sf::Vector2i>> map;
	sf::Sprite tile;
	sf::Texture tileTexture;
	sf::RenderWindow window;
	sf::Vector2i screenDimensions;
	sf::Clock timer;
	sf::Time timePerFrame;
	Player player;
	gameMenu menu;
};



