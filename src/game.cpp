#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

#include "game.h"

//Nick's github test comment! :D yes
void Game::Run()
{
	State = MAINMENU;
	screenDimensions = sf::Vector2i(800, 600);
	window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Zelda Clone");

	// Load First Map
	map.LoadMap("Maps/Map1.txt");
	player.Run(screenDimensions);

	speed = 10;

	timePerFrame = sf::milliseconds(16);
	timer.restart();

	// Load Main Menu
	menu.LoadMenu("Sound/intro.ogg", window, screenDimensions.x, screenDimensions.y);
	while (window.isOpen())
	{
		if( State == PLAYING )
		{
			if (timePerFrame <= timer.getElapsedTime())
			{
				timer.restart();

				Update();
				Render();
			}
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
		//What's the best way to implement this? -Bahbi
		if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
		{
			player.SetPos(0, -1, speed, UP);
		}
		else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
		{
			player.SetPos(0, 1, speed, DOWN);
		}
		else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
		{
			player.SetPos(-1, 0, speed, LEFT);
		}
		else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
		{
			player.SetPos(1, 0, speed, RIGHT);
		}
		else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
		{
			State = PLAYING;
		}
		if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X))
		{
			window.close();
		}
	}
}

