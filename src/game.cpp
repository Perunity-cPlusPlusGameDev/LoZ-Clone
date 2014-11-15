#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

#include "game.h"

void Game::Run()
{
	/*Initialize*/
	State = MAINMENU;
	screenDimensions = sf::Vector2i(800, 600);
	window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Zelda Clone");
	map.LoadMap("Maps/Map1.txt"); // Improve the way we handle maps
	map1.LoadMap("Maps/Map1.1.txt");
	map2.LoadMap("Maps/Map1.2.txt");
	player.Init(screenDimensions);
	clock.restart();
	/*End Of Initialize*/

	// Load Main Menu
	menu.LoadMenu("Sound/intro.ogg", window, screenDimensions.x, screenDimensions.y);

	//Main Loop
	while (window.isOpen())
	{
		if( State == PLAYING )
		{
			clock.restart();
			Update();
			Draw();
		}
		ProcessEvents();
		ProcessInput();
	}
}



void Game::Update()
{
	player.Update();
}

void Game::Draw()
{
	window.clear();

	map.Draw(window);
	player.Draw(window);
	map1.Draw(window);
	map2.Draw(window);

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
	player.ProcessInput();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && (State != PLAYING))
	{
		State = PLAYING;
		std::cout << "State: Playing" << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && (State != PLAYING))
	{
		window.close();
	}

}

