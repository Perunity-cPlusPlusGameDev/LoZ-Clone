#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

class Player
{
public:
	void Init(sf::Vector2i screenDimensions);
	void SetPos(int posx, int posy, int dir);
	sf::Vector2f GetPos();
	void Draw(sf::RenderWindow& window);
	void ProcessInput();
	void Update();
	void MapSize(sf::Vector2i pos);
private:
	static const int TILE_SIZE = 32;
	void Move(sf::Vector2i velocity);
	void CheckCollision(float &x, float &y);
	void CheckCameraBorder(float &x, float &y);
	sf::Sprite sprite;
	sf::Texture spriteTexture;
	sf::View view;
	enum DIRECTION
	{
	    DOWN = 0,
	    LEFT = 1,
	    RIGHT = 2,
	    UP = 3
	};
	sf::Vector2i source;
	sf::Vector2f velocity;
	sf::Clock clock;
	float frameCounter = 0, switchFrame = 100, frameSpeed = 500;
	int mapx;
	int mapy;

};
#endif