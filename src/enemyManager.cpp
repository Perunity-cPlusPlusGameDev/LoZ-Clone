#include "enemyManager.h"

void EnemyManager::Init()
{
	//gui.Init("coolvetica");
}

void EnemyManager::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < enemyList.size(); i++)
	{
		//sf::Vector2f pos = enemyList[i].GetPos();
		//gui.MakeTextbox("Hello, ****! \n How are you today? \n lol", window, pos.x + 25, pos.y - 25, 15, sf::Color(255, 255, 255), true);
		enemyList[i].Draw(window);
	}
}

void EnemyManager::Update(sf::Time dt)
{
	for (int i = 0; i < enemyList.size(); i++)
	{
		enemyList[i].Update(dt);
	}
}

void EnemyManager::CreateEnemy(int x, int y, sf::Texture& texture, sf::Vector2i mapSize)
{
	Enemy enemy;
	enemy.Init(sf::Vector2i(800, 600), x, y, texture, mapSize);
	enemyList.push_back(enemy);
}
void EnemyManager::ProcessInput()
{
	elapsedTime = timer.getElapsedTime();
	if(elapsedTime > timeLimit)
	{
		for (int i = 0; i < enemyList.size(); i++)
		{
			enemyList[i].i = std::rand() % 4;
			timer.restart();
		}
	}

	for (int i = 0; i < enemyList.size(); i++)
	{
		enemyList[i].ProcessInput();
	}
}