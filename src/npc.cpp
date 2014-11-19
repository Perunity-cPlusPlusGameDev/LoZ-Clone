#include "npc.h"

void Npc::Init(sf::Vector2i screenDimensions, int initPosX, int initPosY, sf::Texture& _texture, sf::Vector2i mapSize, int entityType)
{
	Entity::Init(screenDimensions, initPosX, initPosY, _texture, mapSize, entityType);
}

void Npc::Draw(sf::RenderWindow& window)
{
	Entity::Draw(window);
}

void Npc::ProcessInput()
{
	//std::cout << "NPC PROCESS INPUT" << std::endl;
	srand(time(NULL));
	random = std::rand() % 4;
	std::cout << random << std::endl;
	switch(random)
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
		default:
		break;
	}
}

void Npc::Update(sf::Time dt)
{
	Entity::Update(dt);
}

sf::Vector2f Npc::GetPos()
{
	return Entity::GetPos();
}
