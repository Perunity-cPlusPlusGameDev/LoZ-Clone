#include "entityManager.h"

void EntityManager::Init()
{
	gui.Init("coolvetica");
}

void EntityManager::Draw(sf::RenderWindow& window)
{
	for (auto & e : entityList)
	{
		sf::Vector2f pos = e->GetPos();
		//gui.MakeTextbox("Hello, ****! \n How are you today? \n lol", window, pos.x + 25, pos.y - 25, 15, sf::Color(255, 255, 255), true);
		e->Draw(window);
	}
}

void EntityManager::Update(sf::Time dt)
{
	for (auto & e : entityList) {
	    e->Update(dt);
	}
}

void EntityManager::CreateEntity(int entityType, int x, int y, sf::Texture& texture, sf::Vector2i mapSize)
{
	switch(entityType)
	{
		case 1:
		case 3:
		{
			std::shared_ptr<Npc> ptr(new Npc);
			ptr->Init(sf::Vector2i(800, 600), x, y, texture, mapSize, entityType);
			entityList.push_back(ptr);
		}break;

		default:
			std::cout << "Invalid entityType specified" << std::endl;
			break;
	}
}

void EntityManager::ProcessInput()
{
	srand(time(NULL));
	elapsedTime = timer.getElapsedTime();
	if(elapsedTime > timeLimit)
	{
		entityList[std::rand() % entityList.size()]->ProcessInput();
		timer.restart();
	}
}