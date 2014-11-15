#include "player.h"

void Player::Init(sf::Vector2i screenDimensions)
{
	if(!spriteTexture.loadFromFile("Textures/image.png"))
		std::cout << "Player texture file cannot be found!" << std::endl;
	sprite.setTexture(spriteTexture);
	std::cout << "Player texture Loaded!" << std::endl;
	source = sf::Vector2i(1, DOWN);
	velocity = sf::Vector2f(0,0);
	sprite.setPosition(100,100);
}

void Player::Draw(sf::RenderWindow& window)
{
	sprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
	frameCounter += frameSpeed * clock.restart().asSeconds();
		if (frameCounter >= switchFrame)
		{
			frameCounter = 0;
			source.x++;
			if(source.x * 32 >= spriteTexture.getSize().x)
				source.x = 0;
		}
	window.draw(sprite);
}

void Player::ProcessInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		source.y = UP;
		velocity.y = -0.1f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		source.y = DOWN;
		velocity.y = 0.1f;
	}
	else
	{
		velocity.y = 0.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		source.y = LEFT;
		velocity.x = -0.1f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		source.y = RIGHT;
		velocity.x = 0.1f;
	}
	else
	{
		velocity.x = 0.0f;
	}
}

void Player::Update()
{
	sprite.move(velocity.x, velocity.y);
}

void Player::CheckCollision(float &x, float &y)
{
	/*
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
	*/
}

sf::Vector2i Player::GetPos()
{
	//return
}

void Player::SetPos(int posx, int posy, int dir) //Should be for TP's and such
{

}

