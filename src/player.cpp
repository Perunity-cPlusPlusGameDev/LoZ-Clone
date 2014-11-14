#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

#include "player.h"

void Player::Run()
{
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

void Player::DrawPlayer()
{
	tile.setPosition(2,2);
	window.draw(tile);
	std::cout << "Player Drawn!" << std::endl;
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

