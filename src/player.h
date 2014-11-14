#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

#include "animatedsprite.h"

class Player
{
public:
	void Run(sf::Vector2i screenDimensions);
	void SetPos(int posx, int posy, int speed, int dir);
	void GetPos(int &posX, int &posY);

	void DrawPlayer(sf::RenderWindow& window);
private:
	static const int TILE_SIZE = 32;
	void Render();
	void Update();
	void LoadPlayer();
	void ProcessInput();
	void Move();
	void CheckCollision(float &x, float &y);
	sf::Sprite tile;
	sf::Texture tileTexture;
	int x;
	int y;
	int direction;

	Animation walkingAnimationDown;
	Animation walkingAnimationLeft;
	Animation walkingAnimationRight;
	Animation walkingAnimationUp;
	Animation* currentAnimation = &walkingAnimationDown;
	AnimatedSprite animatedsprite;
	sf::Clock frameClock;
	sf::Time frameTime;

	float speed;
    bool noKeyWasPressed;

};
#endif