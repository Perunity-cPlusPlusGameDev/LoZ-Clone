#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "game.h"


void Game::Run()
{
	screenDimensions = sf::Vector2i(800, 600);
	window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Zelda Clone");

	timePerFrame = sf::milliseconds(16);
	timer.restart();

	//LoadMap();

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
			std::cout << "An event has fired which hasn't been added to the process list" << std::endl;
			break;
		}
	}
}

void Game::ProcessInput()
{

}

void Game::LoadMap(const std::string& fileName)
{

}

void Game::DrawMap()
{

}