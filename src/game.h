#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "player.h"
#include "npc.h"
#include "gameMenu.h"
#include "map.h"
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
	Player player;
	Npc npc1;
	Npc npc2;
	gameMenu menu;
	Map map;
	Map map1;
	Map map2;
	int State;
	sf::Time dt;
	sf::Clock deltaClock;
};
#endif