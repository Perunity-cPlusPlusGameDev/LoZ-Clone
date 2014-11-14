#pragma once
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
	int speed;
	int State;
	enum DIRECTION
	{
	    UP = 0,
	    DOWN = 1,
	    LEFT = 2,
	    RIGHT = 3,
	};
	enum GAMESTATE
	{
		MAINMENU = 0,
		PLAYING = 1,
		PAUSED = 2,
	};
};



