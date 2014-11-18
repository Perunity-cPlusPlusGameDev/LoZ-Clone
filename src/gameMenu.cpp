#include "gameMenu.h"

void gameMenu::LoadMenu(const std::string& fileName, sf::RenderWindow &window, int x, int y){
	// Music
	gui.Init("Triforce");
    if (!music.openFromFile(fileName))
    {
        std::cout << "Music file cannot be found!\n";
	}
	music.play();
	music.setLoop(true);
	music.setVolume(0.5f);
	std::cout << "Music Loaded\n";

	// Main menu image
	if(!mainMenuTexture.loadFromFile("Textures/800x600.jpg"))
	{
		std::cout << "Texture file cannot be found!\n";
	}
	mainMenu.setTexture(mainMenuTexture);
	mainMenu.setPosition(0, 0);
	mainMenu.setTextureRect(sf::IntRect(0, 0, x, y));

	window.clear();
	window.draw(mainMenu);
	sf::Color color = sf::Color(0, 0, 0);
	gui.MakeTextbox("Visit \"bit.ly/LoZ-Clone\" to checkout our source code",window, x/2, y/4, 30, color);
	gui.MakeTextbox("Press R to start", window, x/2, y-150, 30, color);
	gui.MakeTextbox("Press S to go setting", window, x/2, y-100, 30, color);
	gui.MakeTextbox("Press X to exit", window, x/2, y-50, 30, color);
	window.display();
	std::cout << "Texture loaded!\n";
}
void gameMenu::Settings()
{
	windowSetting.create(sf::VideoMode(400, 400), "Settings", sf::Style::Close);
}
void gameMenu::ProcessEvents()
{
	sf::Event event;
	while(windowSetting.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
			windowSetting.close();
			break;
			default:
			//std::cout << "An event has fired which hasn't been added to the process list" << std::endl;
			break;
		}
	}
}
