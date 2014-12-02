#include "Entity.h"

void Entity::Init(sf::Vector2i screenDimensions, int initPosX, int initPosY, sf::Texture& _texture, sf::Vector2i mapSize, int _entityType)
{
	texture = _texture;
	entityType = _entityType;
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
	frameCounter += frameSpeed * clock.restart().asSeconds();
	switch (entityType) {
	case 1:
	default:
		sprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
		if (frameCounter >= switchFrame) {
			frameCounter = 0;
			if (velocity != sf::Vector2i(0, 0))
				source.x++;
			if (source.x * 32 >= texture.getSize().x)
				source.x = 0;
		}
		break;
	case 3:
		sprite.setTextureRect(sf::IntRect(source.x * 32, 0 * 32, 32, 32));
		if (frameCounter >= switchFrame/2) {
			frameCounter = 0;

			if (!rAnimation) {
				source.x++;
			} else {
				source.x--;
			}
			if (source.x * 32 >= 4 * 32) {
				rAnimation = true;
			} else if (source.x * 32 <= 1 * 32){
				rAnimation = false;
			}
			
		}
		break;
	}
	
	


	window.draw(sprite);
}

void Entity::ProcessInput()
{
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
	if(entityType == 1 || entityType == 3)
	{
		if( x < startPosition.x - npcWalkingDistance)
		{
			x = startPosition.x - npcWalkingDistance;
			velocity = sf::Vector2i(0, 0);
		}
		if( y < startPosition.y - npcWalkingDistance)
		{
			y = startPosition.y - npcWalkingDistance;
			velocity = sf::Vector2i(0, 0);
		}
		if( x > startPosition.x + npcWalkingDistance)
		{
			x = startPosition.x + npcWalkingDistance;
			velocity = sf::Vector2i(0, 0);
		}
		if( y > startPosition.y + npcWalkingDistance)
		{
			y = startPosition.y + npcWalkingDistance;
			velocity = sf::Vector2i(0, 0);
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
	}
}

sf::Vector2f Entity::GetPos()
{
	return sprite.getPosition();
}

void Entity::SetPos(int posx, int posy, int dir) //Should be for TP's and such
{

}
