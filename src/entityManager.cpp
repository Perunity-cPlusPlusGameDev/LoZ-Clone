#include "entityManager.h"

void EntityManager::Init()
{
	gui.Init("coolvetica");
}

void EntityManager::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < entityList.size(); i++)
	{
		sf::Vector2f pos = entityList[i]->GetPos();
		//gui.MakeTextbox("Hello, ****! \n How are you today? \n lol", window, pos.x + 25, pos.y - 25, 15, sf::Color(255, 255, 255), true);
		entityList[i]->Draw(window);
		//std::cout << pos.x << pos.y << std::endl;
	}
}

void EntityManager::Update(sf::Time dt)
{
	for (int i = 0; i < entityList.size(); i++)
	{
		entityList[i]->Update(dt);
	}
}

void EntityManager::CreateEntity(int entityType, int x, int y, sf::Texture& texture, sf::Vector2i mapSize)
{
	switch(entityType)
	{
		case 1:
		{
			Entity* entity;
			std::unique_ptr<Entity> ptr(entity);
			ptr->Init(sf::Vector2i(800, 600), x, y, texture, mapSize);
			entityList.push_back(ptr);
		}break;

		default:
			std::cout << "Invalid entityType specified" << std::endl;
			break;
	}


}
void EntityManager::ProcessInput()
{
	elapsedTime = timer.getElapsedTime();
	if(elapsedTime > timeLimit)
	{
		for (int i = 0; i < entityList.size(); i++)
		{
			//entityList[i].ProcessInput();
		}
		timer.restart();
	}


}