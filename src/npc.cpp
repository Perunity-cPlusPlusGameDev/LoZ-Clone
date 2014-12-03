#include "npc.h"

void Npc::Init(sf::Vector2i screenDimensions, int initPosX, int initPosY, sf::Texture& _texture, sf::Vector2i mapSize, int entityType)
{
	Entity::Init(screenDimensions, initPosX, initPosY, _texture, mapSize, entityType);
}

void Npc::ProcessInput() {
	srand(time(NULL));
	random = std::rand() % 4;
	switch (random) {
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
	default:
		break;
	}
}