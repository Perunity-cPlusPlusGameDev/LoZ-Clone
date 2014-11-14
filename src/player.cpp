#include "player.h"

void Player::Run(sf::Vector2i screenDimensions)
{
	int i = 50;
	int direction = 1;

	if(!tileTexture.loadFromFile("Textures/image.png"))
		std::cout << "Texture file cannot be found!" << std::endl;
	tile.setTexture(tileTexture);
	// default position
	std::cout << "Texture Loaded!" << std::endl;


	 // set up the animations for all four directions (set spritesheet and push frames)

    walkingAnimationDown.setSpriteSheet(tileTexture);
    walkingAnimationDown.addFrame(sf::IntRect( 0 * TILE_SIZE, 0 * TILE_SIZE, TILE_SIZE, TILE_SIZE));
    walkingAnimationDown.addFrame(sf::IntRect( 1 * TILE_SIZE, 0 * TILE_SIZE, TILE_SIZE, TILE_SIZE));
    walkingAnimationDown.addFrame(sf::IntRect( 2 * TILE_SIZE, 0 * TILE_SIZE, TILE_SIZE, TILE_SIZE));


    walkingAnimationLeft.setSpriteSheet(tileTexture);
    walkingAnimationLeft.addFrame(sf::IntRect( 0 * TILE_SIZE, 1 * TILE_SIZE, TILE_SIZE, TILE_SIZE));
    walkingAnimationLeft.addFrame(sf::IntRect( 1 * TILE_SIZE, 1 * TILE_SIZE, TILE_SIZE, TILE_SIZE));
    walkingAnimationLeft.addFrame(sf::IntRect( 2 * TILE_SIZE, 1 * TILE_SIZE, TILE_SIZE, TILE_SIZE));


    walkingAnimationRight.setSpriteSheet(tileTexture);
    walkingAnimationRight.addFrame(sf::IntRect( 0 * TILE_SIZE, 2 * TILE_SIZE, TILE_SIZE, TILE_SIZE));
    walkingAnimationRight.addFrame(sf::IntRect( 1 * TILE_SIZE, 2 * TILE_SIZE, TILE_SIZE, TILE_SIZE));
    walkingAnimationRight.addFrame(sf::IntRect( 2 * TILE_SIZE, 2 * TILE_SIZE, TILE_SIZE, TILE_SIZE));


    walkingAnimationUp.setSpriteSheet(tileTexture);
    walkingAnimationUp.addFrame(sf::IntRect( 0 * TILE_SIZE, 3 * TILE_SIZE, TILE_SIZE, TILE_SIZE));
    walkingAnimationUp.addFrame(sf::IntRect( 1 * TILE_SIZE, 3 * TILE_SIZE, TILE_SIZE, TILE_SIZE));
    walkingAnimationUp.addFrame(sf::IntRect( 2 * TILE_SIZE, 3 * TILE_SIZE, TILE_SIZE, TILE_SIZE));



    // set up AnimatedSprite
    AnimatedSprite animatedsprite(sf::seconds(0.2), true, false);

    speed = 80.f;
    noKeyWasPressed = true;
}

void Player::Render()
{

}

void Player::Update()
{

}

void Player::LoadPlayer()
{

}

void Player::DrawPlayer(sf::RenderWindow& window)
{
    frameTime = frameClock.restart();
    sf::Vector2f movement(0.f, 0.f);
	if ( direction == 0 )
	{
		currentAnimation = &walkingAnimationUp;
        movement.y -= speed;
        noKeyWasPressed = false;
	}
	else if ( direction == 1 )
	{
		currentAnimation = &walkingAnimationDown;
        movement.y += speed;
        noKeyWasPressed = false;
	}
	else if (direction == 2 )
	{
		currentAnimation = &walkingAnimationLeft;
        movement.x -= speed;
        noKeyWasPressed = false;
	}
	else if ( direction == 3 )
	{
		currentAnimation = &walkingAnimationRight;
        movement.x += speed;
        noKeyWasPressed = false;
	}
	// Get player current position and check collision
	sf::Vector2f position = animatedsprite.getPosition();
	CheckCollision(position.x, position.y);
	animatedsprite.setPosition(position);

	animatedsprite.play(*currentAnimation);
    animatedsprite.move(movement * frameTime.asSeconds());

	if (noKeyWasPressed)
    {
        animatedsprite.stop();
    }
 	noKeyWasPressed = true;
	animatedsprite.update(frameTime);
	window.draw(animatedsprite);
}

void Player::ProcessInput()
{

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
	if ( x > 800 - TILE_SIZE )
	{
		x = 800 - TILE_SIZE;
	}
	if ( y > 600 - TILE_SIZE )
	{
		y = 600 - TILE_SIZE;
	}
}

void Player::Move()
{

}

void Player::GetPos(int &posX, int &posY)
{
	posX = x;
	posY = y;
}

void Player::SetPos(int posx, int posy, int speed, int dir)
{
	direction = dir;

	// doesn't work with animation
	//x += posx * speed;
	//y += posy * speed;
	//CheckCollision();
}

