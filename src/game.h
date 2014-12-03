#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <random>
#include <unordered_map>
#include "resourceManager.h"
#include "player.h"
#include "npc.h"
#include "gameMenu.h"
#include "map.h"
#include "entityManager.h"
#include "command.h"
#include "entity.h"
namespace GAMESTATE{
	enum {
		MAINMENU = 0,
		PLAYING = 1,
		PAUSED = 2,
	};
}
namespace ENTITYTYPE {
	enum {
		PLAYER = 0,
		NPC = 1,
		MOB = 2,
		ITEM = 3
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
	sf::Time dt;
	sf::Clock deltaClock;
	sf::Clock fpsclock;
	ResourceManager rm;
	Player player;
	gameMenu menu;
	Command cmd;
	Map map, map1, map2, cave, field;
	EntityManager npcManager;
	EntityManager enemyManager;
	EntityManager itemManager;
	int State;
	bool isCmd = false;
	bool wasPressed = false;
	int currentMap = 0;
	std::unordered_map<std::string, sf::Texture> Texture;
	std::string cmdText;
};
#endif