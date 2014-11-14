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

	tile.setPosition(x,y);
	tile.setTextureRect(sf::IntRect(0, 0, TILE_SIZE, TILE_SIZE));
	window.draw(tile);
}

void Player::ProcessInput()
{

}

void Player::CheckCollision()
{
	std::cout << x << " " << y << std::endl;
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

void Player::SetPos(int posx, int posy, int speed){

	x += posx * speed;
	y += posy * speed;
	CheckCollision();
}

