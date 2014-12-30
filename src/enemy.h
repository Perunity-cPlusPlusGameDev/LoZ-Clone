#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Entity.h"
class Enemy : public Entity
{
public:
	void ProcessInput();
	void Init(sf::Vector2i screenDimensions, int initPosX, int initPosY, sf::Texture& _texture, sf::Vector2i mapSize, int entityType);
	void Update(sf::Time dt);
	int i;
private:
	int Random;

};