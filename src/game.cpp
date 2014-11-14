#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

#include "game.h"
//Nick's github test comment! :D yes
void Game::Run()
{
	screenDimensions = sf::Vector2i(800, 600);
	window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Zelda Clone");

	// Load Main Menu
	menu.loadMenu("Sound/intro.ogg", window, screenDimensions.x, screenDimensions.y);

	timePerFrame = sf::milliseconds(16);
	timer.restart();

	map.LoadMap("Maps/Map1.txt");

	player.Run();

	while (window.isOpen())
	{
		if (timePerFrame <= timer.getElapsedTime())
		{
			timer.restart();

			Update();
			Render();
		}
		//ProcessEvents();
		ProcessInput();
	}
}

void Game::Update()
{

}

void Game::Render()
{
	window.clear();
	map.DrawMap(window);
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
	sf::Event event;
	while(window.pollEvent(event))
	{
		int speed = 10;
		//What's the best way to implement this? -Bahbi
		if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
		{
			player.SetPos(0, -1, speed);
		}
		else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
		{
			player.SetPos(0, 1, speed);
		}
		else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
		{
			player.SetPos(-1, 0, speed);
		}
		else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
		{
			player.SetPos(1, 0, speed);
		}
		if(event.type == sf::Event::Closed)
		{
			window.close();
		}
	}

}

