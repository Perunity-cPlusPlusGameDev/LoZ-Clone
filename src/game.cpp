#include "game.h"

void Game::Run()
{
	/*Initialize*/
	State = GAMESTATE::MAINMENU;
	screenDimensions = sf::Vector2i(800, 600);
	window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Zelda Clone");
	window.setFramerateLimit(60);
	npcManager.Init();
	enemyManager.Init();
	// Resource manager
	Texture["playerTexture"] = rm.LoadTexture("mainchar.png");
	Texture["npcTexture1"] = rm.LoadTexture("npc1.png");
	Texture["npcTexture2"] = rm.LoadTexture("npc2.png");
	Texture["npcTexture3"] = rm.LoadTexture("npc3.png");
	Texture["enemyTexture"] = rm.LoadTexture("unicorn.png");
	Texture["townTexture"] = rm.LoadTexture("RPGpack_sheet.png");
	Texture["fieldTexture"] = rm.LoadTexture("hyptosis1.png");
	Texture["menuTexture"] = rm.LoadTexture("800x600.jpg");

	map.LoadMap("Maps/Map1.txt", Texture["townTexture"]); // Improve the way we handle maps
	map1.LoadMap("Maps/Map1.1.txt", Texture["townTexture"]);
	map2.LoadMap("Maps/Map1.2.txt", Texture["townTexture"]);
	cave.LoadMap("Maps/cave.txt", Texture["townTexture"]);
	field.LoadMap("Maps/Field1.txt", Texture["fieldTexture"]);
	/*End Of Initialize*/
	
	// Load Main Menu
	rm.PlayMusic("Sound/title.lite.ogg");
	menu.LoadMenu(Texture["menuTexture"], window, screenDimensions.x, screenDimensions.y);


	// Create Player
	player.Init(screenDimensions, 10, 10, Texture["playerTexture"], map.GetMapSize());

	//Create NPCs
	npcManager.CreateEntity(1, 100, 100, Texture["npcTexture1"], map.GetMapSize());
	npcManager.CreateEntity(1, 150, 100, Texture["npcTexture2"], map.GetMapSize());
	npcManager.CreateEntity(1, 200, 100, Texture["npcTexture3"], map.GetMapSize());

	// Create Enemies
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distributionx(0, field.GetMapSize().x * 32);
	std::uniform_int_distribution<int> distributiony(0, field.GetMapSize().y * 32);
	for(int i = 0; i < 10; i++)
	{
		enemyManager.CreateEntity(1, distributionx(generator), distributiony(generator), Texture["enemyTexture"], map.GetMapSize());
	}

	//  ^^ NEED TO EDIT ENTITYMANAGER FIRST

	//Main Loop
	
	while (window.isOpen())
	{
		dt = deltaClock.restart();
		if( State == GAMESTATE::PLAYING)
		{
			Update(dt);
			Draw();
			//std::cout<< "FPS: " << 1.f / fpsclock.restart().asSeconds() << std::endl;
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
	npcManager.Update(_dt);
	enemyManager.Update(_dt);
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
	npcManager.Draw(window);
	enemyManager.Draw(window);
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
			case sf::Event::TextEntered:
				if (isCmd) {
					cmdText += (char)event.text.unicode;
					std::cout << (char)event.text.unicode;
				}
				break;
			default:
			//std::cout << "An event has fired which hasn't been added to the process list" << std::endl;
			break;
		}
	}
}

void Game::ProcessInput() {
	if (!isCmd) {
		player.ProcessInput();
	}
	npcManager.ProcessInput();
	enemyManager.ProcessInput();

	if (State == GAMESTATE::MAINMENU) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && !menu.GetSettingStatus()) {
			State = GAMESTATE::PLAYING;
			std::cout << "State: Playing" << std::endl;
			rm.PlayMusic("Sound/overworld.ogg"); // testing
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
			window.close();
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !menu.GetSettingStatus()) {
			menu.Settings();
		} 
	} else if (State == GAMESTATE::PLAYING) {

		bool isPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Return);
		if (isPressed && !wasPressed) {
			isCmd = !isCmd; // lel
			if (isCmd) {
				std::cout << "Enter command: ";
			}
			cmd.atCommand(player, cmdText);
		}

		// Check if the key was held since last frame, aka KeyHeld.
		//if (isPressed && wasPressed)

		// Check if the key was released since last frame, aka KeyReleased.
		//if (!isPressed && wasPressed)

		wasPressed = isPressed;
	}
}

