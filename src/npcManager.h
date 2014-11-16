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
	void CreateNPC(int x, int y, sf::Texture& texture);
	void ProcessInput();
private:
	std::vector<Npc> npcList;
};