#include "npcManager.h"

void NpcManager::Init()
{
}

void NpcManager::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < npcList.size(); i++)
	{
		npcList[i].Draw(window);
	}
}

void NpcManager::Update()
{
	for (int i = 0; i < npcList.size(); i++)
	{
		npcList[i].Update();
	}
}

void NpcManager::CreateNPC()
{
	Npc npc;
	npc.Init(sf::Vector2i(800, 600), 120, 420, "npc1");
	npcList.push_back(npc);
}