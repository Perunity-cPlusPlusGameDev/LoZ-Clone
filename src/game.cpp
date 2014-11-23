#include "game.h"

void Game::Run()
{
	/*Initialize*/
	State = GAMESTATE::MAINMENU;
	screenDimensions = sf::Vector2i(800, 600);
	window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Zelda Clone");
	window.setFramerateLimit(60);
	entityManager.Init();
	// Resource manager
	playerTexture = rm.LoadTexture("mainchar");
	npcTexture1 = rm.LoadTexture("npc1");
	npcTexture2 = rm.LoadTexture("npc2");
	npcTexture3 = rm.LoadTexture("npc3");
	enemyTexture = rm.LoadTexture("unicorn");
	townTexture = rm.LoadTexture("RPGpack_sheet");
	fieldTexture = rm.LoadTexture("hyptosis1");

	map.LoadMap("Maps/Map1.txt", townTexture); // Improve the way we handle maps
	map1.LoadMap("Maps/Map1.1.txt", townTexture);
	map2.LoadMap("Maps/Map1.2.txt", townTexture);
	cave.LoadMap("Maps/cave.txt", townTexture);
	field.LoadMap("Maps/Field1.txt", fieldTexture);
	/*End Of Initialize*/

	// Load Main Menu
	menu.LoadMenu("Sound/intro.ogg", window, screenDimensions.x, screenDimensions.y);


	// Create Player
	player.Init(screenDimensions, 10, 10, playerTexture, map.GetMapSize());

	//Create NPCs
	entityManager.CreateEntity(1, 100, 100, npcTexture1, map.GetMapSize());
	entityManager.CreateEntity(1, 150, 100, npcTexture2, map.GetMapSize());
	entityManager.CreateEntity(1, 200, 100, npcTexture3, map.GetMapSize());

	// Create Enemies
	//std::default_random_engine generator;
	//std::uniform_int_distribution<int> distributionx(0, field.GetMapSize().x * 32);
	//std::uniform_int_distribution<int> distributiony(0, field.GetMapSize().y * 32);
	//for(int i = 0; i < 100; i++)
	//{
		//fieldEnemy.CreateEnemy(distributionx(generator), distributiony(generator), enemyTexture, field.GetMapSize());
	//}

	//  ^^ NEED TO EDIT ENTITYMANAGER FIRST

	//Main Loop
	while (window.isOpen())
	{
		dt = deltaClock.restart();
		if( State == GAMESTATE::PLAYING)
		{
			Update(dt);
			Draw();
			std::cout<< "FPS: " << 1.f / fpsclock.restart().asSeconds() << std::endl;
		}
		menu.ProcessEvents();
		ProcessEvents();
		ProcessInput();
	}
}

void Game::Update(sf::Time _dt)
{
	player.Update(_dt);
	map.SetCurrentMap(currentMap);
	entityManager.Update(_dt);
}

void Game::Draw()
{
	window.clear();
	map.Draw(window);
	//cave.Draw(window);
	//map1.Draw(window);
	//map2.Draw(window);
	//field.Draw(window);
	//cave.Draw(window);
	player.Draw(window);
	entityManager.Draw(window);
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
	entityManager.ProcessInput();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && (State == GAMESTATE::MAINMENU) && !menu.GetSettingStatus() )
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
}

