#include "game.h"

void Game::Run()
{
	/*Initialize*/
	State = GAMESTATE::MAINMENU;
	screenDimensions = sf::Vector2i(800, 600);
	window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Zelda Clone");

	map.LoadMap("Maps/Map1.txt"); // Improve the way we handle maps
	map1.LoadMap("Maps/Map1.1.txt");
	map2.LoadMap("Maps/Map1.2.txt");
	player.Init(screenDimensions);
	/*End Of Initialize*/
	player.MapSize(map.GetMapSize());// Pass x and y from map to player
	// Load Main Menu
	menu.LoadMenu("Sound/intro.ogg", window, screenDimensions.x, screenDimensions.y);

	//Main Loop
	while (window.isOpen())
	{
		if( State == GAMESTATE::PLAYING)
		{
			Update();
			Draw();
		}
		ProcessEvents();
		ProcessInput();
	}
}

void Game::Update()
{
	player.Update();
}

void Game::Draw()
{
	window.clear();

	map.Draw(window);
	player.Draw(window);
	map1.Draw(window);
	map2.Draw(window);
	window.display();
}

void Game::ProcessEvents()
{
	sf::Event event;
	while(window.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
			window.close();
			break;
			case sf::Event::LostFocus:
			if(State == GAMESTATE::PLAYING)
				State = GAMESTATE::PAUSED;
			break;
			case sf::Event::GainedFocus:
			if(State == GAMESTATE::PAUSED)
				State = GAMESTATE::PLAYING;
			break;


			default:
			//std::cout << "An event has fired which hasn't been added to the process list" << std::endl;
			break;
		}
	}
}

void Game::ProcessInput()
{
	player.ProcessInput();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && (State != GAMESTATE::PLAYING))
	{
		State = GAMESTATE::PLAYING;
		std::cout << "State: Playing" << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && (State != GAMESTATE::PLAYING))
	{
		window.close();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (State != GAMESTATE::PLAYING))
	{
		menu.Settings();
	}

}

