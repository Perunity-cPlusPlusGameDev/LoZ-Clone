#include "npc.h"

void Npc::ProcessInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		source.y = UP;
		velocity.y = -100;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		source.y = DOWN;
		velocity.y = 100;
	}
	else
	{
		velocity.y = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		source.y = LEFT;
		velocity.x = -100;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		source.y = RIGHT;
		velocity.x = 100;
	}
	else
	{
		velocity.x = 0;
	}

}

