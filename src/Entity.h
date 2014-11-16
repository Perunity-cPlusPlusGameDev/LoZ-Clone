#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Entity
{
public:
	void Init(sf::Vector2i screenDimensions, int initPosX, int initPosY, sf::Texture& texture);
	void SetPos(int posx, int posy, int dir);
	sf::Vector2f GetPos();
	void Draw(sf::RenderWindow& window);
	void Update(sf::Time dt);
	void MapSize(sf::Vector2i pos);

protected:

	void Move(sf::Vector2i velocity);
	void CheckCollision(float &x, float &y);

public:

protected:
	static const int TILE_SIZE = 32;
	sf::Sprite sprite;
	sf::Texture texture;
	enum DIRECTION
	{
	    DOWN = 0,
	    LEFT = 1,
	    RIGHT = 2,
	    UP = 3
	};
	sf::Vector2i source;
	sf::Vector2i velocity;
	sf::Clock clock;
	float frameCounter = 0, switchFrame = 100, frameSpeed = 500;
	int mapx;
	int mapy;

};
