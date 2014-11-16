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
	player.Init(screenDimensions, 120, 450, "image");
	//npc1.Init(screenDimensions, 120, 420, "npc1");
	//npc2.Init(screenDimensions, 160, 420, "npc2");
	/*End Of Initialize*/
	player.MapSize(map.GetMapSize());// Pass x and y from map to player
	// Load Main Menu
	menu.LoadMenu("Sound/intro.ogg", window, screenDimensions.x, screenDimensions.y);

	//mock resource manager
	if(!texture.loadFromFile("Textures/npc1.png"))
		std::cout << "NPC texture file cannot be found!" << std::endl;
	if(!texture2.loadFromFile("Textures/npc2.png"))
		std::cout << "NPC texture file cannot be found!" << std::endl;

	//create npc
	npcManager.CreateNPC(120, 420, texture);
	npcManager.CreateNPC(154, 420, texture);
	npcManager.CreateNPC(188, 420, texture2);


	//Main Loop
	while (window.isOpen())
	{
		if( State == GAMESTATE::PLAYING)
		{
			dt = deltaClock.restart();
			Update(dt);
			Draw();
		}
		ProcessEvents();
		ProcessInput();
	}
}

void Game::Update(sf::Time _dt)
{
	npcManager.Update();
	//npc1.Update();
	//npc2.Update();
	player.Update(_dt);
}

void Game::Draw()
{
	window.clear();

	map.Draw(window);
	npcManager.Draw(window);
	//npc2.Draw(window);
	//npc1.Draw(window);
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
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (State == GAMESTATE::MAINMENU))
	{
		menu.Settings();
	}

}

