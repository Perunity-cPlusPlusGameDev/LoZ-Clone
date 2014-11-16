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

void NpcManager::Update(sf::Time dt)
{
	for (int i = 0; i < npcList.size(); i++)
	{
		npcList[i].Update(dt);
	}
}

void NpcManager::CreateNPC(int x, int y, sf::Texture& texture)
{
	Npc npc;
	npc.Init(sf::Vector2i(800, 600), x, y, texture);
	npcList.push_back(npc);
}
void NpcManager::ProcessInput()
{
	for (int i = 0; i < npcList.size(); i++)
	{
		npcList[i].ProcessInput();
}
}