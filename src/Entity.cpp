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
	//std::cout << "Starting Position X:" << startPosition.x << " Y:" << startPosition.y << std::endl;
}

void Entity::Draw(sf::RenderWindow& window)
{
//	std::cout << "Cur Position X:" << sprite.getPosition().x << " Y:" << sprite.getPosition().y << std::endl;
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

void Entity::Update(sf::Time dt)
{
	sprite.move(velocity.x * dt.asSeconds() ,velocity.y * dt.asSeconds());
	sf::Vector2f pos = GetPos();
	CheckCollision(pos.x, pos.y);
	sprite.setPosition(pos.x, pos.y);
}

void Entity::CheckCollision(float &x, float &y)
{
	/*if(isNPC)
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
	{*/
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
	//}
}

sf::Vector2f Entity::GetPos()
{
	return sprite.getPosition();
}

void Entity::SetPos(int posx, int posy, int dir) //Should be for TP's and such
{

}

//void Entity::MapSize(sf::Vector2i pos) // Used for CheckCollision
//{
//	map.x = pos.x;
//	map.y = pos.y;
//}