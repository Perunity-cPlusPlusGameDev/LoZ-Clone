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
	virtual void ProcessInput();
	virtual void Init(sf::Vector2i screenDimensions, int initPosX, int initPosY, sf::Texture& texture, sf::Vector2i mapSize, int _entityType);
	virtual void SetPos(int posx, int posy, int dir);
	virtual sf::Vector2f GetPos();
	virtual void Draw(sf::RenderWindow& window);
	virtual void Update(sf::Time dt);


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
	sf::Vector2i map;
	sf::Vector2i startPosition;
	int npcWalkingDistance = 50;
	int entityType;
	bool rAnimation = false;
};
