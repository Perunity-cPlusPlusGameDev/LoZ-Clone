#include "player.h"


void Player::Init(sf::Vector2i screenDimensions, int initPosX, int initPosY, sf::Texture& texture, sf::Vector2i mapSize)
{
	Entity::Init(screenDimensions, initPosX, initPosY, texture, mapSize, false);
	// Camera Init
	view.reset(sf::FloatRect(100, 100, 800, 600));
	view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
}

void Player::Draw(sf::RenderWindow& window)
{
	sf::Vector2f pos = GetPos();
	CheckCameraBorder(pos.x,pos.y);
	view.setCenter(pos.x,pos.y);
	window.setView(view);
	Entity::Draw(window);
}


void Player::ProcessInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		source.y = UP;
		velocity.y = -100;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		source.y = DOWN;
		velocity.y = 100;
	}
	else
	{
		velocity.y = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		source.y = LEFT;
		velocity.x = -100;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		source.y = RIGHT;
		velocity.x = 100;
	}
	else
	{
		velocity.x = 0;
	}
}

void Player::CheckCameraBorder(float &x, float &y)
{

	if(x < 400 )
	{
		x = 400;
	}
	if(y < 300)
	{
		y = 300;
	}
	if(x > (map.x * TILE_SIZE - 400))
	{
		x = (map.x * TILE_SIZE - 400);
	}
	if(y > (map.y * TILE_SIZE - 300))
	{
		y = (map.y * TILE_SIZE - 300);
	}
}

