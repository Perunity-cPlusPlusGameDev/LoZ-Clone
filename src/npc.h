#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Entity.h"
class Npc : public Entity
{
public:
	void Init(sf::Vector2i screenDimensions, int initPosX, int initPosY, sf::Texture& _texture, sf::Vector2i mapSize, int entityType) override;
	void Update(sf::Time dt) override;
	void ProcessInput() override;
	void Draw(sf::RenderWindow& window) override;
	sf::Vector2f GetPos();
private:
	int random;
};