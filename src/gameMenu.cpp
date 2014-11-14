#include "gameMenu.h"

void gameMenu::loadMenu(const std::string& fileName, sf::RenderWindow &window, int x, int y){
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
	window.display();
	std::cout << "Texture loaded!\n";

}