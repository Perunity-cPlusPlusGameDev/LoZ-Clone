#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "npc.h"

class NpcManager
{
public:
	void Init();
	void Draw(sf::RenderWindow& window);
	void Update(sf::Time dt);
	void CreateNPC(int x, int y, sf::Texture& texture, sf::Vector2i mapSize, bool isNPC);
	void ProcessInput();
private:
	std::vector<Npc> npcList;
	int random;
	sf::Time timeLimit = sf::seconds(1);
	sf::Time elapsedTime;
	sf::Clock timer;
};