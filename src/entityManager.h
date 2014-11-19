#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "gui.h"
#include "entity.h"
#include "npc.h"
#include <memory>
#include <iostream>

class EntityManager
{
public:
	void Init();
	void Draw(sf::RenderWindow& window);
	void Update(sf::Time dt);
	void CreateEntity(int entityType, int x, int y, sf::Texture& texture, sf::Vector2i mapSize);
	void ProcessInput();
private:
	std::vector<std::unique_ptr<Entity>> entityList;
	sf::Time timeLimit = sf::seconds(1);
	sf::Time elapsedTime;
	sf::Clock timer;
	Gui gui;
};