#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Entity.h"
class Player: public Entity
{
public:
	void ProcessInput();
	void Draw(sf::RenderWindow& window);
	void Init(int entityType, sf::Vector2i screenDimensions, int initPosX, int initPosY, sf::Texture& texture, sf::Vector2i mapSize);
	void SetPos(int posx, int posy, int dir);
private:
	void CheckCameraBorder(float &x, float &y);

public:

private:
	sf::View view;
};
#endif