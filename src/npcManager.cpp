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

void NpcManager::CreateNPC(int x, int y, sf::Texture& texture, sf::Vector2i mapSize)
{
	Npc npc;
	npc.Init(sf::Vector2i(800, 600), x, y, texture, mapSize);
	npcList.push_back(npc);
}
void NpcManager::ProcessInput()
{
	elapsedTime = timer.getElapsedTime();
	if(elapsedTime > timeLimit)
	{
		for (int i = 0; i < npcList.size(); i++)
		{
			npcList[i].i = std::rand() % 4;
			timer.restart();
		}
	}

	for (int i = 0; i < npcList.size(); i++)
	{
		npcList[i].ProcessInput();
	}
}