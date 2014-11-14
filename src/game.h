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
	void Render();
	void ProcessEvents();
	void ProcessInput();
	sf::RenderWindow window;
	sf::Vector2i screenDimensions;
	sf::Clock timer;
	sf::Time timePerFrame;
	Player player;
	gameMenu menu;
	Map map;
	Map map1;
	Map map2;
	int speed;
	int State;
	enum DIRECTION
	{
	    UP = 0,
	    DOWN = 1,
	    LEFT = 2,
	    RIGHT = 3,
	    STOP = 4,
	};
	enum GAMESTATE
	{
		MAINMENU = 0,
		PLAYING = 1,
		PAUSED = 2,
	};
};
#endif