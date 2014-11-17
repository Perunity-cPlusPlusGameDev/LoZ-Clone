#include "gui.h"
Gui::Gui()
{
	if(!gameFont.loadFromFile("Fonts/Triforce.ttf")){
		std::cout << "Font file cannot be found!\n";
	}
}
void Gui::MakeText(std::string btnName, sf::RenderWindow &window, int x, int y)
{
	sf::Vector2f fontPosition(x, y);
	sf::Text gameText(btnName, gameFont, 30);
	gameText.setColor(sf::Color(255, 0, 0));
	sf::FloatRect textRect = gameText.getLocalBounds();
	gameText.setOrigin(textRect.width / 2, textRect.height / 2);
	gameText.setPosition(fontPosition);
	window.draw(gameText);
}