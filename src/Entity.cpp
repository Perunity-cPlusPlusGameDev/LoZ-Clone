#include "Entity.h"

void Entity::Init(sf::Vector2i screenDimensions, int initPosX, int initPosY, sf::Texture& _texture, sf::Vector2i mapSize, bool _isNPC)
{
	texture = _texture;
	isNPC = _isNPC;
	sprite.setTexture(_texture);
	source = sf::Vector2i(1, DOWN);
	velocity = sf::Vector2i(0,0);
	sprite.setPosition(initPosX,initPosY);
	map = mapSize;
	startPosition.x = initPosX;
	startPosition.y = initPosY;
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
			if(source.x * 32 >= texture.getSize().x)
				source.x = 0;
		}
	window.draw(sprite);
}

void Entity::Update(sf::Time dt, int &currentMap)
{
	sprite.move(velocity.x * dt.asSeconds() ,velocity.y * dt.asSeconds());
	sf::Vector2f pos = GetPos();
	CheckCollision(pos.x, pos.y, currentMap);
	sprite.setPosition(pos.x, pos.y);
}

void Entity::CheckCollision(float &x, float &y, int &currentMap)
{
	if(isNPC)
	{
		if( x < startPosition.x - npcWalkingDistance)
		{
			x = startPosition.x - npcWalkingDistance;
		}
		if( y < startPosition.y - npcWalkingDistance)
		{
			y = startPosition.y - npcWalkingDistance;
		}
		if( x > startPosition.x + npcWalkingDistance)
		{
			x = startPosition.x + npcWalkingDistance;
		}
		if( y > startPosition.y + npcWalkingDistance)
		{
			y = startPosition.y + npcWalkingDistance;
		}
	}
	else
	{
		if ( x < 0 )
		{
			x = 0;
		}
		if ( y < 0 )
		{
			y = 0;
		}
		if ( x > ((map.x * TILE_SIZE) - TILE_SIZE))
		{
			x = ((map.x * TILE_SIZE) - TILE_SIZE);
		}
		if ( y > (map.y * TILE_SIZE) - TILE_SIZE )
		{
			y = (map.y * TILE_SIZE) - TILE_SIZE;
		}
		// TELEPERRRTT
		if ( (x > 0 && x <= 30) && (y <= 30 && y > 0))
		{
			currentMap = (currentMap ? 0 : 1);
			y += 30;
		}
	}
}

sf::Vector2f Entity::GetPos()
{
	return sprite.getPosition();
}

void Entity::SetPos(int posx, int posy, int dir) //Should be for TP's and such
{

}
