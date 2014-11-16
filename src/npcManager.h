#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "npc.h"

class NpcManager
{
public:
	void Init();
	void Draw(sf::RenderWindow& window);
	void Update();
	void CreateNPC(int x, int y, sf::Texture texture);
private:
	std::vector<Npc> npcList;
};