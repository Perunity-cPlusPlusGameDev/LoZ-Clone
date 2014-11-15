#include "player.h"

void Player::Init(sf::Vector2i screenDimensions)
{
	if(!spriteTexture.loadFromFile("Textures/image.png"))
		std::cout << "Player texture file cannot be found!" << std::endl;
	sprite.setTexture(spriteTexture);
	std::cout << "Player texture Loaded!" << std::endl;
	source = sf::Vector2i(1, DOWN);
	velocity = sf::Vector2f(0,0);
	sprite.setPosition(120,450);
	// Camera Init
	view.reset(sf::FloatRect(100, 100, 800, 600));
	view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
}

void Player::Draw(sf::RenderWindow& window)
{
	sprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
	frameCounter += frameSpeed * clock.restart().asSeconds();
		if (frameCounter >= switchFrame)
		{
			frameCounter = 0;
			if(velocity != sf::Vector2f(0,0))
				source.x++;
			if(source.x * 32 >= spriteTexture.getSize().x)
				source.x = 0;
		}
	sf::Vector2f pos = GetPos();
	CheckCameraBorder(pos.x,pos.y);
	view.setCenter(pos.x,pos.y);
	window.draw(sprite);
	window.setView(view);
}

void Player::ProcessInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		source.y = UP;
		velocity.y = -0.05f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		source.y = DOWN;
		velocity.y = 0.05f;
	}
	else
	{
		velocity.y = 0.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		source.y = LEFT;
		velocity.x = -0.05f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		source.y = RIGHT;
		velocity.x = 0.05f;
	}
	else
	{
		velocity.x = 0.0f;
	}
}

void Player::Update()
{
	sf::Vector2f pos = GetPos();
	CheckCollision(pos.x, pos.y);
	sprite.setPosition(pos.x, pos.y);
	sprite.move(velocity.x, velocity.y);
}

void Player::CheckCollision(float &x, float &y)
{
	if ( x < 0 )
	{
		x = 0;
	}
	if ( y <= 0 )
	{
		y = 0;
	}
	if ( x > ((mapx * TILE_SIZE) - TILE_SIZE))
	{
		x = ((mapx * TILE_SIZE) - TILE_SIZE);
	}
	if ( y > (mapy * TILE_SIZE) - TILE_SIZE )
	{
		y = (mapy * TILE_SIZE) - TILE_SIZE;
	}
}
void Player::CheckCameraBorder(float &x, float &y)
{

	if(x < 400 )
	{
		x = 400;
	}
	if(y < 300)
	{
		y = 300;
	}
	if(x > (mapx * TILE_SIZE - 400))
	{
		x = (mapx * TILE_SIZE - 400);
	}
	if(y > (mapy * TILE_SIZE - 300))
	{
		y = (mapy * TILE_SIZE - 300);
	}
}
sf::Vector2f Player::GetPos()
{
	return sprite.getPosition();
}

void Player::SetPos(int posx, int posy, int dir) //Should be for TP's and such
{

}

void Player::MapSize(sf::Vector2i pos) // Used for CheckCollision
{
	mapx = pos.x;
	mapy = pos.y;
}