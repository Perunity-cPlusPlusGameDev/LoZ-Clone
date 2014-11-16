#pragma once

#include <SFML/Graphics.hpp>
#include "npc.h"

class NpcManager
{
public:
	void Init();
	void Draw(sf::RenderWindow& window);
	void Update();
	void CreateNPC();
private:
	std::vector<Npc> npcList;
	sf::RenderWindow window;
};