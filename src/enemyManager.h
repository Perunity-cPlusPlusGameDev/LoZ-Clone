#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "enemy.h"
#include "gui.h"
class EnemyManager
{
public:
	void Init();
	void Draw(sf::RenderWindow& window);
	void Update(sf::Time dt);
	void CreateEnemy(int x, int y, sf::Texture& texture, sf::Vector2i mapSize);
	void ProcessInput();
private:
	std::vector<Enemy> enemyList;
	int random;
	sf::Time timeLimit = sf::seconds(1);
	sf::Time elapsedTime;
	sf::Clock timer;
	//Gui gui;
};