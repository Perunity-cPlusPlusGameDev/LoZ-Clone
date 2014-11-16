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
	void CreateNPC();
private:
	Npc npc;
	std::vector<Npc> npcList;
};