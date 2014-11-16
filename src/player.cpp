#include "player.h"

/*
void Player::Init()
{
	// Camera Init
	view.reset(sf::FloatRect(100, 100, 800, 600));
	view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
}

void Player::Draw(sf::RenderWindow& window)
{
	CheckCameraBorder(pos.x,pos.y);
	view.setCenter(pos.x,pos.y);
	window.setView(view);
}
*/

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
	if(x > (mapx * TILE_SIZE - 400))
	{
		x = (mapx * TILE_SIZE - 400);
	}
	if(y > (mapy * TILE_SIZE - 300))
	{
		y = (mapy * TILE_SIZE - 300);
	}
}

