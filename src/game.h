#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <random>
#include "resourceManager.h"
#include "player.h"
#include "npc.h"
#include "gameMenu.h"
#include "map.h"
#include "npcManager.h"
#include "enemyManager.h"
namespace GAMESTATE
{
	enum
	{
		MAINMENU = 0,
		PLAYING = 1,
		PAUSED = 2,
	};
}
class Game
{
public:
	void Run();
private:
	static const int TILE_SIZE = 32;
	void Update(sf::Time _dt);
	void Draw();
	void ProcessEvents();
	void ProcessInput();
	sf::RenderWindow window;
	sf::Vector2i screenDimensions;
	ResourceManager rm;
	Player player;
	gameMenu menu;
	Map map, map1, map2, cave, field;
	int State;
	sf::Time dt;
	sf::Clock deltaClock;
	NpcManager townNpc;
	EnemyManager fieldEnemy;
	sf::Texture npcTexture1 , npcTexture2, npcTexture3;
	sf::Texture playerTexture;
	sf::Texture enemyTexture;
	bool DrawHouse = false;
	int currentMap = 0;
};
#endif