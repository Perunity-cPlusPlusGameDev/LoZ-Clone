#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "game.h"


void Game::Run()
{	
	screenDimensions = sf::Vector2i(800, 600);
	window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Isometric Game");

	timePerFrame = sf::milliseconds(16);
	timer.restart();

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

}
void Game::ProcessEvents()
{

}
void Game::ProcessInput()
{

}