#include "gameMenu.h"

void gameMenu::LoadMenu(const std::string& fileName, sf::RenderWindow &window, int x, int y){
	// Music
    if (!music.openFromFile(fileName)){
        return;
	}
	music.play();
	music.setLoop(true);
	std::cout << "Music Loaded\n";

	// Main menu image
	if(!mainMenuTexture.loadFromFile("Textures/800x600.jpg")){
		std::cout << "Texture file cannot be found!\n";
	}
	mainMenu.setTexture(mainMenuTexture);
	mainMenu.setPosition(0, 0);
	mainMenu.setTextureRect(sf::IntRect(0, 0, x, y));

	window.clear();
	window.draw(mainMenu);
	MakeText("Press R to start", window, x/2, y-100);
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
