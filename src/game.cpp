#include "game.h"

void Game::Run()
{
	/*Initialize*/
	State = GAMESTATE::MAINMENU;
	screenDimensions = sf::Vector2i(800, 600);
	window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Zelda Clone");

	npcManager.Init();

	map.LoadMap("Maps/Map1.txt"); // Improve the way we handle maps
	map1.LoadMap("Maps/Map1.1.txt");
	map2.LoadMap("Maps/Map1.2.txt");

	/*End Of Initialize*/

	// Load Main Menu
	menu.LoadMenu("Sound/intro.ogg", window, screenDimensions.x, screenDimensions.y);

	//mock resource manager
	if(!texture.loadFromFile("Textures/npc1.png"))
		std::cout << "NPC texture file cannot be found!" << std::endl;
	if(!texture2.loadFromFile("Textures/npc2.png"))
		std::cout << "NPC texture file cannot be found!" << std::endl;
	if(!playerTexture.loadFromFile("Textures/image.png"))
		std::cout << "Player texture file cannot be found!" << std::endl;

	player.Init(screenDimensions, 124, 450, playerTexture, map.GetMapSize(), false);

	//create npc
	npcManager.CreateNPC(120, 480, texture, map.GetMapSize(), true);
	npcManager.CreateNPC(154, 480, texture, map.GetMapSize(), true);
	npcManager.CreateNPC(188, 480, texture2, map.GetMapSize(), true);


	//Main Loop
	while (window.isOpen())
	{
		dt = deltaClock.restart();
		if( State == GAMESTATE::PLAYING)
		{
			Update(dt);
			Draw();
		}
		menu.ProcessEvents();
		ProcessEvents();
		ProcessInput();
	}
}

void Game::Update(sf::Time _dt)
{
	npcManager.Update(_dt);
	player.Update(_dt);
}

void Game::Draw()
{
	window.clear();

	map.Draw(window);
	npcManager.Draw(window);
	player.Draw(window);
	if(DrawHouse)
	{
		map1.Draw(window);
		map2.Draw(window);
	}
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
	npcManager.ProcessInput();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && (State == GAMESTATE::MAINMENU))
	{
		State = GAMESTATE::PLAYING;
		std::cout << "State: Playing" << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && (State == GAMESTATE::MAINMENU))
	{
		window.close();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (State == GAMESTATE::MAINMENU))
	{
		menu.Settings();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::H) && (State == GAMESTATE::PLAYING))
	{
		if(DrawHouse)
		{
			DrawHouse = false;
		}
		else
		{
			DrawHouse = true;
		}
	}

}

