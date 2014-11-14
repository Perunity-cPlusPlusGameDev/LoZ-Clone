#include "player.h"

void Player::Run()
{
	int i = 50;
	int direction = 1;

	if(!tileTexture.loadFromFile("Textures/panda.png"))
		std::cout << "Texture file cannot be found!" << std::endl;
	tile.setTexture(tileTexture);
	// default position
	x = 500;
	y = 500;
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


	if ( direction == 0 )
	{
		tile.setTextureRect(sf::IntRect(0 * TILE_SIZE, 2 * TILE_SIZE, TILE_SIZE, TILE_SIZE));
	}
	else if ( direction == 1 )
	{
		tile.setTextureRect(sf::IntRect(0 * TILE_SIZE, 0 * TILE_SIZE, TILE_SIZE, TILE_SIZE));
	}
	else if (direction == 2 )
	{
		tile.setTextureRect(sf::IntRect(5 * TILE_SIZE, 3 * TILE_SIZE, -TILE_SIZE, TILE_SIZE));
	}
	else if ( direction == 3 )
	{
		tile.setTextureRect(sf::IntRect(0 * TILE_SIZE, 3 * TILE_SIZE, TILE_SIZE, TILE_SIZE));
	}
	else
	{
		// Just in case some shit happens
		tile.setTextureRect(sf::IntRect(0 * TILE_SIZE, 0 * TILE_SIZE, TILE_SIZE, TILE_SIZE));
	}
	tile.setPosition(x,y);
	window.draw(tile);
}

void Player::ProcessInput()
{

}

void Player::CheckCollision()
{
	if ( x < 0 )
	{
		x = 0;
	}
	if ( y <= 0 )
	{
		y = 0;
	}
	if ( x > 800 - TILE_SIZE )
	{
		x = 800 - TILE_SIZE;
	}
	if ( y > 600 - TILE_SIZE )
	{
		y = 600 - TILE_SIZE;
	}
}

void Player::Move()
{

}

void Player::GetPos(int &posX, int &posY)
{
	posX = x;
	posY = y;
}

void Player::SetPos(int posx, int posy, int speed, int dir)
{
	direction = dir;
	x += posx * speed;
	y += posy * speed;
	CheckCollision();
}

