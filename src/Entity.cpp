#include "Entity.h"

void Entity::Init(sf::Vector2i screenDimensions, int initPosX, int initPosY, sf::Texture& texture)
{
	sprite.setTexture(texture);
	source = sf::Vector2i(1, DOWN);
	velocity = sf::Vector2i(0,0);
	sprite.setPosition(initPosX,initPosY);
}

void Entity::Draw(sf::RenderWindow& window)
{
	sprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
	frameCounter += frameSpeed * clock.restart().asSeconds();

		if (frameCounter >= switchFrame)
		{
			frameCounter = 0;
			if(velocity != sf::Vector2i(0,0))
				source.x++;
			if(source.x * 32 >= 96) //texture.getSize().x is empty for some reason
				source.x = 0;
		}

	sf::Vector2f pos = GetPos();
	window.draw(sprite);
}

void Entity::Update(sf::Time dt)
{
	sprite.move(velocity.x * dt.asSeconds() ,velocity.y * dt.asSeconds());
	sf::Vector2f pos = GetPos();
	CheckCollision(pos.x, pos.y);
	sprite.setPosition(pos.x, pos.y);
}

void Entity::CheckCollision(float &x, float &y)
{
	if ( x < 0 )
	{
		x = 0;
	}
	if ( y <= 0 )
	{
		y = 0;
	}
	/*
	if ( x > ((mapx * TILE_SIZE) - TILE_SIZE))
	{
		x = ((mapx * TILE_SIZE) - TILE_SIZE);
	}
	if ( y > (mapy * TILE_SIZE) - TILE_SIZE )
	{
		y = (mapy * TILE_SIZE) - TILE_SIZE;
	}
	something here isnt working well
	*/
}

sf::Vector2f Entity::GetPos()
{
	return sprite.getPosition();
}

void Entity::SetPos(int posx, int posy, int dir) //Should be for TP's and such
{

}

void Entity::MapSize(sf::Vector2i pos) // Used for CheckCollision
{
	mapx = pos.x;
	mapy = pos.y;
}