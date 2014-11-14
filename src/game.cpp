#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

#include "game.h"
#include "player.h"
//Nick's github test comment! :D yes
void Game::Run()
{
	screenDimensions = sf::Vector2i(800, 600);
	window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Zelda Clone");

	// Load Main Menu
	menu.loadMenu("Sound/intro.ogg", window, screenDimensions.x, screenDimensions.y);

	if(!tileTexture.loadFromFile("Textures/tiles.png"))
		std::cout << "Texture file cannot be found!" << std::endl;
	tile.setTexture(tileTexture);

	timePerFrame = sf::milliseconds(16);
	timer.restart();

	LoadMap("Maps/Map1.txt");

	player.Run();

	while (window.isOpen())
	{
		if (timePerFrame <= timer.getElapsedTime())
		{
			timer.restart();

			Update();
			Render();
		}
		ProcessEvents();
		ProcessInput();
	}
}

void Game::Update()
{

}

void Game::Render()
{
	window.clear();
	DrawMap();
	player.DrawPlayer(window);
	window.display();
}

void Game::ProcessEvents()
{
	sf::Event event;
	while(window.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
			window.close();
			break;

			default:
			//std::cout << "An event has fired which hasn't been added to the process list" << std::endl;
			break;
		}
	}
}

void Game::ProcessInput()
{

}

void Game::LoadMap(const std::string& fileName)
{
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
				if (value.length() == 2)
				{
					int x = atoi(value.substr(0, 1).c_str());
					int y = atoi(value.substr(1, 2).c_str());

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

void Game::DrawMap()
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			tile.setPosition(j * 32, i * 32);
			tile.setTextureRect(sf::IntRect(map[i][j].x * 32, map[i][j].y * 32, 32, 32));
			window.draw(tile);
		}
	}
}