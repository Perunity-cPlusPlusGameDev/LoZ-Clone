#include "gameMenu.h"

void gameMenu::LoadMenu(const std::string& fileName, sf::RenderWindow &window, int x, int y){
	// Music
    if (!music.openFromFile(fileName))
    {
        std::cout << "Music file cannot be found!\n";
	}
	music.play();
	music.setLoop(true);
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
	MakeText("Press R to start", window, x/2, y-150);
	MakeText("Press S to go setting", window, x/2, y-100);
	MakeText("Press X to exit", window, x/2, y-50);
	window.display();
	std::cout << "Texture loaded!\n";
}

void gameMenu::MakeText(std::string btnName, sf::RenderWindow &window, int x, int y)
{
	sf::Vector2f fontPosition(x, y);
	sf::Font gameFont;
	if(!gameFont.loadFromFile("Fonts/Triforce.ttf")){
		std::cout << "Font file cannot be found!\n";
	}
	sf::Text gameText(btnName, gameFont, 30);
	gameText.setColor(sf::Color(255, 0, 0));
	sf::FloatRect textRect = gameText.getLocalBounds();
	gameText.setOrigin(textRect.width / 2, textRect.height / 2);
	gameText.setPosition(fontPosition);
	window.draw(gameText);
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
