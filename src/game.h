#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "player.h"
#include "gameMenu.h"
#include "map.h"

class Game
{
public:
	void Run();
private:
	static const int TILE_SIZE = 32;
	void Update();
	void Draw();
	void ProcessEvents();
	void ProcessInput();
	sf::RenderWindow window;
	sf::Vector2i screenDimensions;
	Player player;
	gameMenu menu;
	Map map;
	Map map1;
	Map map2;
	int State;
	enum GAMESTATE
	{
		MAINMENU = 0,
		PLAYING = 1,
		PAUSED = 2,
	};
};
#endif