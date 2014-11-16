#include "npc.h"

void Npc::Init(sf::Vector2i screenDimensions, int initPosX, int initPosY, sf::Texture& spriteTexture)
{
	sprite.setTexture(spriteTexture);
	std::cout << "Npc texture Loaded!" << std::endl;
	source = sf::Vector2i(1, DOWN);
	velocity = sf::Vector2i(0,0);
	sprite.setPosition(initPosX,initPosY);
}

void Npc::Draw(sf::RenderWindow& window)
{
	sprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
	frameCounter += frameSpeed * clock.restart().asSeconds();
		if (frameCounter >= switchFrame)
		{
			frameCounter = 0;
			if(velocity != sf::Vector2i(0,0))
				source.x++;
			if(source.x * 32 >= spriteTexture.getSize().x)
				source.x = 0;
		}
	window.draw(sprite);
}

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

void Npc::Update(sf::Time dt)
{
	sprite.move(velocity.x * dt.asSeconds() ,velocity.y * dt.asSeconds());
	sf::Vector2f pos = GetPos();
	CheckCollision(pos.x, pos.y);
	sprite.setPosition(pos.x, pos.y);
}

void Npc::CheckCollision(float &x, float &y)
{

}

sf::Vector2f Npc::GetPos()
{
	return sprite.getPosition();
}

void Npc::SetPos(int posx, int posy, int dir) //Should be for TP's and such
{

}

void Npc::MapSize(sf::Vector2i pos) // Used for CheckCollision
{
	mapx = pos.x;
	mapy = pos.y;
}