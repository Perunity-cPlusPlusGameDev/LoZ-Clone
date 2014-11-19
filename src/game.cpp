#include "game.h"

void Game::Run()
{
	/*Initialize*/
	State = GAMESTATE::MAINMENU;
	screenDimensions = sf::Vector2i(800, 600);
	window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Zelda Clone");

	townNpc.Init();
	fieldEnemy.Init();

	map.LoadMap("Maps/Map1.txt", "RPGpack_sheet"); // Improve the way we handle maps
	map1.LoadMap("Maps/Map1.1.txt", "RPGpack_sheet");
	map2.LoadMap("Maps/Map1.2.txt", "RPGpack_sheet");
	cave.LoadMap("Maps/cave.txt", "RPGpack_sheet");
	field.LoadMap("Maps/Field1.txt", "hyptosis1");
	/*End Of Initialize*/

	// Load Main Menu
	menu.LoadMenu("Sound/intro.ogg", window, screenDimensions.x, screenDimensions.y);

	//mock resource manager
	if(!playerTexture.loadFromFile("Textures/mainchar.png"))
		std::cout << "Player texture file cannot be found!" << std::endl;
	if(!npcTexture1.loadFromFile("Textures/npc1.png"))
		std::cout << "NPC texture file cannot be found!" << std::endl;
	if(!npcTexture2.loadFromFile("Textures/npc2.png"))
		std::cout << "NPC texture file cannot be found!" << std::endl;
	if(!npcTexture3.loadFromFile("Textures/npc3.png"))
		std::cout << "NPC texture file cannot be found!" << std::endl;
	if(!enemyTexture.loadFromFile("Textures/unicorn.png"))
		std::cout << "Enemy texture file cannot be found!" << std::endl;

	player.Init(screenDimensions, 124, 450, playerTexture, map.GetMapSize());

	//create npc
	townNpc.CreateNPC(120, 480, npcTexture1, map.GetMapSize());
	townNpc.CreateNPC(154, 480, npcTexture2, map.GetMapSize());
	townNpc.CreateNPC(188, 480, npcTexture3, map.GetMapSize());

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distributionx(0, field.GetMapSize().x * 32);
	std::uniform_int_distribution<int> distributiony(0, field.GetMapSize().y * 32);
	for(int i = 0; i < 100; i++)
	{
		fieldEnemy.CreateEnemy(distributionx(generator), distributiony(generator), enemyTexture, field.GetMapSize());
	}

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
	player.Update(_dt, currentMap);
	map.SetCurrentMap(currentMap);

	switch(map.GetCurrentMap())
	{
		case 0:
			townNpc.Update(_dt);
			break;
		case 1:
			fieldEnemy.Update(_dt);
			break;
	}
}

void Game::Draw()
{
	window.clear();
	switch(map.GetCurrentMap())
	{
		case 0:
			map.Draw(window);
			cave.Draw(window);
			if(DrawHouse)
			{
				map1.Draw(window);
				map2.Draw(window);
			}
			townNpc.Draw(window);
			break;
		case 1:

			field.Draw(window);
			cave.Draw(window);
			fieldEnemy.Draw(window);
			break;
	}
	player.Draw(window);
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


	switch(map.GetCurrentMap())
	{
		case 0:
			townNpc.ProcessInput();
			break;
		case 1:
			fieldEnemy.ProcessInput();
			break;
	}
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

