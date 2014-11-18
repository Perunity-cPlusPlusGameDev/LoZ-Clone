#include "npcManager.h"

void NpcManager::Init()
{
	gui.Init("coolvetica");
}

void NpcManager::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < npcList.size(); i++)
	{
		sf::Vector2f pos = npcList[i].GetPos();
		gui.MakeTextbox("Hello, ****! \n How are you today? \n lol", window, pos.x + 25, pos.y - 25, 15, sf::Color(255, 255, 255), true);
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