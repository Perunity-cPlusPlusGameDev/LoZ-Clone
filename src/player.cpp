#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

#include "player.h"
#include "game.h"

void Player::Run()
{
	int i = 50;
	int direction = 1;

	if(!tileTexture.loadFromFile("Textures/player.png"))
		std::cout << "Texture file cannot be found!" << std::endl;
	tile.setTexture(tileTexture);
	std::cout << "Texture Loaded!" << std::endl;
}

void Player::Render()
{

}

void Player::Update()
{

}

void Player::LoadPlayer()
{

}

void Player::DrawPlayer(sf::RenderWindow& window)
{
	tile.setPosition(500,500);
	window.draw(tile);
}

void Player::ProcessInput()
{

}

void Player::CheckCollision()
{

}

void Player::Move()
{

}

void Player::GetPos()
{

}

