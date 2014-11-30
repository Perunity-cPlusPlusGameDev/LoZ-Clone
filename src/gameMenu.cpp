#include "gameMenu.h"

void gameMenu::LoadMenu(sf::Texture mainMenuTexture, sf::RenderWindow &window, int x, int y){
	// Music
	gui.Init("Triforce");

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
	std::cout << "Menu loaded!\n";
}
void gameMenu::Settings()
{
	isSettingOpen = true;
	windowSetting.create(sf::VideoMode(400, 400), "Settings", sf::Style::Close);
	windowSetting.clear();
	gui.MakeTextbox("Setting", windowSetting, 1, 1, 30, sf::Color(0, 0, 0));
	windowSetting.display();
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
				isSettingOpen = false;
				break;
			default:
				//std::cout << "An event has fired which hasn't been added to the process list" << std::endl;
				break;
		}
	}
}
bool gameMenu::GetSettingStatus()
{
	return isSettingOpen;
}
