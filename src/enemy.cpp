#include "enemy.h"

void Enemy::Init(sf::Vector2i screenDimensions, int initPosX, int initPosY, sf::Texture& _texture, sf::Vector2i mapSize)
{
	Entity::Init(screenDimensions, initPosX, initPosY, _texture, mapSize, false);

}

void Enemy::ProcessInput()
{
	switch(i)
	{
		case 0:
			source.y = UP;
			velocity.y = -50;
			break;
		case 1:
			source.y = DOWN;
			velocity.y = 50;
			break;
		case 2:
			source.y = LEFT;
			velocity.x = -50;
			break;
		case 3:
			source.y = RIGHT;
			velocity.x = 50;
			break;

	}

}
void Enemy::Update(sf::Time dt)
{
	int dummy;
	Entity::Update(dt, dummy);
}